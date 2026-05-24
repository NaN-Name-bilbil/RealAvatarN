// DigHumanSubsystem.cpp
#include "DigHumanSubsystem.h"
#include "Async/Async.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"
#include "HAL/PlatformFileManager.h"
#include "HAL/PlatformProcess.h"
#include "IImageWrapper.h"
#include "IImageWrapperModule.h"
#include <Kismet/GameplayStatics.h>


FReadImageRunnable* FReadImageRunnable::ReadInstance = nullptr;

// ============================================================
//  音频转换辅助
//  优化：写入调用方提供的预分配 buffer，消除每帧 heap alloc
// ============================================================
static void ConvertFloat32ToInt16Bytes(
    const float* InData,
    int32         Count,
    TArray<uint8>& OutBuffer)   // 复用调用方 buffer
{
    OutBuffer.SetNumUninitialized(Count * 2, false);
    int16* Dst = reinterpret_cast<int16*>(OutBuffer.GetData());
    for (int32 i = 0; i < Count; ++i)
    {
        // Clamp + 直接 cast，省去 FMath::RoundToInt 分支
        float s = FMath::Clamp(InData[i], -1.0f, 1.0f) * 32767.0f;
        Dst[i] = static_cast<int16>(s);
    }
}


// ============================================================
//  USubsystem 生命周期
// ============================================================
void UDigHumanSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);

    DHEngine = CreateDigitalHumanEngine(OnDHLog);
    if (!DHEngine)
        UE_LOG(LogDigitalHuman, Error, TEXT("Failed to Create Digital Human Engine from DLL!"));

    ProceduralSoundWave = NewObject<USoundWaveProcedural>();
    ProceduralSoundWave->AddToRoot();
    ProceduralSoundWave->SetSampleRate(16000);
    ProceduralSoundWave->NumChannels = 1;
    ProceduralSoundWave->bCanProcessAsync = true;
    ProceduralSoundWave->Duration = INDEFINITELY_LOOPING_DURATION;
    ProceduralSoundWave->SoundGroup = SOUNDGROUP_Voice;
    ProceduralSoundWave->bLooping = false;

    // 事件驱动：FResRunnable 等待此事件，PushAudioSamples 时触发
    //ResultReadyEvent = FPlatformProcess::GetSynchEventFromPool(false /*manual reset*/);

    UE_LOG(LogDigitalHuman, Log, TEXT("UDigHumanSubsystem: Initialized"));
}

void UDigHumanSubsystem::Deinitialize()
{
    bRunning = false;

    // 先触发事件，唤醒可能正在等待的 FResRunnable，让它能正常退出
    if (ResultReadyEvent)
        ResultReadyEvent->Trigger();

    StopWavStreamTest();

    if (ResThread)
    {
        ResThread->Shutdown();
        ResThread = nullptr;
    }
    if (ReadThread)
    {
        ReadThread->Shutdown();
        ReadThread = nullptr;
    }

    if (OutputTexture)
    {
        OutputTexture->RemoveFromRoot();
        OutputTexture = nullptr;
    }

    if (GAudioComponent) GAudioComponent->Stop();
    if (ProceduralSoundWave)
    {
        ProceduralSoundWave->RemoveFromRoot();
        ProceduralSoundWave = nullptr;
    }

    if (DHEngine)
    {
        DestroyDigitalHumanEngine(DHEngine);
        DHEngine = nullptr;
    }

    if (OutPCMFileHandle)
    {
        delete OutPCMFileHandle;
        OutPCMFileHandle = nullptr;
    }
    if (InPCMFileHandle)
    {
        delete InPCMFileHandle;
        InPCMFileHandle = nullptr;
    }

    // 归还事件到池
    if (ResultReadyEvent)
    {
        FPlatformProcess::ReturnSynchEventToPool(ResultReadyEvent);
        ResultReadyEvent = nullptr;
    }

    Super::Deinitialize();
}


// ============================================================
//  InitSystemModel / InitCustomModel
// ============================================================
bool UDigHumanSubsystem::InitSystemModel(
    const FString& licenseKey, int32 BatchSize, UAudioComponent* AudioComponent)
{
    FString pluginsdir = FPaths::Combine(FPaths::ProjectPluginsDir(), TEXT("RealAvatarN/Model"));
    Use_fp16 = true;
    InferenceBatchSize = BatchSize;
    Plugindir = pluginsdir;

    if (AudioComponent)
    {
        GAudioComponent = AudioComponent;
        GAudioComponent->SetSound(ProceduralSoundWave);
        GAudioComponent->bAutoDestroy = false;
        GAudioComponent->Play();
    }

    return InitCustomModel(licenseKey, pluginsdir);
}

bool UDigHumanSubsystem::InitCustomModel(const FString& licenseKey, const FString& MaskDir)
{
    if (!DHEngine) return false;

    Async(EAsyncExecution::Thread, [this, licenseKey, MaskDir]()
        {
            bool bOk = DHEngine->InitModels(
                TCHAR_TO_UTF8(*licenseKey),
                TCHAR_TO_UTF8(*MaskDir),
                Use_TensorRT, Use_fp16, InferenceBatchSize);

            AsyncTask(ENamedThreads::GameThread, [this, bOk]()
                {
                    if (OnModelLoaded.IsBound()) OnModelLoaded.Broadcast(bOk);
                });
        });
    return true;
}


