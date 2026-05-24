#include "NewAudioCaptureComponent.h"


UNewAudioCaptureComponent::UNewAudioCaptureComponent(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    PrimaryComponentTick.bCanEverTick = true;
    PrimaryComponentTick.bStartWithTickEnabled = true;
    PrimaryComponentTick.TickGroup = TG_PrePhysics;
}

void UNewAudioCaptureComponent::OnRegister()
{
    Super::OnRegister();
    // ✅ OnRegister 时 Audio 系统已就绪，在这里安全创建
    if (!CaptureSynth)
    {
        CaptureSynth = new Audio::FAudioCaptureSynth();
    }

    PrimaryComponentTick.bCanEverTick = true;
    SetComponentTickEnabled(true);
}

void UNewAudioCaptureComponent::BeginPlay()
{
    Super::BeginPlay();
    SetComponentTickEnabled(true);

    UE_LOG(LogTemp, Warning,
        TEXT("AudioCapture BeginPlay: Registered=%d, TickEnabled=%d, CanEverTick=%d, Owner=%s"),
        IsRegistered(), IsComponentTickEnabled(), PrimaryComponentTick.bCanEverTick,
        GetOwner() ? *GetOwner()->GetName() : TEXT("null"));
}
bool UNewAudioCaptureComponent::Init(int32& SampleRate)
{
    Audio::FCaptureDeviceInfo DeviceInfo;
    if (!CaptureSynth->GetDefaultCaptureDeviceInfo(DeviceInfo))
        return false;

    if (DeviceInfo.PreferredSampleRate > 0)
    {
        SampleRate = DeviceInfo.PreferredSampleRate;
    }
    else
    {
        UE_LOG(LogAudio, Warning, TEXT("Invalid SampleRate from device: %d"),
            DeviceInfo.PreferredSampleRate);
        return false;
    }

    NumChannels = DeviceInfo.InputChannels;
    G_SampleRate = SampleRate;

    if (NumChannels <= 0 || NumChannels > 8)
    {
        UE_LOG(LogAudio, Warning, TEXT("Invalid NumChannels: %d"), NumChannels);
        return false;
    }

    bIsStreamOpen = CaptureSynth->OpenDefaultStream();
    UE_LOG(LogAudio, Warning, TEXT("AudioCapture init: NumChannels=%d, SampleRate=%d"),
        NumChannels, SampleRate);

    return bIsStreamOpen;
}

void UNewAudioCaptureComponent::OnBeginGenerate()
{
    ScratchInterleaved.Reset();
    ScratchMono.Reset();
    ReadyBuffer16k.Reset();
    ResamplePhase = 0.0;

    {
        FScopeLock L(&SendQueueCS);
        PendingSendQueue.Reset();
    }

    if (!bIsStreamOpen)
        bIsStreamOpen = CaptureSynth->OpenDefaultStream();

    if (bIsStreamOpen)
    {
        CaptureSynth->StartCapturing();
        check(CaptureSynth->IsCapturing());
        bIsNotReadyForForFinishDestroy = true;
    }
}

void UNewAudioCaptureComponent::OnEndGenerate()
{
    if (bIsStreamOpen)
    {
        check(CaptureSynth->IsStreamOpen());
        CaptureSynth->StopCapturing();
        bIsStreamOpen = false;
        bIsNotReadyForForFinishDestroy = false;
    }
}

void UNewAudioCaptureComponent::BeginDestroy()
{
    Super::BeginDestroy();
    bIsDestroying = true;
    Stop();
}

bool UNewAudioCaptureComponent::IsReadyForFinishDestroy()
{
    return !bIsNotReadyForForFinishDestroy;
}

