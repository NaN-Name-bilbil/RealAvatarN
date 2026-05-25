// Copyright NaNName, Inc. All Rights Reserved.


using System;
using System.IO;
using UnrealBuildTool;

public class RealAvatarN : ModuleRules
{
    // In earlier UE versions (such as 4.27), the architecture string is empty.
    protected string ArchitectureString
    {
        get
        {
            if (Target.Architecture.ToString().Length > 0)
            {
                return Target.Architecture.ToString();
            }
            else
            {
                return "x64";
            }
        }
    }

    protected void LoadOnnxRuntime()
    {
        string PlatformDir = Target.Platform.ToString();
        string IncDirPath = Path.Combine(ModuleDirectory, "..", "ThirdParty", "onnxruntime", "Include");
        string LibDirPath = "";
        string RelativeLibDirPath = "";
        string SharedLibFileName = "UNSUPPORTED_PLATFORM";

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            //拷贝一下model文件夹
            string PluginDir = Path.GetFullPath(Path.Combine(ModuleDirectory, "../../"));
            string ModelDir = Path.Combine(PluginDir, "Model");

            if (Directory.Exists(ModelDir))
            {
                foreach (string FilePath in Directory.GetFiles(
                    ModelDir,
                    "*",
                    SearchOption.AllDirectories))
                {
                    string RelativePath = FilePath.Substring(ModelDir.Length + 1);
                    System.Console.WriteLine("model文件夹:" + FilePath);
                    RuntimeDependencies.Add(
                        FilePath
                    );
                }
            }

            // Build.cs 中
            PublicIncludePaths.Add(IncDirPath);
            RelativeLibDirPath = Path.Combine("..", "ThirdParty", "onnxruntime", "Lib", PlatformDir, "onnxruntime", ArchitectureString);
            LibDirPath = Path.Combine(ModuleDirectory, RelativeLibDirPath);



            PublicAdditionalLibraries.Add(Path.Combine(LibDirPath, "onnxruntime.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(LibDirPath, "onnxruntime_providers_cuda.lib"));

            RuntimeDependencies.Add(Path.Combine(LibDirPath, "onnxruntime.dll"));
            RuntimeDependencies.Add(Path.Combine(LibDirPath, "onnxruntime_providers_shared.dll"));
            RuntimeDependencies.Add(Path.Combine(LibDirPath, "onnxruntime_providers_cuda.dll"));//打包
            RuntimeDependencies.Add(Path.Combine(LibDirPath, "onnxruntime_providers_tensorrt.dll"));//打包

            PublicDelayLoadDLLs.Add(SharedLibFileName);
            // ✅ 延迟加载，防止找不到dll时崩溃
            PublicDelayLoadDLLs.Add("onnxruntime.dll");
            PublicDelayLoadDLLs.Add("onnxruntime_providers_shared.dll");


            string Names = "OpenCV480";

            string IncPath = Path.Combine(ModuleDirectory, "../ThirdParty/" + Names + "/includes");
            string LibPath = Path.Combine(ModuleDirectory, "../ThirdParty/" + Names + "/Libs");
            string LibName = "opencv_world480";

            PublicSystemIncludePaths.Add(IncPath);
            PublicAdditionalLibraries.Add(Path.Combine(LibPath, LibName + ".lib"));

            string DLLName = LibName + ".dll";
            PublicDelayLoadDLLs.Add(DLLName);
            RuntimeDependencies.Add(Path.Combine(LibPath, LibName + ".dll"));
            RuntimeDependencies.Add(Path.Combine(LibPath, "opencv_videoio_ffmpeg480_64.dll"));
            
            //加载tensorrt
            Names = "TensorRT-10.16.1.11";
            PublicDefinitions.Add("ENABLE_FEATURE_DISABLE_RUNTIME_ALLOCATION=0");
            IncPath = Path.Combine(ModuleDirectory, "../ThirdParty/" + Names + "/include");
            LibPath = Path.Combine(ModuleDirectory, "../ThirdParty/" + Names + "/lib");

            PublicSystemIncludePaths.Add(IncPath);
            PublicAdditionalLibraries.Add(Path.Combine(LibPath, "nvinfer_10.lib"));
            PublicDelayLoadDLLs.Add("nvinfer_10.dll");
            RuntimeDependencies.Add(Path.Combine(LibPath, "nvinfer_10.dll"));

            //cuda
            string CudaPath = Environment.GetEnvironmentVariable("CUDA_PATH");
            if (string.IsNullOrEmpty(CudaPath))
            {
                throw new BuildException("❌ CUDA_PATH 环境变量未设置！");
            }
            string IncludePath = Path.Combine(CudaPath, "include");
            LibPath = Path.Combine(CudaPath, "lib", "x64");
            PublicIncludePaths.Add(IncludePath);
            PublicAdditionalLibraries.Add(Path.Combine(LibPath, "cudart.lib"));
            Console.WriteLine("[CUDA] Using CUDA at: " + CudaPath);


            //加载api

            IncPath = Path.Combine(ModuleDirectory, "../Core/include");
            LibPath = Path.Combine(ModuleDirectory, "../Core/lib");
            LibName = "Project1";

            PublicSystemIncludePaths.Add(IncPath);
            PublicAdditionalLibraries.Add(Path.Combine(LibPath, LibName + ".lib"));

            DLLName = LibName + ".dll";
            PublicDelayLoadDLLs.Add(DLLName);
            RuntimeDependencies.Add(Path.Combine(LibPath, LibName + ".dll"));



        }
        else if (Target.Platform == UnrealTargetPlatform.Linux)
        {
            RelativeLibDirPath = Path.Combine("..", "ThirdParty", "onnxruntime", "Lib", PlatformDir, "onnxruntime", ArchitectureString);
            LibDirPath = Path.Combine(ModuleDirectory, RelativeLibDirPath);
            SharedLibFileName = "libonnxruntime.so";
            PublicAdditionalLibraries.Add(Path.Combine(LibDirPath, SharedLibFileName));
            RuntimeDependencies.Add(Path.Combine(LibDirPath, "libonnxruntime.so.1"));
            RuntimeDependencies.Add(Path.Combine(LibDirPath, SharedLibFileName));
            PublicIncludePaths.Add(IncDirPath);
        }
        else if (Target.Platform == UnrealTargetPlatform.Mac)
        {
            RelativeLibDirPath = Path.Combine("..", "ThirdParty", "onnxruntime", "Lib", PlatformDir, "onnxruntime");
            LibDirPath = Path.Combine(ModuleDirectory, RelativeLibDirPath);
            SharedLibFileName = "libonnxruntime.dylib";
            PublicAdditionalLibraries.Add(Path.Combine(LibDirPath, SharedLibFileName));
            RuntimeDependencies.Add(Path.Combine(LibDirPath, "libonnxruntime.1.19.2.dylib"));
            RuntimeDependencies.Add(Path.Combine(LibDirPath, SharedLibFileName));
            PublicIncludePaths.Add(IncDirPath);
        }
        else if (Target.Platform == UnrealTargetPlatform.IOS)
        {
            RelativeLibDirPath = Path.Combine("..", "ThirdParty", "onnxruntime", "Lib", PlatformDir);
            LibDirPath = Path.Combine(ModuleDirectory, RelativeLibDirPath);
            PublicAdditionalFrameworks.Add(
                new Framework(
                    "onnxruntime",
                    "../ThirdParty/Lib/IOS/onnxruntime.embeddedframework.zip"
                )
            );
            PublicIncludePaths.Add(IncDirPath);
        }
        else if (Target.Platform == UnrealTargetPlatform.Android)
        {

            string archx = "arm64-v8a";
            RelativeLibDirPath = Path.Combine("..", "ThirdParty", "onnxruntime", "Lib", PlatformDir, "onnxruntime", archx);

            LibDirPath = Path.Combine(ModuleDirectory, RelativeLibDirPath);
            System.Console.WriteLine("!!!!!!!!!!!!!!!!!!!!!!!!!!" + LibDirPath);
            SharedLibFileName = "libonnxruntime.so";

            // 1️⃣ 头文件
            PublicIncludePaths.Add(IncDirPath);

            // 2️⃣ 链接so（关键）
            PublicAdditionalLibraries.Add(Path.Combine(LibDirPath, SharedLibFileName));

            // 3️⃣ 打包进APK（关键）
            RuntimeDependencies.Add(Path.Combine(LibDirPath, SharedLibFileName));

            // 4️⃣ 告诉UE这是Android so
            AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(ModuleDirectory, "OnnxRuntime_UPL.xml"));
        }

        string RelativeSharedLibPath = Path.Combine(RelativeLibDirPath, SharedLibFileName).Replace('\\', '/');
        PublicDefinitions.Add("ORT_API_MANUAL_INIT");
        if (Target.Type != TargetType.Editor)
        {
            PublicDefinitions.Add("ORT_NO_EXCEPTIONS");
        }

        PublicDefinitions.Add("ONNXRUNTIME_SHAREDLIB_PATH_TTS=" + RelativeSharedLibPath);
    }
    // 封装一个复制整个文件夹的方法
    private void CopyFolder(string sourceDir, string targetDir)
    {
        if (!Directory.Exists(sourceDir))
        {
            System.Console.WriteLine("警告: 目录不存在 - " + sourceDir);
            return;
        }

        foreach (string filePath in Directory.GetFiles(sourceDir, "*", SearchOption.AllDirectories))
        {
            // 计算相对路径，保持目录结构
            string relativePath = filePath.Substring(sourceDir.Length + 1);
            string destPath = Path.Combine(targetDir, relativePath);

            RuntimeDependencies.Add(destPath, filePath);
        }
    }