// ============================================================
//  StartRealtimeDrive
// ============================================================
bool UDigHumanSubsystem::StartRealtimeDrive(
    const FString& IdleVideoPath, const FString& TalkVideoPath, UImage* Avatar_Image)
{
    GAvatar_Image = Avatar_Image;
    if (!DHEngine) return false;

    if (ReadThread)
    {
        ReadThread->Shutdown();
        ReadThread = nullptr;
    }
    ReadThread = FReadImageRunnable::InitReadRunnable(
        this, TEXT(""), IdleVideoPath, TalkVideoPath, TEXT(""), TEXT(""), 1);
    if (!ReadThread)
    {
        UE_LOG(LogDigitalHuman, Error, TEXT("StartRealtimeDrive: Failed to create FReadRunnable"));
        return false;
    }

    if (ResThread)
    {
        ResThread->Shutdown();
        ResThread = nullptr;
    }
    ResThread = FResRunnable::Create(this);
    if (!ResThread)
    {
        UE_LOG(LogDigitalHuman, Error, TEXT("StartRealtimeDrive: Failed to create FResRunnable"));
        return false;
    }

    return true;
}


// ============================================================
//  StartWavStream
// ============================================================
bool UDigHumanSubsystem::StartWavStream(
    const FString& WavPath,
    int32          ChunkSamples,
    int32          IntervalMs)
{
    if (!DHEngine)
    {
        UE_LOG(LogDigitalHuman, Error,
            TEXT("StartWavStream: DHEngine is null, call InitSystemModel first"));
        return false;
    }

    StopWavStreamTest();

    WavPushThread = FWavPushRunnable::Create(
        this, WavPath,
        FMath::Clamp(ChunkSamples, 1, 4096),
        FMath::Clamp(IntervalMs, 1, 1000));

    if (!WavPushThread)
    {
        UE_LOG(LogDigitalHuman, Error, TEXT("StartWavStream: Failed to create WavPushRunnable"));
        return false;
    }

    UE_LOG(LogDigitalHuman, Log,
        TEXT("StartWavStream: WAV=%s  Chunk=%d samples  Interval=%d ms"),
        *WavPath, ChunkSamples, IntervalMs);
    return true;
}

void UDigHumanSubsystem::StopWavStreamTest()
{
    if (WavPushThread)
    {
        WavPushThread->Shutdown();
        WavPushThread = nullptr;
        UE_LOG(LogDigitalHuman, Log, TEXT("StopWavStreamTest: WavPushRunnable stopped"));
    }
}


// ============================================================
//  PushAudioSamples
//  优化：推送后触发 ResultReadyEvent，唤醒 FResRunnable
// ============================================================
void UDigHumanSubsystem::PushAudioSamples(const TArray<float>& InPCM)
{
    if (!DHEngine || InPCM.Num() <= 0) return;


    DHEngine->PushAudioSamples(InPCM.GetData(), InPCM.Num());


    if (debug)
    {
        // 复用 AudioConvertBuffer（仅 debug 路径，不影响正常帧）
        ConvertFloat32ToInt16Bytes(InPCM.GetData(), InPCM.Num(), AudioConvertBuffer);

        if (!bRecordFileOpened)
        {
            FString SavePath = FPaths::ProjectSavedDir() + TEXT("debug_in_audio.pcm");
            InPCMFileHandle = FPlatformFileManager::Get()
                .GetPlatformFile().OpenWrite(*SavePath, false);
            bRecordFileOpened = true;
        }
        if (InPCMFileHandle)
            InPCMFileHandle->Write(AudioConvertBuffer.GetData(), AudioConvertBuffer.Num());
    }
}

void UDigHumanSubsystem::TickRealtime()
{
    if (DHEngine) DHEngine->TickRealtime();
}

bool UDigHumanSubsystem::IsReady() const
{
    return DHEngine ? DHEngine->IsReady() && bRunning : false;
}


// ============================================================
//  generateaudio
//  优化：复用 AudioConvertBuffer，消除每帧 heap alloc
// ============================================================
void UDigHumanSubsystem::generateaudio(const DHInferenceResult& Result)
{
    if (!Result.AudioPCMData || Result.AudioSamplesCount <= 0
        || !ProceduralSoundWave || !GAudioComponent) return;

    // 复用 member buffer，SetNumUninitialized 在容量足够时不重新分配
    ConvertFloat32ToInt16Bytes(
        Result.AudioPCMData, Result.AudioSamplesCount, AudioConvertBuffer);

    ProceduralSoundWave->QueueAudio(
        AudioConvertBuffer.GetData(), AudioConvertBuffer.Num());

    if (debug)
    {
        if (!bOutFileOpened)
        {
            FString SavePath = FPaths::ProjectSavedDir() + TEXT("debug_out_audio.pcm");
            OutPCMFileHandle = FPlatformFileManager::Get()
                .GetPlatformFile().OpenWrite(*SavePath, false);
            bOutFileOpened = true;
        }
        if (OutPCMFileHandle)
            OutPCMFileHandle->Write(AudioConvertBuffer.GetData(), AudioConvertBuffer.Num());
    }
}


