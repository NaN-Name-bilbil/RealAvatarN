// DigHumanSubsystem.h
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Components/Image.h"
#include "DigitalHumanAPI.h"

#include "Runtime/Core/Public/HAL/RunnableThread.h"
#include "Runtime/Core/Public/HAL/Runnable.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundWaveProcedural.h"
#include "Tickable.h"
#include "DigHumanSubsystem.generated.h"

class FReadImageRunnable;
class FWavPushRunnable;
class FResRunnable;


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnModelLoaded, bool, result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnModelReady, bool, result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCalcViedoFinished, bool, result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWavPushFinished, bool, result);

DEFINE_LOG_CATEGORY_STATIC(LogDigitalHuman, Log, All);

static void OnDHLog(int level, const char* msg)
{
	switch (level)
	{
	case 0:  UE_LOG(LogDigitalHuman, Log, TEXT("%s"), UTF8_TO_TCHAR(msg)); break;
	case 1:  UE_LOG(LogDigitalHuman, Warning, TEXT("%s"), UTF8_TO_TCHAR(msg)); break;
	default: UE_LOG(LogDigitalHuman, Error, TEXT("%s"), UTF8_TO_TCHAR(msg)); break;
	}
}

typedef IDigitalHumanEngine* (*FCreateDigitalHumanEngine)(DHLogCallback);
typedef void                 (*FDestroyDigitalHumanEngine)(IDigitalHumanEngine*);


UCLASS()
class REALAVATARN_API UDigHumanSubsystem : public UGameInstanceSubsystem, public FTickableGameObject
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// FTickableGameObject 接口
	virtual void Tick(float DeltaTime) override;
	virtual bool IsTickable() const override { return !IsTemplate(); }
	virtual TStatId GetStatId() const override
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(UDigHumanSubsystem, STATGROUP_Tickables);
	}

	// ── 原有接口 ────────────────────────────────────────────────
	bool InitCustomModel(const FString& licenseKey, const FString& MaskDir);

	UFUNCTION(BlueprintCallable, Category = "DigHuman")
	bool InitSystemModel(const FString& licenseKey, int32 BatchSize = 1, UAudioComponent* AudioComponent = nullptr);

	UFUNCTION(BlueprintCallable, Category = "DigHuman")
	bool StartRealtimeDrive(const FString& IdleVideoPath, const FString& TalkVideoPath, UImage* Avatar_Image);

	UFUNCTION(BlueprintCallable, Category = "DigHuman")
	void PushAudioSamples(const TArray<float>& InPCM);

	UFUNCTION(BlueprintCallable, Category = "DigHuman")
	void ChangeAvatarStatue(int32 statue);

	UFUNCTION(BlueprintCallable, Category = "DigHuman")
	void ThreadTick();

	void generateaudio(const DHInferenceResult& Result);

	UFUNCTION(BlueprintPure, Category = "DigHuman")
	bool IsReady() const;

	UFUNCTION(BlueprintCallable, Category = "DigHuman")
	bool ComputeViedoFromFile(const FString& WavPath, const FString& VideoPath, const FString& OutPutVideoPath);

	// 在你的 GameMode 或 Subsystem 里调用一次即可
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static void SetSceneRendering(UObject* WorldContextObject, bool bOn);

	// ── WAV 文件流式推送 ────────────────────────────────────────
	UFUNCTION(BlueprintCallable, Category = "DigHuman",
		meta = (ToolTip = "从WAV文件模拟TTS流式推送，自动启动推理线程\nChunkSamples=160 IntervalMs=10 建议10ms回调节奏"))
	bool StartWavStream(
		const FString& WavPath,
		int32          ChunkSamples = 160,
		int32          IntervalMs = 10);

	UFUNCTION(BlueprintCallable, Category = "DigHuman")
	void StopWavStreamTest();

	// ── C++ 内部 ────────────────────────────────────────────────
	void TickRealtime();
	void UpdateTexture(unsigned char* ImageData, int Width, int Height);
	void BrocastResult(bool res);

	// ── 双缓冲 staging buffer（UpdateTexture 零 heap alloc）──────
	// 渲染命令执行完后通过 bInUse=false 归还，无需额外锁
	struct FStagingBuffer
	{
		TArray<uint8>   Data;
		TAtomic<bool>   bInUse{ false };
	};
	static constexpr int32 kStagingCount = 2;
	FStagingBuffer StagingBuffers[kStagingCount];

	// 从双缓冲中取一个空闲 slot，全部占用时返回 nullptr
	FStagingBuffer* GetFreeStagingBuffer()
	{
		for (int32 i = 0; i < kStagingCount; ++i)
		{
			bool Expected = false;
			if (StagingBuffers[i].bInUse.CompareExchange(Expected, true))
				return &StagingBuffers[i];
		}
		return nullptr;
	}

