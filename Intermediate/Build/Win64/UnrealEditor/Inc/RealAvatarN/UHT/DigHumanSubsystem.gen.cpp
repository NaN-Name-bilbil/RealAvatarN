// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RealAvatarN/Public/DigHumanSubsystem.h"
#include "Runtime/Engine/Classes/Engine/GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDigHumanSubsystem() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UAudioComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
ENGINE_API UClass* Z_Construct_UClass_USoundWaveProcedural_NoRegister();
REALAVATARN_API UClass* Z_Construct_UClass_UDigHumanSubsystem();
REALAVATARN_API UClass* Z_Construct_UClass_UDigHumanSubsystem_NoRegister();
REALAVATARN_API UFunction* Z_Construct_UDelegateFunction_RealAvatarN_OnCalcViedoFinished__DelegateSignature();
REALAVATARN_API UFunction* Z_Construct_UDelegateFunction_RealAvatarN_OnModelLoaded__DelegateSignature();
REALAVATARN_API UFunction* Z_Construct_UDelegateFunction_RealAvatarN_OnModelReady__DelegateSignature();
REALAVATARN_API UFunction* Z_Construct_UDelegateFunction_RealAvatarN_OnWavPushFinished__DelegateSignature();
UMG_API UClass* Z_Construct_UClass_UImage_NoRegister();
UPackage* Z_Construct_UPackage__Script_RealAvatarN();
// End Cross Module References