// ============================================================
//  ThreadTick — 后台线程消费推理结果（FResRunnable 调用）
//
//  优化：
//    · generateaudio 转到 GameThread（USoundWaveProcedural 非线程安全）
//    · UpdateTexture 内部用 ENQUEUE_RENDER_COMMAND，可在任意线程调用
//    · FreeResult 继续在后台线程，不阻塞 GameThread
// ============================================================
void UDigHumanSubsystem::ThreadTick()
{
    if (!DHEngine) return;

    DHInferenceResult Result;
    if (!DHEngine->PopResult(Result)) return;

    double TotalStart = FPlatformTime::Seconds();

    // ── 音频：GameThread（USoundWaveProcedural 要求）─────────────
    if (Result.AudioPCMData && Result.AudioSamplesCount > 0
        && ProceduralSoundWave && GAudioComponent)
    {
        // 拷贝到局部 buffer 后投递，避免 Result 在 GameThread 执行前被 FreeResult 释放
        TArray<uint8> AudioCopy;
        ConvertFloat32ToInt16Bytes(
            Result.AudioPCMData, Result.AudioSamplesCount, AudioCopy);

        // debug 写文件（后台线程就可以写，不必等 GameThread）
        if (debug)
        {
            if (!bOutFileOpened)
            {
                FString SavePath = FPaths::ProjectSavedDir() + TEXT("debug_out_audio.pcm");
                OutPCMFileHandle = FPlatformFileManager::Get()
                    .GetPlatformFile().OpenWrite(*SavePath, false);
                bOutFileOpened = true;
            }
            if (OutPCMFileHandle)
                OutPCMFileHandle->Write(AudioCopy.GetData(), AudioCopy.Num());
        }


        // ── QueueAudio 背压（关键修复）──────────────────
        //   原实现：积压超阈就丢弃这段音频。但 PopResult 已把它从引擎
        //   队列弹出，丢弃 = 永久丢失 → 大段中间音频消失，
        //   听感上"音频没播完就结束了"。
        //   引擎推理速度 >> 音频实时播放速度(1x)，队列会堆积。
        //   正确做法：背压——待播队列超高水位时【阻塞等待】
        //   到低水位以下再 QueueAudio。一帧不丢，播放速率自然
        //   把管线限到 1x，音视频同步且完整。
        //   本函数在 FResRunnable 后台线程执行，可安全 sleep；
        //   等待时检查 bRunning，能被 Stop/Deinitialize 及时打断。
        if (ProceduralSoundWave && GAudioComponent)
        {
            const int32 HighWaterBytes = 16000 * 2 * 3 / 2; // 48000 ≈ 1.5s
            const int32 LowWaterBytes = 16000 * 2 * 4 / 5; // 25600 ≈ 0.8s

            if (ProceduralSoundWave->GetAvailableAudioByteCount() >= HighWaterBytes)
            {
                while (bRunning
                    && ProceduralSoundWave
                    && ProceduralSoundWave->GetAvailableAudioByteCount() > LowWaterBytes)
                {
                    FPlatformProcess::SleepNoStats(0.005f);
                }
            }

            if (bRunning && ProceduralSoundWave)
                ProceduralSoundWave->QueueAudio(AudioCopy.GetData(), AudioCopy.Num());
        }

    }

    // ── 图像：UpdateTexture 内部走 ENQUEUE_RENDER_COMMAND，此处可直接调用 ──
    if (Result.ImageData)
    {
        //double T0 = FPlatformTime::Seconds();
        UpdateTexture(Result.ImageData, Result.ImageWidth, Result.ImageHeight);
        //double T1 = FPlatformTime::Seconds();
        //UE_LOG(LogDigitalHuman, Log,TEXT("[ThreadTick] UpdateTexture (%dx%d): %.2f ms"),Result.ImageWidth, Result.ImageHeight, (T1 - T0) * 1000.0);
    }

    // ── FreeResult：后台线程，不占 GameThread ─────────────────────

    DHEngine->FreeResult(Result);

}


