#pragma once

#include "CoreMinimal.h"
#include <AudioCaptureCore.h>
#include "Components/SynthComponent.h"
#include "Containers/Queue.h"
#include "NewAudioCaptureComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGenerateAudioD, const TArray<uint8>&, OutAudio);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGenerateAudioF, const TArray<float>&, OutAudioFloat);

UCLASS(ClassGroup = Synth, meta = (BlueprintSpawnableComponent))
class REALAVATARN_API UNewAudioCaptureComponent : public USynthComponent
{
    GENERATED_BODY()

    // 头文件
public:
    UNewAudioCaptureComponent(const FObjectInitializer& ObjectInitializer);
    virtual void BeginPlay() override;
    virtual void OnRegister() override;

protected:
    //~ USynthComponent
    virtual bool  Init(int32& SampleRate) override;
    virtual int32 OnGenerateAudio(float* OutAudio, int32 NumSamples) override;
    virtual void  OnBeginGenerate() override;
    virtual void  OnEndGenerate() override;

    //~ UActorComponent
    virtual void TickComponent(float DeltaTime,
        ELevelTick TickType,
        FActorComponentTickFunction* ThisTickFunction) override;

    //~ UObject
    virtual void BeginDestroy() override;
    virtual bool IsReadyForFinishDestroy() override;
    virtual void FinishDestroy() override;

public:
    /** 每次广播一块的样本数 (16kHz 单声道)。例如 160 = 10ms, 320 = 20ms */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Latency",
        meta = (ClampMin = "16", ClampMax = "102400"))
    int32 OnceSendFloatDataNum = 160;

    /** 目标输出采样率，固定 16000 即可；保留为参数方便以后改 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Latency",
        meta = (ClampMin = "8000", ClampMax = "48000"))
    int32 TargetSampleRate = 48000;

    /** 蓝图开关：是否广播 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Latency")
    bool bBroadcastEnabled = true;

    /** 选择广播的格式：true 走 OnAudioOutFloat，false 走 OnAudioOut(uint8 PCM) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Latency")
    bool bUseFloat = true;

    UPROPERTY(BlueprintAssignable) FOnGenerateAudioD OnAudioOut;
    UPROPERTY(BlueprintAssignable) FOnGenerateAudioF OnAudioOutFloat;

private:
    // ---- 采集 ----
    // ✅ 改为指针，避免 CDO 构造时 FAudioCaptureSynth 内部崩溃
    Audio::FAudioCaptureSynth* CaptureSynth = nullptr;
    int32 NumChannels = 0;
    int32 G_SampleRate = 0;

    bool bIsStreamOpen = false;
    FThreadSafeBool bIsDestroying;
    FThreadSafeBool bIsNotReadyForForFinishDestroy;

    // ---- 音频线程私有的临时区（无需加锁，只在 OnGenerateAudio 内访问）----
    TArray<float> ScratchInterleaved;   // 从 CaptureSynth 拉到的原始交错样本
    TArray<float> ScratchMono;          // 下混成单声道、原采样率
    TArray<float> ReadyBuffer16k;       // 重采样到 16k 后的待切块缓冲
    double        ResamplePhase = 0.0;  // 重采样相位累加器（跨调用连续）

    // ---- 跨线程：音频线程切好块 -> game thread 取出广播 ----
    FCriticalSection SendQueueCS;
    TArray<TArray<float>> PendingSendQueue;
};