public:
	UPROPERTY(BlueprintAssignable, Category = "DigHuman")
	FOnCalcViedoFinished OnCalcViedoFinished;

	UPROPERTY(BlueprintAssignable, Category = "DigHuman")
	FOnModelLoaded OnModelLoaded;

	UPROPERTY(BlueprintAssignable, Category = "DigHuman")
	FOnModelReady OnModelReady;

	UPROPERTY(BlueprintAssignable, Category = "DigHuman")
	FOnWavPushFinished OnWavPushFinished;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DigHuman")
	int32 InferenceBatchSize = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DigHuman")
	bool Use_fp16 = true;

	bool Use_TensorRT = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
	float VideoFPS = 30.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
	int32 AudioSampleRate = 16000;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DigHuman")
	bool debug = true;

public:
	FReadImageRunnable* ReadThread = nullptr;
	FWavPushRunnable* WavPushThread = nullptr;
	FResRunnable* ResThread = nullptr;

	UTexture2D* OutputTexture = nullptr;
	FTextureRHIRef TextureRHI;

	UImage* GAvatar_Image = nullptr;

	UPROPERTY()
	USoundWaveProcedural* ProceduralSoundWave = nullptr;

	UPROPERTY()
	UAudioComponent* GAudioComponent = nullptr;

	IDigitalHumanEngine* DHEngine = nullptr;

	bool       bOutFileOpened = false;
	IFileHandle* OutPCMFileHandle = nullptr;

	bool       bRecordFileOpened = false;
	IFileHandle* InPCMFileHandle = nullptr;

	bool waitframe = false;

	// 事件：有新音频推入时触发，唤醒 FResRunnable，消除 1ms 轮询(弃用)
	FEvent* ResultReadyEvent = nullptr;

private:
	FString Plugindir;
	int32   TexWidth = 2160;
	int32   TexHeight = 3840;
	double  LastConsumeTime = 0.0;
	bool    bRunning = false;

	// 复用 buffer：generateaudio 用，避免每帧 heap alloc
	TArray<uint8> AudioConvertBuffer;

	static constexpr int32 MaxQueueSize = 10;
	static constexpr int32 PlaybackThreshold = 30;

	double LastInferenceTime = 0.0f;
	double TargetInterval = 0.002;
};


// ============================================================
//  FReadImageRunnable — 推理驱动线程（原有，保持不变）
// ============================================================
class REALAVATARN_API FReadImageRunnable : public FRunnable
{
public:
	static FReadImageRunnable* InitReadRunnable(
		UDigHumanSubsystem* inActor,
		FString VideoPath, FString IdlePath, FString TalkPath,
		FString WavPath, FString OutputVideoPath, int function_idx);

	virtual bool   Init() override;
	virtual uint32 Run()  override;
	virtual void   Stop() override;
	void Shutdown();

protected:
	FReadImageRunnable(UDigHumanSubsystem* inReadActor,
		FString VideoPath, FString IdlePath, FString TalkPath, int function_idx);
	virtual ~FReadImageRunnable();

private:
	FRunnableThread* ReadImageThread = nullptr;
	UDigHumanSubsystem* ReadActor = nullptr;
	static FReadImageRunnable* ReadInstance;

	TAtomic<bool> bRunning{ false };

	FString GVideoPath;
	int     Gfunction_idx;
	FString GIdlePath;
	FString GTalkPath;
};


// ============================================================
//  FWavPushRunnable — WAV 流式推送线程
// ============================================================
class REALAVATARN_API FWavPushRunnable : public FRunnable
{
public:
	static FWavPushRunnable* Create(
		UDigHumanSubsystem* InSubsystem,
		const FString& InWavPath,
		int32               InChunkSamples,
		int32               InIntervalMs);

	virtual bool   Init() override;
	virtual uint32 Run()  override;
	virtual void   Stop() override;
	void Shutdown();

protected:
	FWavPushRunnable(
		UDigHumanSubsystem* InSubsystem,
		const FString& InWavPath,
		int32               InChunkSamples,
		int32               InIntervalMs);
	virtual ~FWavPushRunnable();

private:
	// WAV 解析：输出 16kHz float[-1,1] mono PCM
	bool LoadAndResampleWav(const FString& Path, TArray<float>& OutPCM) const;

	// debug 录音：复用 buffer，避免每 chunk heap alloc
	TArray<uint8> DebugPCMBuffer;

	FRunnableThread* PushThread = nullptr;
	UDigHumanSubsystem* Subsystem = nullptr;

	FString WavPath;
	int32   ChunkSamples = 160;
	int32   IntervalMs = 10;

	TAtomic<bool> bRunning{ false };
};


// ============================================================
//  FResRunnable — 定帧驱动线程
//
//  优化：改为事件驱动（等待 ResultReadyEvent），
//        消除原来 SleepNoStats(0.001f) 的 1ms 空转轮询。
// ============================================================
class REALAVATARN_API FResRunnable : public FRunnable
{
public:
	static FResRunnable* Create(UDigHumanSubsystem* InSubsystem);

	virtual bool   Init() override;
	virtual uint32 Run()  override;
	virtual void   Stop() override;
	void Shutdown();

protected:
	FResRunnable(UDigHumanSubsystem* InSubsystem);
	virtual ~FResRunnable();

private:
	FRunnableThread* ResThread = nullptr;
	UDigHumanSubsystem* Subsystem = nullptr;

	TAtomic<bool> bRunning{ false };
};