// ============================================================
//  UpdateTexture
//
//  优化（对比原版）：
//    1. 修复 bug：原代码先赋值 TexWidth=Width 再判断，导致尺寸变化时
//       第二个 if 永远为 false，实际拷贝被跳过。
//    2. 双缓冲 staging（kStagingCount=2）：
//       · 用 TAtomic<bool> bInUse 无锁竞争空闲 slot
//       · SetNumUninitialized + EAllowShrinking::No 复用已分配内存
//    3. 单次 Memcpy：ImageData → staging，渲染线程直接写 RHI（原来两次）
//    4. 渲染命令 ON_SCOPE_EXIT 自动归还 staging slot
//    5. 纹理重建放 GameThread AsyncTask，本帧跳过，下帧尺寸匹配后恢复正常
// ============================================================
void UDigHumanSubsystem::UpdateTexture(unsigned char* ImageData, int Width, int Height)
{
    if (!GAvatar_Image || !ImageData || Width == 0 || Height == 0)
    {
        return;
    }

    // ── 1. 尺寸变化或纹理未创建：重建纹理（GameThread）─────────────
    if (Width != TexWidth || Height != TexHeight || !OutputTexture)
    {
        const int32 NewW = Width;
        const int32 NewH = Height;

        UE_LOG(LogDigitalHuman, Warning,
            TEXT("OutputTexture resize:%d,%d"), NewW, NewH);

        AsyncTask(ENamedThreads::GameThread,
            [this, NewW, NewH]()
            {
                if (OutputTexture)
                {
                    OutputTexture->RemoveFromRoot();
                }

                TexWidth = NewW;
                TexHeight = NewH;

                OutputTexture =
                    UTexture2D::CreateTransient(
                        NewW,
                        NewH,
                        PF_B8G8R8A8);

                OutputTexture->AddToRoot();
                OutputTexture->SRGB = true;
                OutputTexture->Filter = TF_Bilinear;
                OutputTexture->NeverStream = true;
                OutputTexture->UpdateResource();

                GAvatar_Image->SetBrushFromTexture(
                    OutputTexture,
                    true);
            });

        return;
    }

    // ── 2. 后台线程：取 staging，仅做 Memcpy ─────────────────────
    FStagingBuffer* Staging = GetFreeStagingBuffer();

    if (!Staging)
    {
        UE_LOG(LogDigitalHuman,
            Warning,
            TEXT("UpdateTexture: staging buffers full, dropping frame"));
        return;
    }

    const int64 DataSize = (int64)Width * Height * 4;

#if ENGINE_MAJOR_VERSION > 5 || (ENGINE_MAJOR_VERSION == 5 && ENGINE_MINOR_VERSION >= 7)
    Staging->Data.SetNumUninitialized(
        DataSize,
        EAllowShrinking::No);
#else
    Staging->Data.SetNumUninitialized(
        DataSize,
        false);
#endif

    FMemory::Memcpy(
        Staging->Data.GetData(),
        ImageData,
        DataSize);

    // ── 3. 渲染命令：GetResource() 在渲染线程调用 ────────────────
    const int32 W = Width;
    const int32 H = Height;

    UTexture2D* TexPtr = OutputTexture;

    ENQUEUE_RENDER_COMMAND(UpdateDHTexture)(
        [TexPtr, Staging, W, H]
    (FRHICommandListImmediate& RHICmdList)
        {
            struct FStagingGuard
            {
                FStagingBuffer* S;

                explicit FStagingGuard(FStagingBuffer* InS)
                    : S(InS)
                {
                }

                ~FStagingGuard()
                {
                    if (S)
                    {
                        S->bInUse = false;
                    }
                }
            } Guard(Staging);

            if (!TexPtr)
            {
                return;
            }

            FTextureResource* Resource = TexPtr->GetResource();

            if (!Resource)
            {
                return;
            }

#if ENGINE_MAJOR_VERSION > 5 || (ENGINE_MAJOR_VERSION == 5 && ENGINE_MINOR_VERSION >= 7)

            FRHITexture* RHITex = Resource->GetTexture2DRHI();

            if (!RHITex)
            {
                return;
            }

#else

            FRHITexture2D* RHITex = Resource->GetTexture2DRHI();

            if (!RHITex)
            {
                return;
            }

#endif

            uint32 DestStride = 0;

            void* Dest =
                RHILockTexture2D(
                    RHITex,
                    0,
                    RLM_WriteOnly,
                    DestStride,
                    false);

            if (!Dest)
            {
                return;
            }

            const uint32 SrcPitch = (uint32)(W * 4);

            if (DestStride == SrcPitch)
            {
                FMemory::Memcpy(
                    Dest,
                    Staging->Data.GetData(),
                    (int64)W * H * 4);
            }
            else
            {
                const uint8* Src = Staging->Data.GetData();

                for (int32 Row = 0; Row < H; ++Row)
                {
                    FMemory::Memcpy(
                        (uint8*)Dest + (int64)Row * DestStride,
                        Src + (int64)Row * SrcPitch,
                        SrcPitch);
                }
            }

            RHIUnlockTexture2D(
                RHITex,
                0,
                false);
        });
}

// ============================================================
//  Tick（GameThread，FTickableGameObject）
//  TickRealtime 调用 DHEngine->TickRealtime()，推理本身在此执行。
// ============================================================
void UDigHumanSubsystem::Tick(float DeltaTime)
{
    if (!IsReady())
        return;



    const double Now = FPlatformTime::Seconds();


    if ((Now - LastInferenceTime) >= TargetInterval)
    {//必须限制在30fps，不然120fps会拉爆内存
        LastInferenceTime = Now;

        TickRealtime();
    }
}


// ============================================================
//  BrocastResult
// ============================================================
void UDigHumanSubsystem::BrocastResult(bool res)
{
    bRunning = res;
    AsyncTask(ENamedThreads::GameThread, [this, res]()
        {
            if (OnModelReady.IsBound()) OnModelReady.Broadcast(res);
        });
}


// ============================================================
//  ComputeViedoFromFile
// ============================================================
bool UDigHumanSubsystem::ComputeViedoFromFile(
    const FString& WavPath, const FString& VideoPath, const FString& OutPutVideoPath)
{
    if (!DHEngine) return false;

    Async(EAsyncExecution::Thread, [this, WavPath, VideoPath, OutPutVideoPath]()
        {
            bool bSuccess = DHEngine->ComputeVideoFromFile(
                TCHAR_TO_UTF8(*WavPath),
                TCHAR_TO_UTF8(*VideoPath),
                TCHAR_TO_UTF8(*OutPutVideoPath));

            AsyncTask(ENamedThreads::GameThread, [this, bSuccess, OutPutVideoPath]()
                {

                    if (OnCalcViedoFinished.IsBound())
                        OnCalcViedoFinished.Broadcast(bSuccess);
                });
        });
    return true;
}

void UDigHumanSubsystem::SetSceneRendering(UObject* WorldContextObject, bool bOn)
{
    if (!WorldContextObject)
    {
        return;
    }

    UWorld* World = WorldContextObject->GetWorld();

    if (!World)
    {
        return;
    }

    if (UGameViewportClient* Viewport = World->GetGameViewport())
    {

        UE_LOG(LogTemp, Warning,
            TEXT("SetSceneRendering:%d"), Viewport->bDisableWorldRendering = !bOn);
    }
}