    public RealAvatarN(ReadOnlyTargetRules Target) : base(Target)
    {
        PrivateDependencyModuleNames.AddRange(new string[] { "AnimGraphRuntime", "Projects" });
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bEnableExceptions = true;
        string ThirdPartyDirectory = Path.Combine(ModuleDirectory, "..", "ThirdParty");
        PublicIncludePaths.Add(Path.Combine(ThirdPartyDirectory, "Include"));
        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "UMG", "Json", "JsonUtilities" , "RHI",
            "RenderCore",
            "Renderer",
            "AudioMixer",
            "AudioCaptureCore",

        });

        string pluginDir = Path.GetFullPath(Path.Combine(ModuleDirectory, "../../"));
        string modelSourceDir = Path.Combine(pluginDir, "Model");

        // 从 Target 动态获取项目目录，拼出打包输出路径
        string projectDir = Target.ProjectFile.Directory.FullName;
        string archiveDir = Path.Combine(projectDir, "pack", "Windows", "EmptyProject");
        string modelTarget = Path.Combine(archiveDir, "Plugins", "RealAvatarN", "Model");

        // 只在打包时执行（非编辑器构建）
        if (Target.Type != TargetType.Editor)
        {
            //CopyFolder(modelSourceDir, modelTarget);
        }


        LoadOnnxRuntime();
    }
}
