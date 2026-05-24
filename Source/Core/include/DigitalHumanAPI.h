#pragma once

#ifdef _WIN32
#ifdef DH_EXPORTS
#define DH_API __declspec(dllexport)
#else
#define DH_API __declspec(dllimport)
#endif
#else
#define DH_API
#endif

#include <stdbool.h>

// 输出结果结构体（供 UE5 消费）
struct DHInferenceResult {
    unsigned char* ImageData; // BGRA 图像数据指针
    int ImageWidth;
    int ImageHeight;
    int ImageChannels;        // 固定为 4 (BGRA)

    float* AudioPCMData;      // 对应的音频数据指针
    int AudioSamplesCount;    // 音频采样点数量
};

class DH_API IDigitalHumanEngine {
public:
    virtual ~IDigitalHumanEngine() = default;

    // 1. 初始化模型 (DNet, BNF, PFPLD, SCRFD)
    virtual bool InitModels(
        const char* licenseKey,
        const char* maskDir,
        bool useTensorRT,
        bool useFP16,
        int batchSize) = 0;

    // 2. 预处理视频 (提取帧、人脸检测、Crop)
    virtual bool PreprocessVideo(int video_type,const char* videoPath) = 0;

    // 3. 推入音频 PCM 采样 (float, 16000Hz, 单声道)
    virtual void PushAudioSamples(const float* pcmData, int sampleCount) = 0;

    virtual void ChangeVideoStatue(int statue) = 0;

    // 4. 驱动核心 Tick (建议在后台线程死循环调用)
    // 内部会消耗 Audio，进行 BNF 和 DNet 批处理推理，并将结果压入输出队列
    virtual void TickRealtime() = 0;

    // 5. 弹出结果 (建议在 UE 的 GameThread / Tick 中调用)
    // UE5 拿到 Result 后，去 Update UTexture2D 和 SoundWave
    // 返回 true 表示成功拿到一帧数据
    virtual bool PopResult(DHInferenceResult& outResult) = 0;

    // 6. 释放 PopResult 返回的内部内存（非常重要，防止内存泄漏）
    virtual void FreeResult(DHInferenceResult& result) = 0;

    // 7. 判断视频预处理是否完成
    virtual bool IsReady() const = 0;

    virtual bool ComputeVideoFromFile(const char* WavPath, const char* VideoPath, const char* OutPutVideoPath) = 0;
};
// -------------------------------------------------------
// 日志回调类型
//   level : 0 = Info, 1 = Warning, 2 = Error
//   msg   : 已格式化的 UTF-8 字符串
// -------------------------------------------------------
typedef void (*DHLogCallback)(int level, const char* msg);
// C 风格工厂函数
extern "C" {
    DH_API IDigitalHumanEngine* CreateDigitalHumanEngine(DHLogCallback callback);
    DH_API void DestroyDigitalHumanEngine(IDigitalHumanEngine* engine);

}