// ============================================================
//  ChangeAvatarStatue
// ============================================================
void UDigHumanSubsystem::ChangeAvatarStatue(int32 statue)
{
    if (DHEngine) DHEngine->ChangeVideoStatue(statue);
}


// ============================================================
//  FReadImageRunnable（原有，保持不变）
// ============================================================
FReadImageRunnable* FReadImageRunnable::InitReadRunnable(
    UDigHumanSubsystem* inActor,
    FString VideoPath, FString IdlePath, FString TalkPath,
    FString WavPath, FString OutputVideoPath, int function_idx)
{
    if (!ReadInstance && FPlatformProcess::SupportsMultithreading())
        ReadInstance = new FReadImageRunnable(inActor, VideoPath, IdlePath, TalkPath, function_idx);
    else if (ReadInstance)
        UE_LOG(LogTemp, Warning,
            TEXT("InitReadRunnable: instance already exists, call Shutdown first"));
    return ReadInstance;
}

FReadImageRunnable::FReadImageRunnable(
    UDigHumanSubsystem* inReadActor,
    FString VideoPath, FString IdlePath, FString TalkPath, int function_idx)
{
    ReadActor = inReadActor;
    GVideoPath = VideoPath;
    Gfunction_idx = function_idx;
    GIdlePath = IdlePath;
    GTalkPath = TalkPath;

    ReadImageThread = FRunnableThread::Create(
        this, TEXT("ReadImageRunnable"), 0, EThreadPriority::TPri_Normal);
}

FReadImageRunnable::~FReadImageRunnable() {}

bool FReadImageRunnable::Init() { bRunning = true; return true; }

uint32 FReadImageRunnable::Run()
{
    if (!ReadActor) return 1;

    auto ProcessVideo = [&](int32 Index, const FString& Path) -> bool
        {
            if (!ReadActor->DHEngine->PreprocessVideo(Index, TCHAR_TO_UTF8(*Path)))
            {
                UE_LOG(LogTemp, Error, TEXT("DLL Failed to preprocess video: %s"), *Path);
                ReadActor->BrocastResult(false);
                return false;
            }
            return true;
        };

    if (!ProcessVideo(0, GIdlePath)) return 1;
    if (!ProcessVideo(1, GTalkPath)) return 1;
    ReadActor->BrocastResult(true);

    UE_LOG(LogTemp, Warning, TEXT("ReadImageRunnable: preprocessing complete"));
    return 0;
}

void FReadImageRunnable::Stop() { bRunning = false; }

void FReadImageRunnable::Shutdown()
{
    bRunning = false;
    if (ReadImageThread)
    {
        UE_LOG(LogTemp, Warning, TEXT("ReadImageThread: WaitForCompletion"));
        ReadImageThread->WaitForCompletion();
        delete ReadImageThread;
        ReadImageThread = nullptr;
    }
    ReadInstance = nullptr;
    UE_LOG(LogTemp, Warning, TEXT("ReadImageRunnable: Shutdown complete"));
}


// ============================================================
//  FWavPushRunnable — WAV 流式推送线程
// ============================================================
FWavPushRunnable* FWavPushRunnable::Create(
    UDigHumanSubsystem* InSubsystem,
    const FString& InWavPath,
    int32               InChunkSamples,
    int32               InIntervalMs)
{
    if (!FPlatformProcess::SupportsMultithreading())
    {
        UE_LOG(LogDigitalHuman, Error,
            TEXT("FWavPushRunnable: platform does not support multithreading"));
        return nullptr;
    }

    FWavPushRunnable* Runnable = new FWavPushRunnable(
        InSubsystem, InWavPath, InChunkSamples, InIntervalMs);

    Runnable->PushThread = FRunnableThread::Create(
        Runnable, TEXT("WavPushRunnable"), 0, TPri_Normal);

    if (!Runnable->PushThread)
    {
        UE_LOG(LogDigitalHuman, Error,
            TEXT("FWavPushRunnable: FRunnableThread::Create failed"));
        delete Runnable;
        return nullptr;
    }
    return Runnable;
}

FWavPushRunnable::FWavPushRunnable(
    UDigHumanSubsystem* InSubsystem,
    const FString& InWavPath,
    int32               InChunkSamples,
    int32               InIntervalMs)
    : Subsystem(InSubsystem)
    , WavPath(InWavPath)
    , ChunkSamples(InChunkSamples)
    , IntervalMs(InIntervalMs)
{
}

FWavPushRunnable::~FWavPushRunnable() {}

bool FWavPushRunnable::Init()
{
    bRunning = true;
    return true;
}