// Begin Delegate FOnModelLoaded
struct Z_Construct_UDelegateFunction_RealAvatarN_OnModelLoaded__DelegateSignature_Statics
{
	struct _Script_RealAvatarN_eventOnModelLoaded_Parms
	{
		bool result;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DigHumanSubsystem.h" },
	};
#endif // WITH_METADATA
	static void NewProp_result_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_result;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UDelegateFunction_RealAvatarN_OnModelLoaded__DelegateSignature_Statics::NewProp_result_SetBit(void* Obj)
{
	((_Script_RealAvatarN_eventOnModelLoaded_Parms*)Obj)->result = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_RealAvatarN_OnModelLoaded__DelegateSignature_Statics::NewProp_result = { "result", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_RealAvatarN_eventOnModelLoaded_Parms), &Z_Construct_UDelegateFunction_RealAvatarN_OnModelLoaded__DelegateSignature_Statics::NewProp_result_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_RealAvatarN_OnModelLoaded__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_RealAvatarN_OnModelLoaded__DelegateSignature_Statics::NewProp_result,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_RealAvatarN_OnModelLoaded__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_RealAvatarN_OnModelLoaded__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_RealAvatarN, nullptr, "OnModelLoaded__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_RealAvatarN_OnModelLoaded__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_RealAvatarN_OnModelLoaded__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_RealAvatarN_OnModelLoaded__DelegateSignature_Statics::_Script_RealAvatarN_eventOnModelLoaded_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_RealAvatarN_OnModelLoaded__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_RealAvatarN_OnModelLoaded__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_RealAvatarN_OnModelLoaded__DelegateSignature_Statics::_Script_RealAvatarN_eventOnModelLoaded_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_RealAvatarN_OnModelLoaded__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_RealAvatarN_OnModelLoaded__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnModelLoaded_DelegateWrapper(const FMulticastScriptDelegate& OnModelLoaded, bool result)
{
	struct _Script_RealAvatarN_eventOnModelLoaded_Parms
	{
		bool result;
	};
	_Script_RealAvatarN_eventOnModelLoaded_Parms Parms;
	Parms.result=result ? true : false;
	OnModelLoaded.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnModelLoaded

// Begin Delegate FOnModelReady
struct Z_Construct_UDelegateFunction_RealAvatarN_OnModelReady__DelegateSignature_Statics
{
	struct _Script_RealAvatarN_eventOnModelReady_Parms
	{
		bool result;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DigHumanSubsystem.h" },
	};
#endif // WITH_METADATA
	static void NewProp_result_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_result;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UDelegateFunction_RealAvatarN_OnModelReady__DelegateSignature_Statics::NewProp_result_SetBit(void* Obj)
{
	((_Script_RealAvatarN_eventOnModelReady_Parms*)Obj)->result = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_RealAvatarN_OnModelReady__DelegateSignature_Statics::NewProp_result = { "result", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_RealAvatarN_eventOnModelReady_Parms), &Z_Construct_UDelegateFunction_RealAvatarN_OnModelReady__DelegateSignature_Statics::NewProp_result_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_RealAvatarN_OnModelReady__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_RealAvatarN_OnModelReady__DelegateSignature_Statics::NewProp_result,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_RealAvatarN_OnModelReady__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_RealAvatarN_OnModelReady__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_RealAvatarN, nullptr, "OnModelReady__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_RealAvatarN_OnModelReady__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_RealAvatarN_OnModelReady__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_RealAvatarN_OnModelReady__DelegateSignature_Statics::_Script_RealAvatarN_eventOnModelReady_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_RealAvatarN_OnModelReady__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_RealAvatarN_OnModelReady__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_RealAvatarN_OnModelReady__DelegateSignature_Statics::_Script_RealAvatarN_eventOnModelReady_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_RealAvatarN_OnModelReady__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_RealAvatarN_OnModelReady__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnModelReady_DelegateWrapper(const FMulticastScriptDelegate& OnModelReady, bool result)
{
	struct _Script_RealAvatarN_eventOnModelReady_Parms
	{
		bool result;
	};
	_Script_RealAvatarN_eventOnModelReady_Parms Parms;
	Parms.result=result ? true : false;
	OnModelReady.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnModelReady

// Begin Delegate FOnCalcViedoFinished
struct Z_Construct_UDelegateFunction_RealAvatarN_OnCalcViedoFinished__DelegateSignature_Statics
{
	struct _Script_RealAvatarN_eventOnCalcViedoFinished_Parms
	{
		bool result;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DigHumanSubsystem.h" },
	};
#endif // WITH_METADATA
	static void NewProp_result_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_result;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UDelegateFunction_RealAvatarN_OnCalcViedoFinished__DelegateSignature_Statics::NewProp_result_SetBit(void* Obj)
{
	((_Script_RealAvatarN_eventOnCalcViedoFinished_Parms*)Obj)->result = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_RealAvatarN_OnCalcViedoFinished__DelegateSignature_Statics::NewProp_result = { "result", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_RealAvatarN_eventOnCalcViedoFinished_Parms), &Z_Construct_UDelegateFunction_RealAvatarN_OnCalcViedoFinished__DelegateSignature_Statics::NewProp_result_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_RealAvatarN_OnCalcViedoFinished__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_RealAvatarN_OnCalcViedoFinished__DelegateSignature_Statics::NewProp_result,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_RealAvatarN_OnCalcViedoFinished__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_RealAvatarN_OnCalcViedoFinished__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_RealAvatarN, nullptr, "OnCalcViedoFinished__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_RealAvatarN_OnCalcViedoFinished__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_RealAvatarN_OnCalcViedoFinished__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_RealAvatarN_OnCalcViedoFinished__DelegateSignature_Statics::_Script_RealAvatarN_eventOnCalcViedoFinished_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_RealAvatarN_OnCalcViedoFinished__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_RealAvatarN_OnCalcViedoFinished__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_RealAvatarN_OnCalcViedoFinished__DelegateSignature_Statics::_Script_RealAvatarN_eventOnCalcViedoFinished_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_RealAvatarN_OnCalcViedoFinished__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_RealAvatarN_OnCalcViedoFinished__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnCalcViedoFinished_DelegateWrapper(const FMulticastScriptDelegate& OnCalcViedoFinished, bool result)
{
	struct _Script_RealAvatarN_eventOnCalcViedoFinished_Parms
	{
		bool result;
	};
	_Script_RealAvatarN_eventOnCalcViedoFinished_Parms Parms;
	Parms.result=result ? true : false;
	OnCalcViedoFinished.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnCalcViedoFinished

// Begin Delegate FOnWavPushFinished
struct Z_Construct_UDelegateFunction_RealAvatarN_OnWavPushFinished__DelegateSignature_Statics
{
	struct _Script_RealAvatarN_eventOnWavPushFinished_Parms
	{
		bool result;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DigHumanSubsystem.h" },
	};
#endif // WITH_METADATA
	static void NewProp_result_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_result;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UDelegateFunction_RealAvatarN_OnWavPushFinished__DelegateSignature_Statics::NewProp_result_SetBit(void* Obj)
{
	((_Script_RealAvatarN_eventOnWavPushFinished_Parms*)Obj)->result = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_RealAvatarN_OnWavPushFinished__DelegateSignature_Statics::NewProp_result = { "result", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_RealAvatarN_eventOnWavPushFinished_Parms), &Z_Construct_UDelegateFunction_RealAvatarN_OnWavPushFinished__DelegateSignature_Statics::NewProp_result_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_RealAvatarN_OnWavPushFinished__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_RealAvatarN_OnWavPushFinished__DelegateSignature_Statics::NewProp_result,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_RealAvatarN_OnWavPushFinished__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_RealAvatarN_OnWavPushFinished__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_RealAvatarN, nullptr, "OnWavPushFinished__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_RealAvatarN_OnWavPushFinished__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_RealAvatarN_OnWavPushFinished__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_RealAvatarN_OnWavPushFinished__DelegateSignature_Statics::_Script_RealAvatarN_eventOnWavPushFinished_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_RealAvatarN_OnWavPushFinished__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_RealAvatarN_OnWavPushFinished__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_RealAvatarN_OnWavPushFinished__DelegateSignature_Statics::_Script_RealAvatarN_eventOnWavPushFinished_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_RealAvatarN_OnWavPushFinished__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_RealAvatarN_OnWavPushFinished__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnWavPushFinished_DelegateWrapper(const FMulticastScriptDelegate& OnWavPushFinished, bool result)
{
	struct _Script_RealAvatarN_eventOnWavPushFinished_Parms
	{
		bool result;
	};
	_Script_RealAvatarN_eventOnWavPushFinished_Parms Parms;
	Parms.result=result ? true : false;
	OnWavPushFinished.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnWavPushFinished

// Begin Class UDigHumanSubsystem Function ChangeAvatarStatue
struct Z_Construct_UFunction_UDigHumanSubsystem_ChangeAvatarStatue_Statics
{
	struct DigHumanSubsystem_eventChangeAvatarStatue_Parms
	{
		int32 statue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "DigHuman" },
		{ "ModuleRelativePath", "Public/DigHumanSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_statue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDigHumanSubsystem_ChangeAvatarStatue_Statics::NewProp_statue = { "statue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DigHumanSubsystem_eventChangeAvatarStatue_Parms, statue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDigHumanSubsystem_ChangeAvatarStatue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDigHumanSubsystem_ChangeAvatarStatue_Statics::NewProp_statue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDigHumanSubsystem_ChangeAvatarStatue_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDigHumanSubsystem_ChangeAvatarStatue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDigHumanSubsystem, nullptr, "ChangeAvatarStatue", nullptr, nullptr, Z_Construct_UFunction_UDigHumanSubsystem_ChangeAvatarStatue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDigHumanSubsystem_ChangeAvatarStatue_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDigHumanSubsystem_ChangeAvatarStatue_Statics::DigHumanSubsystem_eventChangeAvatarStatue_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDigHumanSubsystem_ChangeAvatarStatue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDigHumanSubsystem_ChangeAvatarStatue_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UDigHumanSubsystem_ChangeAvatarStatue_Statics::DigHumanSubsystem_eventChangeAvatarStatue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDigHumanSubsystem_ChangeAvatarStatue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDigHumanSubsystem_ChangeAvatarStatue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDigHumanSubsystem::execChangeAvatarStatue)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_statue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ChangeAvatarStatue(Z_Param_statue);
	P_NATIVE_END;
}
// End Class UDigHumanSubsystem Function ChangeAvatarStatue

// Begin Class UDigHumanSubsystem Function ComputeViedoFromFile
struct Z_Construct_UFunction_UDigHumanSubsystem_ComputeViedoFromFile_Statics
{
	struct DigHumanSubsystem_eventComputeViedoFromFile_Parms
	{
		FString WavPath;
		FString VideoPath;
		FString OutPutVideoPath;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "DigHuman" },
		{ "ModuleRelativePath", "Public/DigHumanSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WavPath_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VideoPath_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutPutVideoPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_WavPath;
	static const UECodeGen_Private::FStrPropertyParams NewProp_VideoPath;
	static const UECodeGen_Private::FStrPropertyParams NewProp_OutPutVideoPath;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDigHumanSubsystem_ComputeViedoFromFile_Statics::NewProp_WavPath = { "WavPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DigHumanSubsystem_eventComputeViedoFromFile_Parms, WavPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WavPath_MetaData), NewProp_WavPath_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDigHumanSubsystem_ComputeViedoFromFile_Statics::NewProp_VideoPath = { "VideoPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DigHumanSubsystem_eventComputeViedoFromFile_Parms, VideoPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VideoPath_MetaData), NewProp_VideoPath_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDigHumanSubsystem_ComputeViedoFromFile_Statics::NewProp_OutPutVideoPath = { "OutPutVideoPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DigHumanSubsystem_eventComputeViedoFromFile_Parms, OutPutVideoPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutPutVideoPath_MetaData), NewProp_OutPutVideoPath_MetaData) };
void Z_Construct_UFunction_UDigHumanSubsystem_ComputeViedoFromFile_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((DigHumanSubsystem_eventComputeViedoFromFile_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDigHumanSubsystem_ComputeViedoFromFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DigHumanSubsystem_eventComputeViedoFromFile_Parms), &Z_Construct_UFunction_UDigHumanSubsystem_ComputeViedoFromFile_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDigHumanSubsystem_ComputeViedoFromFile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDigHumanSubsystem_ComputeViedoFromFile_Statics::NewProp_WavPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDigHumanSubsystem_ComputeViedoFromFile_Statics::NewProp_VideoPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDigHumanSubsystem_ComputeViedoFromFile_Statics::NewProp_OutPutVideoPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDigHumanSubsystem_ComputeViedoFromFile_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDigHumanSubsystem_ComputeViedoFromFile_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDigHumanSubsystem_ComputeViedoFromFile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDigHumanSubsystem, nullptr, "ComputeViedoFromFile", nullptr, nullptr, Z_Construct_UFunction_UDigHumanSubsystem_ComputeViedoFromFile_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDigHumanSubsystem_ComputeViedoFromFile_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDigHumanSubsystem_ComputeViedoFromFile_Statics::DigHumanSubsystem_eventComputeViedoFromFile_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDigHumanSubsystem_ComputeViedoFromFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDigHumanSubsystem_ComputeViedoFromFile_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UDigHumanSubsystem_ComputeViedoFromFile_Statics::DigHumanSubsystem_eventComputeViedoFromFile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDigHumanSubsystem_ComputeViedoFromFile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDigHumanSubsystem_ComputeViedoFromFile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDigHumanSubsystem::execComputeViedoFromFile)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_WavPath);
	P_GET_PROPERTY(FStrProperty,Z_Param_VideoPath);
	P_GET_PROPERTY(FStrProperty,Z_Param_OutPutVideoPath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ComputeViedoFromFile(Z_Param_WavPath,Z_Param_VideoPath,Z_Param_OutPutVideoPath);
	P_NATIVE_END;
}
// End Class UDigHumanSubsystem Function ComputeViedoFromFile

// Begin Class UDigHumanSubsystem Function InitSystemModel
struct Z_Construct_UFunction_UDigHumanSubsystem_InitSystemModel_Statics
{
	struct DigHumanSubsystem_eventInitSystemModel_Parms
	{
		FString licenseKey;
		int32 BatchSize;
		UAudioComponent* AudioComponent;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "DigHuman" },
		{ "CPP_Default_AudioComponent", "None" },
		{ "CPP_Default_BatchSize", "1" },
		{ "ModuleRelativePath", "Public/DigHumanSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_licenseKey_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AudioComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_licenseKey;
	static const UECodeGen_Private::FIntPropertyParams NewProp_BatchSize;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AudioComponent;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDigHumanSubsystem_InitSystemModel_Statics::NewProp_licenseKey = { "licenseKey", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DigHumanSubsystem_eventInitSystemModel_Parms, licenseKey), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_licenseKey_MetaData), NewProp_licenseKey_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDigHumanSubsystem_InitSystemModel_Statics::NewProp_BatchSize = { "BatchSize", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DigHumanSubsystem_eventInitSystemModel_Parms, BatchSize), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDigHumanSubsystem_InitSystemModel_Statics::NewProp_AudioComponent = { "AudioComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DigHumanSubsystem_eventInitSystemModel_Parms, AudioComponent), Z_Construct_UClass_UAudioComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AudioComponent_MetaData), NewProp_AudioComponent_MetaData) };
void Z_Construct_UFunction_UDigHumanSubsystem_InitSystemModel_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((DigHumanSubsystem_eventInitSystemModel_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDigHumanSubsystem_InitSystemModel_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DigHumanSubsystem_eventInitSystemModel_Parms), &Z_Construct_UFunction_UDigHumanSubsystem_InitSystemModel_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDigHumanSubsystem_InitSystemModel_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDigHumanSubsystem_InitSystemModel_Statics::NewProp_licenseKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDigHumanSubsystem_InitSystemModel_Statics::NewProp_BatchSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDigHumanSubsystem_InitSystemModel_Statics::NewProp_AudioComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDigHumanSubsystem_InitSystemModel_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDigHumanSubsystem_InitSystemModel_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDigHumanSubsystem_InitSystemModel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDigHumanSubsystem, nullptr, "InitSystemModel", nullptr, nullptr, Z_Construct_UFunction_UDigHumanSubsystem_InitSystemModel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDigHumanSubsystem_InitSystemModel_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDigHumanSubsystem_InitSystemModel_Statics::DigHumanSubsystem_eventInitSystemModel_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDigHumanSubsystem_InitSystemModel_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDigHumanSubsystem_InitSystemModel_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UDigHumanSubsystem_InitSystemModel_Statics::DigHumanSubsystem_eventInitSystemModel_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDigHumanSubsystem_InitSystemModel()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDigHumanSubsystem_InitSystemModel_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDigHumanSubsystem::execInitSystemModel)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_licenseKey);
	P_GET_PROPERTY(FIntProperty,Z_Param_BatchSize);
	P_GET_OBJECT(UAudioComponent,Z_Param_AudioComponent);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->InitSystemModel(Z_Param_licenseKey,Z_Param_BatchSize,Z_Param_AudioComponent);
	P_NATIVE_END;
}
// End Class UDigHumanSubsystem Function InitSystemModel

// Begin Class UDigHumanSubsystem Function IsReady
struct Z_Construct_UFunction_UDigHumanSubsystem_IsReady_Statics
{
	struct DigHumanSubsystem_eventIsReady_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "DigHuman" },
		{ "ModuleRelativePath", "Public/DigHumanSubsystem.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UDigHumanSubsystem_IsReady_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((DigHumanSubsystem_eventIsReady_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDigHumanSubsystem_IsReady_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DigHumanSubsystem_eventIsReady_Parms), &Z_Construct_UFunction_UDigHumanSubsystem_IsReady_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDigHumanSubsystem_IsReady_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDigHumanSubsystem_IsReady_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDigHumanSubsystem_IsReady_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDigHumanSubsystem_IsReady_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDigHumanSubsystem, nullptr, "IsReady", nullptr, nullptr, Z_Construct_UFunction_UDigHumanSubsystem_IsReady_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDigHumanSubsystem_IsReady_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDigHumanSubsystem_IsReady_Statics::DigHumanSubsystem_eventIsReady_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDigHumanSubsystem_IsReady_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDigHumanSubsystem_IsReady_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UDigHumanSubsystem_IsReady_Statics::DigHumanSubsystem_eventIsReady_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDigHumanSubsystem_IsReady()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDigHumanSubsystem_IsReady_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDigHumanSubsystem::execIsReady)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsReady();
	P_NATIVE_END;
}
// End Class UDigHumanSubsystem Function IsReady

// Begin Class UDigHumanSubsystem Function PushAudioSamples
struct Z_Construct_UFunction_UDigHumanSubsystem_PushAudioSamples_Statics
{
	struct DigHumanSubsystem_eventPushAudioSamples_Parms
	{
		TArray<float> InPCM;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "DigHuman" },
		{ "ModuleRelativePath", "Public/DigHumanSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InPCM_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InPCM_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_InPCM;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDigHumanSubsystem_PushAudioSamples_Statics::NewProp_InPCM_Inner = { "InPCM", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDigHumanSubsystem_PushAudioSamples_Statics::NewProp_InPCM = { "InPCM", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DigHumanSubsystem_eventPushAudioSamples_Parms, InPCM), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InPCM_MetaData), NewProp_InPCM_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDigHumanSubsystem_PushAudioSamples_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDigHumanSubsystem_PushAudioSamples_Statics::NewProp_InPCM_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDigHumanSubsystem_PushAudioSamples_Statics::NewProp_InPCM,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDigHumanSubsystem_PushAudioSamples_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDigHumanSubsystem_PushAudioSamples_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDigHumanSubsystem, nullptr, "PushAudioSamples", nullptr, nullptr, Z_Construct_UFunction_UDigHumanSubsystem_PushAudioSamples_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDigHumanSubsystem_PushAudioSamples_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDigHumanSubsystem_PushAudioSamples_Statics::DigHumanSubsystem_eventPushAudioSamples_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDigHumanSubsystem_PushAudioSamples_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDigHumanSubsystem_PushAudioSamples_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UDigHumanSubsystem_PushAudioSamples_Statics::DigHumanSubsystem_eventPushAudioSamples_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDigHumanSubsystem_PushAudioSamples()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDigHumanSubsystem_PushAudioSamples_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDigHumanSubsystem::execPushAudioSamples)
{
	P_GET_TARRAY_REF(float,Z_Param_Out_InPCM);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->PushAudioSamples(Z_Param_Out_InPCM);
	P_NATIVE_END;
}
// End Class UDigHumanSubsystem Function PushAudioSamples

// Begin Class UDigHumanSubsystem Function SetSceneRendering
struct Z_Construct_UFunction_UDigHumanSubsystem_SetSceneRendering_Statics
{
	struct DigHumanSubsystem_eventSetSceneRendering_Parms
	{
		UObject* WorldContextObject;
		bool bOn;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xe5\x9c\xa8\xe4\xbd\xa0\xe7\x9a\x84 GameMode \xe6\x88\x96 Subsystem \xe9\x87\x8c\xe8\xb0\x83\xe7\x94\xa8\xe4\xb8\x80\xe6\xac\xa1\xe5\x8d\xb3\xe5\x8f\xaf\n" },
#endif
		{ "ModuleRelativePath", "Public/DigHumanSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x9c\xa8\xe4\xbd\xa0\xe7\x9a\x84 GameMode \xe6\x88\x96 Subsystem \xe9\x87\x8c\xe8\xb0\x83\xe7\x94\xa8\xe4\xb8\x80\xe6\xac\xa1\xe5\x8d\xb3\xe5\x8f\xaf" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static void NewProp_bOn_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOn;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDigHumanSubsystem_SetSceneRendering_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DigHumanSubsystem_eventSetSceneRendering_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UDigHumanSubsystem_SetSceneRendering_Statics::NewProp_bOn_SetBit(void* Obj)
{
	((DigHumanSubsystem_eventSetSceneRendering_Parms*)Obj)->bOn = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDigHumanSubsystem_SetSceneRendering_Statics::NewProp_bOn = { "bOn", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DigHumanSubsystem_eventSetSceneRendering_Parms), &Z_Construct_UFunction_UDigHumanSubsystem_SetSceneRendering_Statics::NewProp_bOn_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDigHumanSubsystem_SetSceneRendering_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDigHumanSubsystem_SetSceneRendering_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDigHumanSubsystem_SetSceneRendering_Statics::NewProp_bOn,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDigHumanSubsystem_SetSceneRendering_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDigHumanSubsystem_SetSceneRendering_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDigHumanSubsystem, nullptr, "SetSceneRendering", nullptr, nullptr, Z_Construct_UFunction_UDigHumanSubsystem_SetSceneRendering_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDigHumanSubsystem_SetSceneRendering_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDigHumanSubsystem_SetSceneRendering_Statics::DigHumanSubsystem_eventSetSceneRendering_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDigHumanSubsystem_SetSceneRendering_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDigHumanSubsystem_SetSceneRendering_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UDigHumanSubsystem_SetSceneRendering_Statics::DigHumanSubsystem_eventSetSceneRendering_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDigHumanSubsystem_SetSceneRendering()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDigHumanSubsystem_SetSceneRendering_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDigHumanSubsystem::execSetSceneRendering)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_UBOOL(Z_Param_bOn);
	P_FINISH;
	P_NATIVE_BEGIN;
	UDigHumanSubsystem::SetSceneRendering(Z_Param_WorldContextObject,Z_Param_bOn);
	P_NATIVE_END;
}
// End Class UDigHumanSubsystem Function SetSceneRendering

// Begin Class UDigHumanSubsystem Function StartRealtimeDrive
struct Z_Construct_UFunction_UDigHumanSubsystem_StartRealtimeDrive_Statics
{
	struct DigHumanSubsystem_eventStartRealtimeDrive_Parms
	{
		FString IdleVideoPath;
		FString TalkVideoPath;
		UImage* Avatar_Image;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "DigHuman" },
		{ "ModuleRelativePath", "Public/DigHumanSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IdleVideoPath_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TalkVideoPath_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Avatar_Image_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_IdleVideoPath;
	static const UECodeGen_Private::FStrPropertyParams NewProp_TalkVideoPath;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Avatar_Image;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDigHumanSubsystem_StartRealtimeDrive_Statics::NewProp_IdleVideoPath = { "IdleVideoPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DigHumanSubsystem_eventStartRealtimeDrive_Parms, IdleVideoPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IdleVideoPath_MetaData), NewProp_IdleVideoPath_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDigHumanSubsystem_StartRealtimeDrive_Statics::NewProp_TalkVideoPath = { "TalkVideoPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DigHumanSubsystem_eventStartRealtimeDrive_Parms, TalkVideoPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TalkVideoPath_MetaData), NewProp_TalkVideoPath_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDigHumanSubsystem_StartRealtimeDrive_Statics::NewProp_Avatar_Image = { "Avatar_Image", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DigHumanSubsystem_eventStartRealtimeDrive_Parms, Avatar_Image), Z_Construct_UClass_UImage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Avatar_Image_MetaData), NewProp_Avatar_Image_MetaData) };
void Z_Construct_UFunction_UDigHumanSubsystem_StartRealtimeDrive_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((DigHumanSubsystem_eventStartRealtimeDrive_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDigHumanSubsystem_StartRealtimeDrive_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DigHumanSubsystem_eventStartRealtimeDrive_Parms), &Z_Construct_UFunction_UDigHumanSubsystem_StartRealtimeDrive_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDigHumanSubsystem_StartRealtimeDrive_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDigHumanSubsystem_StartRealtimeDrive_Statics::NewProp_IdleVideoPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDigHumanSubsystem_StartRealtimeDrive_Statics::NewProp_TalkVideoPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDigHumanSubsystem_StartRealtimeDrive_Statics::NewProp_Avatar_Image,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDigHumanSubsystem_StartRealtimeDrive_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDigHumanSubsystem_StartRealtimeDrive_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDigHumanSubsystem_StartRealtimeDrive_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDigHumanSubsystem, nullptr, "StartRealtimeDrive", nullptr, nullptr, Z_Construct_UFunction_UDigHumanSubsystem_StartRealtimeDrive_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDigHumanSubsystem_StartRealtimeDrive_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDigHumanSubsystem_StartRealtimeDrive_Statics::DigHumanSubsystem_eventStartRealtimeDrive_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDigHumanSubsystem_StartRealtimeDrive_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDigHumanSubsystem_StartRealtimeDrive_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UDigHumanSubsystem_StartRealtimeDrive_Statics::DigHumanSubsystem_eventStartRealtimeDrive_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDigHumanSubsystem_StartRealtimeDrive()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDigHumanSubsystem_StartRealtimeDrive_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDigHumanSubsystem::execStartRealtimeDrive)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_IdleVideoPath);
	P_GET_PROPERTY(FStrProperty,Z_Param_TalkVideoPath);
	P_GET_OBJECT(UImage,Z_Param_Avatar_Image);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->StartRealtimeDrive(Z_Param_IdleVideoPath,Z_Param_TalkVideoPath,Z_Param_Avatar_Image);
	P_NATIVE_END;
}
// End Class UDigHumanSubsystem Function StartRealtimeDrive

// Begin Class UDigHumanSubsystem Function StartWavStream
struct Z_Construct_UFunction_UDigHumanSubsystem_StartWavStream_Statics
{
	struct DigHumanSubsystem_eventStartWavStream_Parms
	{
		FString WavPath;
		int32 ChunkSamples;
		int32 IntervalMs;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "DigHuman" },
		{ "CPP_Default_ChunkSamples", "160" },
		{ "CPP_Default_IntervalMs", "10" },
		{ "ModuleRelativePath", "Public/DigHumanSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbb\x8eWAV\xe6\x96\x87\xe4\xbb\xb6\xe6\xa8\xa1\xe6\x8b\x9fTTS\xe6\xb5\x81\xe5\xbc\x8f\xe6\x8e\xa8\xe9\x80\x81\xef\xbc\x8c\xe8\x87\xaa\xe5\x8a\xa8\xe5\x90\xaf\xe5\x8a\xa8\xe6\x8e\xa8\xe7\x90\x86\xe7\xba\xbf\xe7\xa8\x8b\nChunkSamples=160 IntervalMs=10 \xe5\xbb\xba\xe8\xae\xae""10ms\xe5\x9b\x9e\xe8\xb0\x83\xe8\x8a\x82\xe5\xa5\x8f" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WavPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_WavPath;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ChunkSamples;
	static const UECodeGen_Private::FIntPropertyParams NewProp_IntervalMs;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDigHumanSubsystem_StartWavStream_Statics::NewProp_WavPath = { "WavPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DigHumanSubsystem_eventStartWavStream_Parms, WavPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WavPath_MetaData), NewProp_WavPath_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDigHumanSubsystem_StartWavStream_Statics::NewProp_ChunkSamples = { "ChunkSamples", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DigHumanSubsystem_eventStartWavStream_Parms, ChunkSamples), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDigHumanSubsystem_StartWavStream_Statics::NewProp_IntervalMs = { "IntervalMs", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DigHumanSubsystem_eventStartWavStream_Parms, IntervalMs), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UDigHumanSubsystem_StartWavStream_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((DigHumanSubsystem_eventStartWavStream_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDigHumanSubsystem_StartWavStream_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DigHumanSubsystem_eventStartWavStream_Parms), &Z_Construct_UFunction_UDigHumanSubsystem_StartWavStream_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDigHumanSubsystem_StartWavStream_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDigHumanSubsystem_StartWavStream_Statics::NewProp_WavPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDigHumanSubsystem_StartWavStream_Statics::NewProp_ChunkSamples,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDigHumanSubsystem_StartWavStream_Statics::NewProp_IntervalMs,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDigHumanSubsystem_StartWavStream_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDigHumanSubsystem_StartWavStream_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDigHumanSubsystem_StartWavStream_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDigHumanSubsystem, nullptr, "StartWavStream", nullptr, nullptr, Z_Construct_UFunction_UDigHumanSubsystem_StartWavStream_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDigHumanSubsystem_StartWavStream_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDigHumanSubsystem_StartWavStream_Statics::DigHumanSubsystem_eventStartWavStream_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDigHumanSubsystem_StartWavStream_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDigHumanSubsystem_StartWavStream_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UDigHumanSubsystem_StartWavStream_Statics::DigHumanSubsystem_eventStartWavStream_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDigHumanSubsystem_StartWavStream()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDigHumanSubsystem_StartWavStream_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDigHumanSubsystem::execStartWavStream)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_WavPath);
	P_GET_PROPERTY(FIntProperty,Z_Param_ChunkSamples);
	P_GET_PROPERTY(FIntProperty,Z_Param_IntervalMs);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->StartWavStream(Z_Param_WavPath,Z_Param_ChunkSamples,Z_Param_IntervalMs);
	P_NATIVE_END;
}
// End Class UDigHumanSubsystem Function StartWavStream

// Begin Class UDigHumanSubsystem Function StopWavStreamTest
struct Z_Construct_UFunction_UDigHumanSubsystem_StopWavStreamTest_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "DigHuman" },
		{ "ModuleRelativePath", "Public/DigHumanSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDigHumanSubsystem_StopWavStreamTest_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDigHumanSubsystem, nullptr, "StopWavStreamTest", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDigHumanSubsystem_StopWavStreamTest_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDigHumanSubsystem_StopWavStreamTest_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UDigHumanSubsystem_StopWavStreamTest()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDigHumanSubsystem_StopWavStreamTest_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDigHumanSubsystem::execStopWavStreamTest)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StopWavStreamTest();
	P_NATIVE_END;
}
// End Class UDigHumanSubsystem Function StopWavStreamTest

// Begin Class UDigHumanSubsystem Function ThreadTick
struct Z_Construct_UFunction_UDigHumanSubsystem_ThreadTick_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "DigHuman" },
		{ "ModuleRelativePath", "Public/DigHumanSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDigHumanSubsystem_ThreadTick_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDigHumanSubsystem, nullptr, "ThreadTick", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDigHumanSubsystem_ThreadTick_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDigHumanSubsystem_ThreadTick_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UDigHumanSubsystem_ThreadTick()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDigHumanSubsystem_ThreadTick_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDigHumanSubsystem::execThreadTick)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ThreadTick();
	P_NATIVE_END;
}
// End Class UDigHumanSubsystem Function ThreadTick

// Begin Class UDigHumanSubsystem
void UDigHumanSubsystem::StaticRegisterNativesUDigHumanSubsystem()
{
	UClass* Class = UDigHumanSubsystem::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ChangeAvatarStatue", &UDigHumanSubsystem::execChangeAvatarStatue },
		{ "ComputeViedoFromFile", &UDigHumanSubsystem::execComputeViedoFromFile },
		{ "InitSystemModel", &UDigHumanSubsystem::execInitSystemModel },
		{ "IsReady", &UDigHumanSubsystem::execIsReady },
		{ "PushAudioSamples", &UDigHumanSubsystem::execPushAudioSamples },
		{ "SetSceneRendering", &UDigHumanSubsystem::execSetSceneRendering },
		{ "StartRealtimeDrive", &UDigHumanSubsystem::execStartRealtimeDrive },
		{ "StartWavStream", &UDigHumanSubsystem::execStartWavStream },
		{ "StopWavStreamTest", &UDigHumanSubsystem::execStopWavStreamTest },
		{ "ThreadTick", &UDigHumanSubsystem::execThreadTick },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDigHumanSubsystem);
UClass* Z_Construct_UClass_UDigHumanSubsystem_NoRegister()
{
	return UDigHumanSubsystem::StaticClass();
}
struct Z_Construct_UClass_UDigHumanSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "DigHumanSubsystem.h" },
		{ "ModuleRelativePath", "Public/DigHumanSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCalcViedoFinished_MetaData[] = {
		{ "Category", "DigHuman" },
		{ "ModuleRelativePath", "Public/DigHumanSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnModelLoaded_MetaData[] = {
		{ "Category", "DigHuman" },
		{ "ModuleRelativePath", "Public/DigHumanSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnModelReady_MetaData[] = {
		{ "Category", "DigHuman" },
		{ "ModuleRelativePath", "Public/DigHumanSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnWavPushFinished_MetaData[] = {
		{ "Category", "DigHuman" },
		{ "ModuleRelativePath", "Public/DigHumanSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InferenceBatchSize_MetaData[] = {
		{ "Category", "DigHuman" },
		{ "ModuleRelativePath", "Public/DigHumanSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Use_fp16_MetaData[] = {
		{ "Category", "DigHuman" },
		{ "ModuleRelativePath", "Public/DigHumanSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VideoFPS_MetaData[] = {
		{ "Category", "Audio" },
		{ "ModuleRelativePath", "Public/DigHumanSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AudioSampleRate_MetaData[] = {
		{ "Category", "Audio" },
		{ "ModuleRelativePath", "Public/DigHumanSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_debug_MetaData[] = {
		{ "Category", "DigHuman" },
		{ "ModuleRelativePath", "Public/DigHumanSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProceduralSoundWave_MetaData[] = {
		{ "ModuleRelativePath", "Public/DigHumanSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GAudioComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DigHumanSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCalcViedoFinished;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnModelLoaded;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnModelReady;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnWavPushFinished;
	static const UECodeGen_Private::FIntPropertyParams NewProp_InferenceBatchSize;
	static void NewProp_Use_fp16_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_Use_fp16;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_VideoFPS;
	static const UECodeGen_Private::FIntPropertyParams NewProp_AudioSampleRate;
	static void NewProp_debug_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_debug;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ProceduralSoundWave;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GAudioComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDigHumanSubsystem_ChangeAvatarStatue, "ChangeAvatarStatue" }, // 1873855495
		{ &Z_Construct_UFunction_UDigHumanSubsystem_ComputeViedoFromFile, "ComputeViedoFromFile" }, // 814192828
		{ &Z_Construct_UFunction_UDigHumanSubsystem_InitSystemModel, "InitSystemModel" }, // 2284077364
		{ &Z_Construct_UFunction_UDigHumanSubsystem_IsReady, "IsReady" }, // 3665478372
		{ &Z_Construct_UFunction_UDigHumanSubsystem_PushAudioSamples, "PushAudioSamples" }, // 2059207791
		{ &Z_Construct_UFunction_UDigHumanSubsystem_SetSceneRendering, "SetSceneRendering" }, // 3108279487
		{ &Z_Construct_UFunction_UDigHumanSubsystem_StartRealtimeDrive, "StartRealtimeDrive" }, // 4129079071
		{ &Z_Construct_UFunction_UDigHumanSubsystem_StartWavStream, "StartWavStream" }, // 1717666580
		{ &Z_Construct_UFunction_UDigHumanSubsystem_StopWavStreamTest, "StopWavStreamTest" }, // 764749695
		{ &Z_Construct_UFunction_UDigHumanSubsystem_ThreadTick, "ThreadTick" }, // 4083571500
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDigHumanSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDigHumanSubsystem_Statics::NewProp_OnCalcViedoFinished = { "OnCalcViedoFinished", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDigHumanSubsystem, OnCalcViedoFinished), Z_Construct_UDelegateFunction_RealAvatarN_OnCalcViedoFinished__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCalcViedoFinished_MetaData), NewProp_OnCalcViedoFinished_MetaData) }; // 2290746029
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDigHumanSubsystem_Statics::NewProp_OnModelLoaded = { "OnModelLoaded", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDigHumanSubsystem, OnModelLoaded), Z_Construct_UDelegateFunction_RealAvatarN_OnModelLoaded__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnModelLoaded_MetaData), NewProp_OnModelLoaded_MetaData) }; // 646042652
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDigHumanSubsystem_Statics::NewProp_OnModelReady = { "OnModelReady", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDigHumanSubsystem, OnModelReady), Z_Construct_UDelegateFunction_RealAvatarN_OnModelReady__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnModelReady_MetaData), NewProp_OnModelReady_MetaData) }; // 1574029431
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDigHumanSubsystem_Statics::NewProp_OnWavPushFinished = { "OnWavPushFinished", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDigHumanSubsystem, OnWavPushFinished), Z_Construct_UDelegateFunction_RealAvatarN_OnWavPushFinished__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnWavPushFinished_MetaData), NewProp_OnWavPushFinished_MetaData) }; // 4226433687
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UDigHumanSubsystem_Statics::NewProp_InferenceBatchSize = { "InferenceBatchSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDigHumanSubsystem, InferenceBatchSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InferenceBatchSize_MetaData), NewProp_InferenceBatchSize_MetaData) };
void Z_Construct_UClass_UDigHumanSubsystem_Statics::NewProp_Use_fp16_SetBit(void* Obj)
{
	((UDigHumanSubsystem*)Obj)->Use_fp16 = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDigHumanSubsystem_Statics::NewProp_Use_fp16 = { "Use_fp16", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDigHumanSubsystem), &Z_Construct_UClass_UDigHumanSubsystem_Statics::NewProp_Use_fp16_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Use_fp16_MetaData), NewProp_Use_fp16_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDigHumanSubsystem_Statics::NewProp_VideoFPS = { "VideoFPS", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDigHumanSubsystem, VideoFPS), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VideoFPS_MetaData), NewProp_VideoFPS_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UDigHumanSubsystem_Statics::NewProp_AudioSampleRate = { "AudioSampleRate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDigHumanSubsystem, AudioSampleRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AudioSampleRate_MetaData), NewProp_AudioSampleRate_MetaData) };
void Z_Construct_UClass_UDigHumanSubsystem_Statics::NewProp_debug_SetBit(void* Obj)
{
	((UDigHumanSubsystem*)Obj)->debug = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDigHumanSubsystem_Statics::NewProp_debug = { "debug", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDigHumanSubsystem), &Z_Construct_UClass_UDigHumanSubsystem_Statics::NewProp_debug_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_debug_MetaData), NewProp_debug_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDigHumanSubsystem_Statics::NewProp_ProceduralSoundWave = { "ProceduralSoundWave", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDigHumanSubsystem, ProceduralSoundWave), Z_Construct_UClass_USoundWaveProcedural_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProceduralSoundWave_MetaData), NewProp_ProceduralSoundWave_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDigHumanSubsystem_Statics::NewProp_GAudioComponent = { "GAudioComponent", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDigHumanSubsystem, GAudioComponent), Z_Construct_UClass_UAudioComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GAudioComponent_MetaData), NewProp_GAudioComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDigHumanSubsystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDigHumanSubsystem_Statics::NewProp_OnCalcViedoFinished,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDigHumanSubsystem_Statics::NewProp_OnModelLoaded,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDigHumanSubsystem_Statics::NewProp_OnModelReady,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDigHumanSubsystem_Statics::NewProp_OnWavPushFinished,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDigHumanSubsystem_Statics::NewProp_InferenceBatchSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDigHumanSubsystem_Statics::NewProp_Use_fp16,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDigHumanSubsystem_Statics::NewProp_VideoFPS,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDigHumanSubsystem_Statics::NewProp_AudioSampleRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDigHumanSubsystem_Statics::NewProp_debug,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDigHumanSubsystem_Statics::NewProp_ProceduralSoundWave,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDigHumanSubsystem_Statics::NewProp_GAudioComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDigHumanSubsystem_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UDigHumanSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_RealAvatarN,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDigHumanSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDigHumanSubsystem_Statics::ClassParams = {
	&UDigHumanSubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UDigHumanSubsystem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UDigHumanSubsystem_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDigHumanSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UDigHumanSubsystem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UDigHumanSubsystem()
{
	if (!Z_Registration_Info_UClass_UDigHumanSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDigHumanSubsystem.OuterSingleton, Z_Construct_UClass_UDigHumanSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDigHumanSubsystem.OuterSingleton;
}
template<> REALAVATARN_API UClass* StaticClass<UDigHumanSubsystem>()
{
	return UDigHumanSubsystem::StaticClass();
}
UDigHumanSubsystem::UDigHumanSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UDigHumanSubsystem);
UDigHumanSubsystem::~UDigHumanSubsystem() {}
// End Class UDigHumanSubsystem

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE_Project_UE5_5_test_MyProject_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDigHumanSubsystem, UDigHumanSubsystem::StaticClass, TEXT("UDigHumanSubsystem"), &Z_Registration_Info_UClass_UDigHumanSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDigHumanSubsystem), 2253481912U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_Project_UE5_5_test_MyProject_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_3558130412(TEXT("/Script/RealAvatarN"),
	Z_CompiledInDeferFile_FID_UE_Project_UE5_5_test_MyProject_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_Project_UE5_5_test_MyProject_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
