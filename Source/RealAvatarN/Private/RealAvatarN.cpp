// Copyright Epic Games, Inc. All Rights Reserved.

#include "RealAvatarN.h"
#include <onnxruntime_cxx_api.h>

#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/Paths.h"
#define LOCTEXT_NAMESPACE "FRealAvatarNModule"

void FRealAvatarNModule::StartupModule()

{

    FString PluginDir = IPluginManager::Get().FindPlugin("RealAvatarN")->GetBaseDir();

    // ORT dll 所在目录
    FString OrtSharedLibFilePath = FPaths::Combine(PluginDir,
        TEXT("Source"), TEXT("RealAvatarN"),
        TEXT(PREPROCESSOR_TO_STRING(ONNXRUNTIME_SHAREDLIB_PATH_TTS)));
    FString OrtDllDir = FPaths::GetPath(OrtSharedLibFilePath);

    UE_LOG(LogTemp, Warning, TEXT("ORT dll dir: %s"), *OrtDllDir);

    // ✅ 按依赖顺序逐个加载，shared 必须最先加载
    struct FDllEntry { FString Name; void** Handle; };

    TArray<FDllEntry> DllsToLoad = {

        { TEXT("onnxruntime_providers_shared.dll"),   &OrtSharedHandle        },
        { TEXT("onnxruntime.dll"),                    &OrtSharedLibHandle     },

    };

    for (auto& Entry : DllsToLoad)
    {
        FString FullPath = FPaths::Combine(OrtDllDir, Entry.Name);
        *Entry.Handle = FPlatformProcess::GetDllHandle(*FullPath);

        if (*Entry.Handle) {
            UE_LOG(LogTemp, Warning, TEXT("✅ Loaded: %s"), *Entry.Name);
        }
        else
            UE_LOG(LogTemp, Error, TEXT("❌ Failed: %s"), *Entry.Name);
    }


    FString LibraryPath = FPaths::Combine(*PluginDir, TEXT("Source/ThirdParty/OpenCV480/Libs/opencv_world480.dll"));
    OpenCV_World_Handler = FPlatformProcess::GetDllHandle(*LibraryPath);

    if (!OpenCV_World_Handler)
    {
        UE_LOG(LogTemp, Error, TEXT("OpenCV_error"));
    }
    else
    {
        UE_LOG(LogTemp, Display, TEXT("OpenCV_success"));
    }

    LibraryPath = FPaths::Combine(*PluginDir, TEXT("Source/ThirdParty/TensorRT-10.16.1.11/lib/nvinfer_10.dll"));
    TensorRT_Handler = FPlatformProcess::GetDllHandle(*LibraryPath);
    UE_LOG(LogTemp, Warning, TEXT("LibraryPath dll dir: %s"), *LibraryPath);
    if (!TensorRT_Handler)
    {
        UE_LOG(LogTemp, Error, TEXT("TensorRT_error"));
    }
    else
    {
        UE_LOG(LogTemp, Display, TEXT("TensorRT_success"));
    }


    OrtSharedLibFilePath = FPaths::Combine(PluginDir, TEXT("Source"), TEXT("Core"), TEXT("lib"));
    Avatar_Handler = FPlatformProcess::GetDllHandle(*FPaths::Combine(OrtSharedLibFilePath, TEXT("Project1.dll")));
    if (!Avatar_Handler)
    {
        UE_LOG(LogTemp, Error, TEXT("Avatar_Handler_error"));
    }
    else
    {


    }


	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FRealAvatarNModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

    if (Avatar_Handler)
    {
        FPlatformProcess::FreeDllHandle(Avatar_Handler);
        Avatar_Handler = nullptr;
    }

    if (OpenCV_World_Handler)
    {
        FPlatformProcess::FreeDllHandle(OpenCV_World_Handler);
        OpenCV_World_Handler = nullptr;
    }
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FRealAvatarNModule, RealAvatarN)