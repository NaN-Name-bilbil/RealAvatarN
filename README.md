<div align="center">

<img width="80" src="https://img.shields.io/badge/-RealAvatarN-1D9E75?style=flat&logoColor=white" />

# RealAvatarN

**自主实现的 Unreal Engine 数字人插件 · 实时流式口型推理 · 动态视频无缝切换**

*An Original C++ UE Plugin for AI-Driven Digital Humans — Real-time Streaming Lip-Sync & Dynamic Video Transition*

---

[![UE Version](https://img.shields.io/badge/Unreal%20Engine-4.27%20–%205.7-1D9E75?style=flat-square&logo=unrealengine&logoColor=white)](https://www.unrealengine.com)
[![Platform](https://img.shields.io/badge/Platform-Windows%20x64-0078D6?style=flat-square&logo=windows&logoColor=white)]()
[![Model From](https://img.shields.io/badge/Model%20From-DUIX.COM%20%2F%20HeyGem-9B59B6?style=flat-square)](https://github.com/GuijiAI/HeyGem.ai)
[![ONNX](https://img.shields.io/badge/ONNX%20Runtime-GPU%201.19.2-FF6B35?style=flat-square)]()
[![TensorRT](https://img.shields.io/badge/TensorRT-10.x-76B900?style=flat-square&logo=nvidia&logoColor=white)]()

</div>

---

## 📖 项目介绍 / Introduction

**RealAvatarN** 是一款为 Unreal Engine 自主设计开发的数字人插件，参考 [HeyGem](https://github.com/GuijiAI/HeyGem.ai) 的技术框架思路，从零以 C++ 重新实现了完整的推理管线，并使用了 DUIX.COM / HeyGem 提供的模型权重。插件将 AI 驱动的实时口型同步能力与 UE 渲染管线深度融合，封装为简洁的蓝图（Blueprint）与 C++ 接口，开发者无需关心底层细节即可快速构建高质量的交互式数字人应用。

**RealAvatarN** is a self-developed Unreal Engine plugin for digital humans, independently implemented in C++ from the ground up — inspired by the technical framework of [HeyGem](https://github.com/GuijiAI/HeyGem.ai), with model weights sourced from DUIX.COM / HeyGem. The entire inference pipeline has been rewritten natively in C++ and deeply integrated with UE's rendering pipeline, exposing clean Blueprint and C++ APIs so developers can build high-quality interactive digital human applications without touching low-level details.

---

## ✨ 核心功能 / Key Features

| 功能 / Feature | 说明 / Description |
|---|---|
| 🎙️ **本地离线实时流式推理** Local Offline Real-time Streaming | 纯本地推理，无需联网，逐帧流式输出口型驱动数据，低延迟连续对话 / Fully local & offline inference, no network required, frame-by-frame streaming with ultra-low latency |
| 👄 **视频口型同步** Video Lip Sync | C++ 自实现推理管线精准驱动视频序列口型，表情自然还原 / Accurate lip-sync on video sequences via self-implemented C++ inference pipeline |
| 🔀 **动态视频过渡** Dynamic Transition | 待机、说话、过渡段无缝切换，消除画面割裂感 / Seamless switching between idle/talk/transition clips |
| 🔧 **蓝图 & C++ 双支持** Blueprint & C++ | 设计师与程序员均可上手，接口完整暴露 / Full API access for both designers and engineers |
| 🖥️ **全版本兼容** Wide UE Compatibility | 支持 UE 4.27 至 UE 5.7，覆盖主流商业及最新版本 / UE 4.27 through 5.7 supported |

---

## ⚡ 性能参考 / Performance Reference

> 测试机器 / Test machine: **i5-13600K + RTX A5000 (24GB) + RAM 64GB**

| 推理模式 / Inference Mode | 平均延迟 / Avg Latency | 帧率 / FPS |
|---|---|---|
| 纯 ONNX GPU / Pure ONNX GPU | ~55 ms | ~18 fps |
| ONNX + TensorRT | ~27 ms | **~40 fps** ✅ |

> 💡 游戏本 RTX 4060 可运行，实测帧率约 **22 fps**。4K 数字人 RAM **必须 ≥ 32GB**（视频预加载可能占用约 16GB）。
>
> A gaming laptop with RTX 4060 can run this plugin at ~**22 fps**. For 4K avatars, RAM **must be ≥ 32GB** (video preloading may consume ~16GB).

---

## 🖥️ 系统要求 / System Requirements

### 推荐配置 / Recommended

| 组件 / Component | 要求 / Requirement |
|---|---|
| OS | Windows 10/11 x64 |
| CPU | Intel i5-13600K 或同等级 / or equivalent |
| GPU | NVIDIA RTX 3080 / A5000（16GB+ 显存）|
| RAM | 64 GB（4K 数字人必须 / required for 4K avatar）|
| CUDA | 12.8+ |
| cuDNN | 9.7+ |
| TensorRT | 10.1.6.1+ |
| ONNX Runtime | GPU 1.19.2 |

### 运行时依赖 / Runtime Dependencies

在使用插件前，请确保以下环境已正确配置：

Before using the plugin, make sure the following environments are correctly configured:

- **CUDA 12.8+** — [下载 / Download](https://developer.nvidia.com/cuda-downloads)
- **cuDNN 9.7+** — [下载 / Download](https://developer.nvidia.com/cudnn-archive)
- **TensorRT 10.x** — [下载 / Download](https://developer.nvidia.com/tensorrt/download/10x)
- **FFmpeg**（非流式模式必须 / required for non-streaming mode）— [下载 / Download](https://ffmpeg.org/download.html) ，安装后需加入系统环境变量 / add to system PATH
- **Dependencies 工具**（用于排查缺失 DLL / for DLL diagnosis）— [GitHub](https://github.com/lucasg/Dependencies)

---

## 🚀 快速开始 / Quick Start

### 1. 安装插件 / Install Plugin

```bash
# 克隆仓库 / Clone the repository
git clone https://github.com/your-username/RealAvatarN.git

# 将插件目录复制到你的 UE 项目 Plugins 文件夹
# Copy the plugin folder into your UE project's Plugins directory
cp -r RealAvatarN /YourProject/Plugins/
```

### 2. 启用插件 / Enable Plugin

在 UE 编辑器中：**Edit → Plugins → 搜索 `RealAvatarN` → 勾选启用 → 重启编辑器**

In UE Editor: **Edit → Plugins → Search `RealAvatarN` → Enable → Restart Editor**

### 3. 查看 Demo / Check the Demo

插件目录内含完整 Demo，包含详细注释与用法说明，建议首次使用从 Demo 开始了解。

The plugin includes a fully annotated Demo project. First-time users are encouraged to start there.

### 4. 调用蓝图节点 / Call Blueprint Node

插件提供两种驱动模式，按需选择：

The plugin offers two driving modes — choose based on your use case:

**🔴 实时流式模式 / Real-time Streaming Mode**（推荐 / Recommended）

在关卡蓝图中按以下流程调用：

In the Level Blueprint, call in this order:

1. `InitSystemModel` — 初始化系统模型 / Initialize the system model
2. `StartRealtimeDrive` — 初始化并预缓存视频 / Initialize and pre-cache video
3. `PushAudioSamples` — 实时将用户音频推入推理管线 / Push user audio into the inference pipeline in real time

> - 🎙️ 音频格式：**16000 Hz，单声道** / Audio format: **16000 Hz, mono**
> - ⏱️ 推荐按 **10ms / 160 samples** 分段推入 / Recommended chunk size: **10ms / 160 samples**
> - 🖥️ 推理效果与 GPU 性能强相关，请确保运行时帧率 **> 30 fps** / Inference quality is GPU-bound — ensure **> 30 fps** at runtime

---

**🎞️ 传统离线模式 / Traditional Offline Mode**（WAV → 视频输出）

在关卡蓝图中按以下流程调用：

In the Level Blueprint, call in this order:

1. `InitSystemModel` — 初始化系统模型 / Initialize the system model
2. `ComputeVideoFromFile` — 传入 WAV 文件路径，计算并输出口型视频 / Pass a WAV file path to compute and output lip-sync video
3. 绑定 `OnCalcVideoFinished` 回调以获取输出结果 / Bind the `OnCalcVideoFinished` callback to receive the result

> ⚠️ 此模式依赖 **FFmpeg**，请确保已安装并正确配置系统环境变量。
>
> This mode requires **FFmpeg** — make sure it is installed and added to the system PATH.

---

> ⚠️ 插件第一次预加载视频时间较长，属正常现象。
>
> The first-time video preloading may take longer — this is expected behavior.

---

## 🎨 定制数字人形象 / Customize Your Avatar

1. **制作静态形象** — 数字人站立姿势正面图
2. **制作视频素材** — 建议 9:16 比例，4K 以下，MP4 格式，准备两段：
   - `idle`：待机循环视频
   - `talk`：说话驱动视频
3. **视频要求** — 首尾帧保持相同以实现无缝循环；动作幅度较小；**避免侧身**；建议不超过 4K 分辨率
4. **修改配置** — 调整 `Start Realtime Drive` 节点的输入路径，打包时使用相对路径

---

## ⚠️ 注意事项 / Important Notes

> 请在使用前仔细阅读以下事项，避免常见问题。
>
> Please read carefully before use to avoid common issues.

### 模型与授权 / Model & License

- 插件默认使用 `Plugins/RealAvatar/Model/` 目录下的演示模型及视频
- **演示所用的豆包数字人框架需另行购买**：[购买链接](https://www.ifdian.net/item/1871d162443d11f1846d5254001e7c00)
- 为保障插件的持续迭代与技术支持，**RealAvatarN 采用订阅授权制**，获取激活码后方可使用完整功能：[获取授权 / Get License](https://ifdian.net/item/dc71566241d811f18e6552540025c377)
- 💡 **免费试用**：激活码填入 `test` 可领取 **7 天体验授权**，无需付费即可完整体验插件功能

- The plugin uses demo models and videos from `Plugins/RealAvatar/Model/` by default
- **The Doubao digital human framework used in demos must be purchased separately**: [Purchase Link](https://www.ifdian.net/item/1871d162443d11f1846d5254001e7c00)
- To support continued development and maintenance, **RealAvatarN requires a subscription license**. An activation code is needed to unlock full functionality: [Get License](https://ifdian.net/item/dc71566241d811f18e6552540025c377)
- 💡 **Free Trial**: Enter `test` as the activation code to claim a **7-day trial license** — no payment required

### 音频格式 / Audio Format

- 流式音频输入必须为 **PCM 格式，16000Hz，单声道**
- FFmpeg 影响音频合成输出，不影响流式推理模式；安装后须将其加入**系统环境变量**

- Streaming audio input must be **PCM, 16000 Hz, mono**
- FFmpeg affects audio synthesis output only, not streaming mode; must be added to **system PATH** after installation

### 打包注意 / Packaging Notes

- 建议打包时使用**相对路径**，打包后需手动复制模型文件和相关 DLL

- Use **relative paths** when packaging; manually copy model files and DLLs after packaging

  打包后重点检查以下三个目录 / Check these directories after packaging:

  ```
  Plugins\RealAvatar\Source\ThirdParty\onnxruntime\Lib\Win64\onnxruntime\x64
  Windows\YourProject\Binaries\Win64
  Windows\YourProject\Plugins\RealAvatar\Model
  ```

- 若打包后缺少 `onnxruntime_providers_cuda` 等 CUDA DLL，建议将所有涉及的 `.dll` 和 `.lib` 统一复制一遍

- If CUDA DLLs like `onnxruntime_providers_cuda` are missing after packaging, copy all relevant `.dll` and `.lib` files manually

### 首次编译报错 / First Build Error

若首次 Build 出现以下错误：

If you see this error on first build:

```
Unable to load library: nvinfer_builder_resource_sm89_10.dll
```

解决方案 / Solution：从 TensorRT 安装包中找到对应 DLL，复制到以下任一目录：

Find the DLL from your TensorRT installation and copy it to either:

```
YourProject\Binaries\Win64
C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v11.8\bin
```

### 插件冲突 / Plugin Conflicts

以下插件与 RealAvatarN 存在 DLL 冲突（均加载了 `onnxruntime.dll`），**使用 RealAvatarN 时需在插件管理器中禁用它们并重启编辑器**：

The following plugins conflict with RealAvatarN (all load `onnxruntime.dll`). **Disable them in the Plugin Manager and restart the editor when using RealAvatarN**:

- `QTTS`
- MetaHuman 系列 / MetaHuman series
- `NNE`（UE 5.5 及以上 / UE 5.5 and above）

### 编辑器 CPU 占用 / Editor CPU Usage

在编辑器打开状态下运行时，CPU 占用较低，可能影响数字人推理性能。

解决方案：**编辑器偏好设置 → 取消勾选"在后台使用较少 CPU"**

When running with the editor open, low CPU allocation may affect inference performance.

Fix: **Editor Preferences → Uncheck "Use Less CPU when in Background"**

### TensorRT 不稳定 / TensorRT Instability

若遇到 TensorRT 运行不稳定，可参考以下步骤优化：

If TensorRT runs unstably, follow these steps:

1. 锁定 GPU 最大时钟频率 / Lock GPU max clock frequency
2. NVIDIA 控制面板 → 管理 3D 设置 → 低延迟模式设为**超高** / Set Low Latency Mode to **Ultra**
3. 电源管理模式设为**最高性能优先** / Set Power Management Mode to **Prefer Maximum Performance**
4. 保存并**重启电脑** / Save and **restart your PC**

参考 / Reference：[CSDN 教程](https://blog.csdn.net/qq_42944019/article/details/126857775)

---

## 📦 环境依赖版本 / Dependency Versions

```
ONNX Runtime GPU  :  1.19.2
CUDA              :  12.8+
cuDNN             :  9.7+
TensorRT          :  10.1.6.1+
FFmpeg            :  Latest stable
```

| 下载资源 / Downloads | 链接 / Link |
|---|---|
| cuDNN Archive | https://developer.nvidia.com/cudnn-archive |
| TensorRT 10.x | https://developer.nvidia.com/tensorrt/download/10x |
| FFmpeg | https://ffmpeg.org/download.html |
| Dependencies (DLL 工具) | https://github.com/lucasg/Dependencies |

---

## 🔗 兼容性 / Compatibility

| UE 版本 | Windows | Linux | macOS |
|---|---|---|---|
| UE 4.27 | ✅ | ❌ 暂不支持 | ❌ 暂不支持 |
| UE 5.0 – 5.3 | ✅ | ❌ 暂不支持 | ❌ 暂不支持 |
| UE 5.4 – 5.7 | ✅ | ❌ 暂不支持 | ❌ 暂不支持 |

> 目前仅支持 **Windows x64** 平台。Linux / macOS 支持计划后续评估。
>
> Currently **Windows x64** only. Linux / macOS support is not available at this time.

---

## 📜 开源协议 & 致谢 / License & Credits

> **Model weights provided by [DUIX.COM](https://www.duix.com) / [HeyGem](https://github.com/GuijiAI/HeyGem.ai) · Built with DUIX.COM**

本插件的推理代码为**自主 C++ 实现**，框架设计参考了 HeyGem 的技术思路，模型权重来源于 DUIX.COM / HeyGem，受 **DUIX.COM Community License** 约束。

根据该协议，本插件的所有使用者和分发者须注意：

1. 随附 [LICENSE](./LICENSE) 文件副本
2. 在相关页面或文档中醒目标注 **"Built with DUIX.COM"**
3. 在最终用户协议中说明产品集成了 DUIX.COM 技术
4. 若产品月活跃用户超过 **1,000 人**，需向 DUIX.COM 申请商业授权

---

The inference code in this plugin is an **original C++ implementation**, inspired by HeyGem's technical framework. Model weights are sourced from DUIX.COM / HeyGem and are subject to the **DUIX.COM Community License**.

By using or distributing this plugin, you agree to:

1. Include a copy of the [LICENSE](./LICENSE) file
2. Prominently display **"Built with DUIX.COM"** on any related website, UI, or documentation
3. State in your end-user agreements that the product incorporates DUIX.COM technology
4. If Monthly Active Users exceed **1,000**, request a commercial license from DUIX.COM

Full license: [DUIX.COM Community License](https://github.com/GuijiAI/HeyGem.ai/blob/main/LICENSE)

---

<div align="center">

Made with ♥ for the UE Digital Human Community

[📺 B站教程](https://space.bilibili.com/349004635?spm_id_from=333.1007.0.0) · [📖 Wiki 文档](#) · [🐛 Issues](../../issues) · [💬 Discussions](../../discussions)

</div>