// ── WAV 解析与重采样 ──────────────────────────────────────────
//  支持：PCM 8/16/24/32-bit，IEEE Float 32-bit，单/双声道，任意采样率
//  输出：16kHz float[-1,1] mono PCM
bool FWavPushRunnable::LoadAndResampleWav(const FString& Path, TArray<float>& OutPCM) const
{
    TArray<uint8> FileData;
    if (!FFileHelper::LoadFileToArray(FileData, *Path))
    {
        UE_LOG(LogDigitalHuman, Error,
            TEXT("FWavPushRunnable: Cannot open WAV: %s"), *Path);
        return false;
    }

    const uint8* Data = FileData.GetData();
    int32        Size = FileData.Num();

    auto ReadU16 = [&](int32 Offset) -> uint16
        {
            if (Offset + 1 >= Size) return 0;
            return uint16(Data[Offset]) | (uint16(Data[Offset + 1]) << 8);
        };
    auto ReadU32 = [&](int32 Offset) -> uint32
        {
            if (Offset + 3 >= Size) return 0;
            return uint32(Data[Offset])
                | (uint32(Data[Offset + 1]) << 8)
                | (uint32(Data[Offset + 2]) << 16)
                | (uint32(Data[Offset + 3]) << 24);
        };

    if (Size < 44
        || FMemory::Memcmp(Data, "RIFF", 4) != 0
        || FMemory::Memcmp(Data + 8, "WAVE", 4) != 0)
    {
        UE_LOG(LogDigitalHuman, Error,
            TEXT("FWavPushRunnable: Not a valid RIFF/WAVE file: %s"), *Path);
        return false;
    }

    uint16 AudioFormat = 0;
    uint16 NumChannels = 0;
    uint32 SampleRate = 0;
    uint16 BitsPerSample = 0;
    int32  DataOffset = -1;
    int32  DataSize = 0;

    int32 Pos = 12;
    while (Pos + 8 <= Size)
    {
        char     ChunkId[5] = {};
        FMemory::Memcpy(ChunkId, Data + Pos, 4);
        uint32 ChunkSize = ReadU32(Pos + 4);
        Pos += 8;

        if (FMemory::Memcmp(ChunkId, "fmt ", 4) == 0)
        {
            AudioFormat = ReadU16(Pos);
            NumChannels = ReadU16(Pos + 2);
            SampleRate = ReadU32(Pos + 4);
            BitsPerSample = ReadU16(Pos + 14);
        }
        else if (FMemory::Memcmp(ChunkId, "data", 4) == 0)
        {
            DataOffset = Pos;
            DataSize = (int32)ChunkSize;
            break;
        }
        Pos += (int32)ChunkSize + ((int32)ChunkSize & 1);
    }

    if (DataOffset < 0 || DataSize <= 0 || NumChannels == 0 || SampleRate == 0)
    {
        UE_LOG(LogDigitalHuman, Error,
            TEXT("FWavPushRunnable: Incomplete WAV header: %s"), *Path);
        return false;
    }
    if (AudioFormat != 1 && AudioFormat != 3)
    {
        UE_LOG(LogDigitalHuman, Error,
            TEXT("FWavPushRunnable: Unsupported AudioFormat=%d: %s"),
            (int32)AudioFormat, *Path);
        return false;
    }

    const int32 BytesPerSample = BitsPerSample / 8;
    const int32 BytesPerFrame = BytesPerSample * NumChannels;
    const int32 TotalFrames = DataSize / BytesPerFrame;
    if (TotalFrames <= 0)
    {
        UE_LOG(LogDigitalHuman, Error,
            TEXT("FWavPushRunnable: Empty data chunk: %s"), *Path);
        return false;
    }

    TArray<float> RawMono;
    RawMono.Reserve(TotalFrames);

    for (int32 i = 0; i < TotalFrames; ++i)
    {
        int32 FrameStart = DataOffset + i * BytesPerFrame;
        if (FrameStart + BytesPerSample > Size) break;

        float Sample = 0.0f;
        if (AudioFormat == 3)
        {
            FMemory::Memcpy(&Sample, Data + FrameStart, 4);
        }
        else
        {
            switch (BitsPerSample)
            {
            case 8:
                Sample = (float(Data[FrameStart]) - 128.0f) / 128.0f;
                break;
            case 16:
            {
                int16 s = int16(uint16(Data[FrameStart]) | (uint16(Data[FrameStart + 1]) << 8));
                Sample = float(s) / 32768.0f;
                break;
            }
            case 24:
            {
                int32 raw = int32(Data[FrameStart])
                    | (int32(Data[FrameStart + 1]) << 8)
                    | (int32(Data[FrameStart + 2]) << 16);
                if (raw & 0x800000) raw |= 0xFF000000;
                Sample = float(raw) / 8388608.0f;
                break;
            }
            case 32:
            {
                int32 raw;
                FMemory::Memcpy(&raw, Data + FrameStart, 4);
                Sample = float(raw) / 2147483648.0f;
                break;
            }
            default: Sample = 0.0f;
            }
        }
        RawMono.Add(FMath::Clamp(Sample, -1.0f, 1.0f));
    }

    const int32 TargetRate = Subsystem->AudioSampleRate;
    if ((int32)SampleRate == TargetRate)
    {
        OutPCM = MoveTemp(RawMono);
    }
    else
    {
        double Ratio = double(SampleRate) / TargetRate;
        int32  DstCount = FMath::CeilToInt(double(RawMono.Num()) / Ratio);
        OutPCM.SetNumUninitialized(DstCount);
        for (int32 DstIdx = 0; DstIdx < DstCount; ++DstIdx)
        {
            double SrcPos = DstIdx * Ratio;
            int32  Lo = FMath::FloorToInt(SrcPos);
            int32  Hi = FMath::Min(Lo + 1, RawMono.Num() - 1);
            float  t = float(SrcPos - Lo);
            OutPCM[DstIdx] = FMath::Lerp(RawMono[Lo], RawMono[Hi], t);
        }
        UE_LOG(LogDigitalHuman, Log,
            TEXT("FWavPushRunnable: Resampled %dHz->%dHz  %d->%d samples"),
            (int32)SampleRate, TargetRate, RawMono.Num(), DstCount);
    }

    UE_LOG(LogDigitalHuman, Log,
        TEXT("FWavPushRunnable: WAV loaded — %d samples @ 16kHz, %.2f sec  [src: %dHz %dch %dbit]"),
        OutPCM.Num(), float(OutPCM.Num()) / TargetRate,
        (int32)SampleRate, (int32)NumChannels, (int32)BitsPerSample);

    return true;
}


