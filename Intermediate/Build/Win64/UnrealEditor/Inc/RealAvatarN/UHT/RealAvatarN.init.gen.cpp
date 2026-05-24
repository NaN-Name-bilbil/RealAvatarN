// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRealAvatarN_init() {}
	REALAVATARN_API UFunction* Z_Construct_UDelegateFunction_RealAvatarN_OnCalcViedoFinished__DelegateSignature();
	REALAVATARN_API UFunction* Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioD__DelegateSignature();
	REALAVATARN_API UFunction* Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioF__DelegateSignature();
	REALAVATARN_API UFunction* Z_Construct_UDelegateFunction_RealAvatarN_OnModelLoaded__DelegateSignature();
	REALAVATARN_API UFunction* Z_Construct_UDelegateFunction_RealAvatarN_OnModelReady__DelegateSignature();
	REALAVATARN_API UFunction* Z_Construct_UDelegateFunction_RealAvatarN_OnWavPushFinished__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_RealAvatarN;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_RealAvatarN()
	{
		if (!Z_Registration_Info_UPackage__Script_RealAvatarN.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_RealAvatarN_OnCalcViedoFinished__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioD__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioF__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_RealAvatarN_OnModelLoaded__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_RealAvatarN_OnModelReady__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_RealAvatarN_OnWavPushFinished__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/RealAvatarN",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0xF9621AE7,
				0x6EBE50AB,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_RealAvatarN.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_RealAvatarN.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_RealAvatarN(Z_Construct_UPackage__Script_RealAvatarN, TEXT("/Script/RealAvatarN"), Z_Registration_Info_UPackage__Script_RealAvatarN, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xF9621AE7, 0x6EBE50AB));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