void UNewAudioCaptureComponent::FinishDestroy()
{
    if (CaptureSynth)
    {
        if (CaptureSynth->IsStreamOpen())
            CaptureSynth->AbortCapturing();

        delete CaptureSynth;
        CaptureSynth = nullptr;
    }

    Super::FinishDestroy();
    bIsStreamOpen = false;
    bIsDestroying = false;
}
// ===================================================================
// 音频线程：拉数据 -> 下混 -> 重采样到 16k -> 按 OnceSendFloatDataNum 切块 -> 入队
// ===================================================================
int32 UNewAudioCaptureComponent::OnGenerateAudio(float* OutAudio, int32 NumSamples)
{
    // 输出给扬声器的部分恒静音 —— 我们只借用 SynthComponent 的音频线程驱动
    FMemory::Memzero(OutAudio, NumSamples * sizeof(float));

    if (!bIsStreamOpen || !CaptureSynth->IsStreamOpen() || !CaptureSynth->IsCapturing())
        return NumSamples;

    if (NumChannels <= 0 || G_SampleRate <= 0 || OnceSendFloatDataNum <= 0 || TargetSampleRate <= 0)
        return NumSamples;

    // 1) 从 CaptureSynth 拉原始交错样本
    if (CaptureSynth->GetNumSamplesEnqueued() > 0)
    {
        ScratchInterleaved.Reset();
        CaptureSynth->GetAudioData(ScratchInterleaved);
    }

    // 2) 下混到单声道（取均值；性能敏感可以改成取第 0 通道）
    if (ScratchInterleaved.Num() >= NumChannels)
    {
        const int32 Frames = ScratchInterleaved.Num() / NumChannels;
        const int32 OldNum = ScratchMono.Num();
        ScratchMono.AddUninitialized(Frames);
        float* Dst = ScratchMono.GetData() + OldNum;
        const float* Src = ScratchInterleaved.GetData();
        const float InvCh = 1.0f / (float)NumChannels;
        for (int32 f = 0; f < Frames; ++f)
        {
            float Sum = 0.f;
            for (int32 c = 0; c < NumChannels; ++c)
                Sum += Src[f * NumChannels + c];
            Dst[f] = Sum * InvCh;
        }
    }

    // 3) 重采样 G_SampleRate -> TargetSampleRate（线性插值，相位跨块连续）
    if (ScratchMono.Num() >= 2)
    {
        const double Step = (double)G_SampleRate / (double)TargetSampleRate;
        const int32  SrcN = ScratchMono.Num();

        // 从 ResamplePhase 开始往后取，直到位置 + 1 越过 SrcN - 1
        TArray<float> Out16k;
        Out16k.Reserve((int32)((double)SrcN / Step) + 2);

        double Pos = ResamplePhase;
        while (true)
        {
            const int32 i0 = (int32)Pos;
            const int32 i1 = i0 + 1;
            if (i1 >= SrcN) break;
            const double a = Pos - (double)i0;
            const float v = (float)((1.0 - a) * ScratchMono[i0] + a * ScratchMono[i1]);
            Out16k.Add(v);
            Pos += Step;
        }

        // 保留尚未用完的尾巴一个样本，新的相位是相对于「保留点」的偏移
        const int32 LastConsumed = FMath::Clamp((int32)Pos, 0, SrcN - 1);
        ResamplePhase = Pos - (double)LastConsumed;
        if (LastConsumed > 0)
            ScratchMono.RemoveAt(0, LastConsumed, false);

        if (Out16k.Num() > 0)
            ReadyBuffer16k.Append(MoveTemp(Out16k));
    }

    // 4) 切块：每凑齐 OnceSendFloatDataNum 个就切一块进队列
    if (ReadyBuffer16k.Num() >= OnceSendFloatDataNum)
    {
        FScopeLock L(&SendQueueCS);

        while (ReadyBuffer16k.Num() >= OnceSendFloatDataNum)
        {
            TArray<float> Chunk;
            Chunk.SetNumUninitialized(OnceSendFloatDataNum);
            FMemory::Memcpy(Chunk.GetData(),
                ReadyBuffer16k.GetData(),
                OnceSendFloatDataNum * sizeof(float));
            ReadyBuffer16k.RemoveAt(0, OnceSendFloatDataNum, false);
            PendingSendQueue.Add(MoveTemp(Chunk));
        }

        // 防雪崩：队列堆积太多说明 game thread 跟不上，丢老的保新的
        const int32 MaxQueued = 200;     // 200 * 20ms = 4s 上限
        if (PendingSendQueue.Num() > MaxQueued)
        {
            const int32 ToDrop = PendingSendQueue.Num() - MaxQueued;
            PendingSendQueue.RemoveAt(0, ToDrop, false);
            UE_LOG(LogTemp, Warning, TEXT("AudioCapture: dropped %d stale chunks"), ToDrop);
        }
    }

    return NumSamples;
}

// ===================================================================
// Game Thread：把队列里所有块按顺序广播出去
// 蓝图 DynamicMulticastDelegate 必须在 game thread 调用
// ===================================================================
void UNewAudioCaptureComponent::TickComponent(float DeltaTime,
    ELevelTick TickType,
    FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (!bBroadcastEnabled)
        return;

    // 把待发队列整体搬出来再广播，缩短临界区
    TArray<TArray<float>> Local;
    {
        FScopeLock L(&SendQueueCS);
        if (PendingSendQueue.Num() == 0) return;
        Local = MoveTemp(PendingSendQueue);
        PendingSendQueue.Reset();
    }
    //UE_LOG(LogTemp, Warning, TEXT("Local:%d"), Local.Num());
    for (TArray<float>& Chunk : Local)
    {
        if (bUseFloat)
        {
            if (OnAudioOutFloat.IsBound())
                OnAudioOutFloat.Broadcast(Chunk);
        }
        else
        {
            // float -> int16 little-endian bytes
            TArray<uint8> Bytes;
            Bytes.SetNumUninitialized(Chunk.Num() * 2);
            int16* Dst = reinterpret_cast<int16*>(Bytes.GetData());
            for (int32 i = 0; i < Chunk.Num(); ++i)
            {
                float s = FMath::Clamp(Chunk[i], -1.f, 1.f) * 32767.f;
                Dst[i] = (int16)FMath::RoundToInt(s);
            }
            if (OnAudioOut.IsBound())
                OnAudioOut.Broadcast(Bytes);
        }
    }
}