// ── FWavPushRunnable::Run — 精确定时推送 ────────────────────────
//
//  优化：debug 录音复用 DebugPCMBuffer（member），消除每 chunk heap alloc
//
uint32 FWavPushRunnable::Run()
{
    // 1. 加载并重采样 WAV
    TArray<float> PCM;
    if (!LoadAndResampleWav(WavPath, PCM))
    {
        TWeakObjectPtr<UDigHumanSubsystem> WeakSub(Subsystem);
        AsyncTask(ENamedThreads::GameThread, [WeakSub]()
            {
                if (WeakSub.IsValid() && WeakSub->OnWavPushFinished.IsBound())
                    WeakSub->OnWavPushFinished.Broadcast(false);
            });
        return 1;
    }

    const int32 TotalSamples = PCM.Num();
    UE_LOG(LogDigitalHuman, Log,
        TEXT("WavPushRunnable: Start pushing %d samples  interval=%dms"),
        TotalSamples, IntervalMs);

    // 2. 等待引擎就绪（PreprocessVideo 异步执行，可能耗时数秒）
    {
        const float WaitTimeoutSec = 60.0f;
        float       WaitedSec = 0.0f;
        while (bRunning && Subsystem && !Subsystem->IsReady())
        {
            FPlatformProcess::SleepNoStats(0.05f);
            WaitedSec += 0.05f;
            if (WaitedSec >= WaitTimeoutSec)
            {
                UE_LOG(LogDigitalHuman, Error,
                    TEXT("WavPushRunnable: Timeout waiting for engine IsReady()"));
                TWeakObjectPtr<UDigHumanSubsystem> WeakSub(Subsystem);
                AsyncTask(ENamedThreads::GameThread, [WeakSub]()
                    {
                        if (WeakSub.IsValid() && WeakSub->OnWavPushFinished.IsBound())
                            WeakSub->OnWavPushFinished.Broadcast(false);
                    });
                return 1;
            }
        }
    }
    if (!bRunning) return 0;

    UE_LOG(LogDigitalHuman, Log, TEXT("WavPushRunnable: Engine ready, begin streaming"));

    // 3. 精确定时推送主循环
    //    用绝对时间点 WakeAt 累加，避免 sleep 漂移
    const double IntervalSec = IntervalMs / 1000.0;
    double WakeAt = FPlatformTime::Seconds() + IntervalSec;
    int32  Offset = 0;

    while (bRunning && Offset < TotalSamples && Subsystem)
    {
        int32 Count = FMath::Min(ChunkSamples, TotalSamples - Offset);

        Subsystem->DHEngine->PushAudioSamples(PCM.GetData() + Offset, Count);


        // debug 录音：复用 DebugPCMBuffer，消除每 chunk heap alloc
        if (Subsystem->debug)
        {
            ConvertFloat32ToInt16Bytes(
                PCM.GetData() + Offset, Count, DebugPCMBuffer);

            if (!Subsystem->bRecordFileOpened)
            {
                FString SavePath = FPaths::ProjectSavedDir() + TEXT("debug_in_audio.pcm");
                Subsystem->InPCMFileHandle = FPlatformFileManager::Get()
                    .GetPlatformFile().OpenWrite(*SavePath, false);
                Subsystem->bRecordFileOpened = true;
            }
            if (Subsystem->InPCMFileHandle)
                Subsystem->InPCMFileHandle->Write(
                    DebugPCMBuffer.GetData(), DebugPCMBuffer.Num());
        }

        Offset += Count;

        // 精确 sleep：粗睡到 1ms 前，剩余自旋
        double Now = FPlatformTime::Seconds();
        double Remaining = WakeAt - Now;
        if (Remaining > 0.001)
            FPlatformProcess::SleepNoStats(float(Remaining) - 0.001f);
        while (FPlatformTime::Seconds() < WakeAt && bRunning) {}

        WakeAt += IntervalSec;
    }

    // ── 尾部冲刷（关键修复 Bug2）─────────────────────
    //   推流结束时，引擎 AudioRingBuffer 还积压大量未消费音频；
    //   且引擎 bDoInference 门控需 available > BatchTotal + Ctx*2 约 19680，
    //   末尾约 1.2s 真实音频永远不满足门控、永不被推理。
    //   若此时立即广播 Finished 并停推理，最后这段口型丢失，
    //   表现为“音频还没播完画面就结束”。
    //   修复：推完真实 PCM 后补足够静音，把卡在门限下的
    //   尾部真实音频顶过阈值让引擎把它推理出来；
    //   静音样本不会产生口型（BNF静音抑制），不污染画面。
    if (bRunning && Subsystem && Subsystem->DHEngine && (Offset >= TotalSamples))
    {
        // 冲刷静音量：覆盖 门控阈值(~19680) + Heygm预填(16000)
        //   + 余量，取 48000(3s) 足够把任何末尾真实音频顶过门限。
        const int32 kFlushSilence = 48000;
        const int32 kStep = (ChunkSamples > 0 ? ChunkSamples : 160);
        TArray<float> Zeros;
        Zeros.SetNumZeroed(kStep);

        int32 Fed = 0;
        double WakeAt2 = FPlatformTime::Seconds() + (IntervalMs / 1000.0);
        while (bRunning && Fed < kFlushSilence && Subsystem && Subsystem->DHEngine)
        {
            int32 c = FMath::Min(kStep, kFlushSilence - Fed);
            Subsystem->DHEngine->PushAudioSamples(Zeros.GetData(), c);
            Fed += c;
            double Now = FPlatformTime::Seconds();
            double Rem = WakeAt2 - Now;
            if (Rem > 0.001) FPlatformProcess::SleepNoStats(float(Rem) - 0.001f);
            while (FPlatformTime::Seconds() < WakeAt2 && bRunning) {}
            WakeAt2 += (IntervalMs / 1000.0);
        }

        // 给引擎/FResRunnable 一点时间把冲刷出的帧处理入队。
        FPlatformProcess::SleepNoStats(0.2f);

        // 等待背压后的播放队列放完：按本段总时长补等
        //   （TotalSamples / 16000 秒），确保最后一帧音频播完才 Finished。
        {
            double PlaySec = double(TotalSamples) / 16000.0;
            double WaitEnd = FPlatformTime::Seconds() + FMath::Min(PlaySec, 60.0) + 0.5;
            while (bRunning && FPlatformTime::Seconds() < WaitEnd
                && Subsystem && Subsystem->ProceduralSoundWave)
            {
                if (Subsystem->ProceduralSoundWave->GetAvailableAudioByteCount() <= 0)
                    break;
                FPlatformProcess::SleepNoStats(0.05f);
            }
        }
    }

    bool bCompleted = (Offset >= TotalSamples);
    UE_LOG(LogDigitalHuman, Log,
        TEXT("WavPushRunnable: %s  pushed %d/%d samples"),
        bCompleted ? TEXT("Completed") : TEXT("Stopped early"),
        Offset, TotalSamples);

    // 4. 回主线程广播完成
    TWeakObjectPtr<UDigHumanSubsystem> WeakSub(Subsystem);
    AsyncTask(ENamedThreads::GameThread, [WeakSub, bCompleted]()
        {
            if (WeakSub.IsValid() && WeakSub->OnWavPushFinished.IsBound())
                WeakSub->OnWavPushFinished.Broadcast(bCompleted);
        });
    return 0;
}

