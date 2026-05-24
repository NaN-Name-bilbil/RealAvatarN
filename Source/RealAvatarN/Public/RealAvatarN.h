// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FRealAvatarNModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	void* Avatar_Handler = nullptr;

protected:

	void* OpenCV_World_Handler = nullptr;
	void* TensorRT_Handler = nullptr;

private:
	void* OrtSharedLibHandle = nullptr;
	void* OrtSharedHandle = nullptr;
	void* OrtCudaHandle = nullptr;
	void* OrtTensorRTHandle = nullptr;
};
