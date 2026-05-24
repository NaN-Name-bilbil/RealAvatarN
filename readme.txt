使用教程：
把对应版本的RealAvatarN插件放入项目工程下的Plugins文件夹，然后启动ue，在editor界面进入项目目录，demo有详细解释和用法

特别事项：
1，插件默认使用插件目录下的Model目录的演示的模型和视频。(演示的豆包数字人框架请另购)
https://www.ifdian.net/item/1871d162443d11f1846d5254001e7c00
2，打包建议是用相对路径，然后打包后需要手动复制模型和dll（详见环境配置）
3，流式音频输入需要保持pcm格式为16000hz单声道。
4，直播可以用用官方的webrtc流，或者直播间插件
5，数字人视频建议首尾帧循环，不大于4k，动作幅度较小，避免侧身！！！
6.！！需要自己安装ffmpeg同时要在系统的环境变量添加（影响音频合成输出，不影响流式模式）
7.如果第一次build出现 (Unable to load library: nvinfer_builder_resource_sm89_10.dll:，可根据下载地址，tensorrt下载后找到对应dll，然后复制到项目的Binaries\Win64文件夹，或者C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v11.8\bin在配置cuda环境的时候一同复制好，即解决
8.插件会和QTTS打架需要在插件中关了重启，包括加载了onnxruntime.dll的插件例如：metahuman 系列和NNE（ue5.5以上）
9.当在编译器打开时，cpu占用会小，影响数字人口型推理，可以在“编辑器偏好设置”里面找到使用较少cpu给去掉

定制自己的数字人形象：
1.制作数字人静态形象站立姿势图  -  制作2个数字人视频（建议9：16 4k以下 mp4）（待机idle和talk说话）（需要保持首尾帧相同）
2.修改start realtime drive的输入，插件第一次预加载视频比较久，打包记得放到相对路径和命名

环境配置：
cpu：i5-13600k； gpu ：RTX A5000/3080（24g/16g） ；RAM: 64GB(4k数字人必须)
我的游戏本4060也能跑

环境配置：
onnxruntime -gpu-1.19.2 : cuda12.8+ cudnn9.7 +tensorRT 10.16.1.11

下载地址：
https://developer.nvidia.com/cudnn-archive
https://github.com/lucasg/Dependencies?tab=readme-ov-file
https://developer.nvidia.com/rdp/cudnn-archive
https://developer.nvidia.com/tensorrt/download/10x
https://ffmpeg.org/download.html

win64打包，经常会少dll。
（onnxruntime_providers_cuda等等cuda的dll推荐上面版本，把涉及到的dll lib都拷贝一遍）
测试用机是a5000 i5-13代，纯onnx gpu延迟为平均55ms，上了tensortrt之后平均27ms，大概是40fps，很快

下面三个目录打包后重点检查
Plugins\RealAvatar\Source\ThirdParty\onnxruntime\Lib\Win64\onnxruntime\x64
Windows\EmptyProject\Binaries\Win64
Windows\EmptyProject\Plugins\RealAvatar\Model（模型记得也复制一遍）

tensorrt不稳定：https://blog.csdn.net/qq_42944019/article/details/126857775
首先锁死最大时钟频率，然后设置NVIDIA控制面板的管理3D设置中的低延时模式为超高，设置电源管理模式为最高性能优先，保存应用，最后需要重启电脑。