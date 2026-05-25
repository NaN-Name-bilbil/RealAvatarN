// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRealAvatarN_init() {}
	REALAVATARN_API UFunction* Z_Construct_UDelegateFunction_RealAvatarN_OnModelLoaded__DelegateSignature();
	REALAVATARN_API UFunction* Z_Construct_UDelegateFunction_RealAvatarN_OnModelReady__DelegateSignature();
	REALAVATARN_API UFunction* Z_Construct_UDelegateFunction_RealAvatarN_OnCalcViedoFinished__DelegateSignature();
	REALAVATARN_API UFunction* Z_Construct_UDelegateFunction_RealAvatarN_OnWavPushFinished__DelegateSignature();
	REALAVATARN_API UFunction* Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioD__DelegateSignature();
	REALAVATARN_API UFunction* Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioF__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_RealAvatarN()
	{
		static UPackage* ReturnPackage = nullptr;
		if (!ReturnPackage)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_RealAvatarN_OnModelLoaded__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_RealAvatarN_OnModelReady__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_RealAvatarN_OnCalcViedoFinished__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_RealAvatarN_OnWavPushFinished__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioD__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioF__DelegateSignature,
			};
			static const UE4CodeGen_Private::FPackageParams PackageParams = {
				"/Script/RealAvatarN",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x799BDE2A,
				0x533B44FD,
				METADATA_PARAMS(nullptr, 0)
			};
			UE4CodeGen_Private::ConstructUPackage(ReturnPackage, PackageParams);
		}
		return ReturnPackage;
	}
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