void FWavPushRunnable::Stop() { bRunning = false; }

void FWavPushRunnable::Shutdown()
{
    bRunning = false;
    if (PushThread)
    {
        PushThread->WaitForCompletion();
        delete PushThread;
        PushThread = nullptr;
    }
    UE_LOG(LogDigitalHuman, Log, TEXT("FWavPushRunnable: Shutdown complete"));
}


// ============================================================
//  FResRunnable
//
//  优化：改为事件驱动（Wait ResultReadyEvent），消除 1ms 轮询空转。
//        FPS 日志保留，方便监控吞吐。
// ============================================================
FResRunnable* FResRunnable::Create(UDigHumanSubsystem* InSubsystem)
{
    if (!FPlatformProcess::SupportsMultithreading())
    {
        UE_LOG(LogDigitalHuman, Warning, TEXT("FResRunnable: Multithreading not supported"));
        return nullptr;
    }

    FResRunnable* Instance = new FResRunnable(InSubsystem);
    Instance->ResThread = FRunnableThread::Create(
        Instance, TEXT("FResRunnable"), 0, TPri_Normal);

    if (!Instance->ResThread)
    {
        UE_LOG(LogDigitalHuman, Error, TEXT("FResRunnable: Thread creation failed"));
        delete Instance;
        return nullptr;
    }
    return Instance;
}

FResRunnable::FResRunnable(UDigHumanSubsystem* InSubsystem)
    : Subsystem(InSubsystem)
{
}
FResRunnable::~FResRunnable() {}

bool FResRunnable::Init()
{
    bRunning = true;
    return true;
}

uint32 FResRunnable::Run()
{
    const double TargetInterval = 1.0 / 33.0; // 33.333ms

    while (bRunning)
    {
        double FrameStart = FPlatformTime::Seconds();

        if (!bRunning) break;

        //double T0 = FPlatformTime::Seconds();
        Subsystem->ThreadTick();
        //double T1 = FPlatformTime::Seconds();
        //UE_LOG(LogDigitalHuman, Log, TEXT("[ThreadTick] ThreadTick: %.2f ms"), (T1 - T0) * 1000.0);

        // 算出本帧剩余时间
        double Elapsed = FPlatformTime::Seconds() - FrameStart;
        double Remaining = TargetInterval - Elapsed;

        if (Remaining > 0.002)
        {
            // 粗睡到距唤醒点 2ms 前，减少 CPU 占用
            FPlatformProcess::SleepNoStats(float(Remaining) - 0.002f);
        }
        // 剩余 2ms 内自旋，保证精度
        double WakeAt = FrameStart + TargetInterval;
        while (FPlatformTime::Seconds() < WakeAt && bRunning) {}
    }
    return 0;
}

void FResRunnable::Stop() { bRunning = false; }

void FResRunnable::Shutdown()
{
    bRunning = false;
    if (ResThread)
    {
        ResThread->WaitForCompletion();
        delete ResThread;
        ResThread = nullptr;
    }
    UE_LOG(LogDigitalHuman, Log, TEXT("FResRunnable: Shutdown complete"));
}