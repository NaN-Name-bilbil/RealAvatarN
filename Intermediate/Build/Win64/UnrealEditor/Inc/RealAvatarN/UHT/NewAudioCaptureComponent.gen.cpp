// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RealAvatarN/Public/NewAudioCaptureComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNewAudioCaptureComponent() {}

// Begin Cross Module References
AUDIOMIXER_API UClass* Z_Construct_UClass_USynthComponent();
REALAVATARN_API UClass* Z_Construct_UClass_UNewAudioCaptureComponent();
REALAVATARN_API UClass* Z_Construct_UClass_UNewAudioCaptureComponent_NoRegister();
REALAVATARN_API UFunction* Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioD__DelegateSignature();
REALAVATARN_API UFunction* Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioF__DelegateSignature();
UPackage* Z_Construct_UPackage__Script_RealAvatarN();
// End Cross Module References

// Begin Delegate FOnGenerateAudioD
struct Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioD__DelegateSignature_Statics
{
	struct _Script_RealAvatarN_eventOnGenerateAudioD_Parms
	{
		TArray<uint8> OutAudio;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/NewAudioCaptureComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutAudio_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_OutAudio_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutAudio;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioD__DelegateSignature_Statics::NewProp_OutAudio_Inner = { "OutAudio", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioD__DelegateSignature_Statics::NewProp_OutAudio = { "OutAudio", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_RealAvatarN_eventOnGenerateAudioD_Parms, OutAudio), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutAudio_MetaData), NewProp_OutAudio_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioD__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioD__DelegateSignature_Statics::NewProp_OutAudio_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioD__DelegateSignature_Statics::NewProp_OutAudio,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioD__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioD__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_RealAvatarN, nullptr, "OnGenerateAudioD__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioD__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioD__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioD__DelegateSignature_Statics::_Script_RealAvatarN_eventOnGenerateAudioD_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioD__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioD__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioD__DelegateSignature_Statics::_Script_RealAvatarN_eventOnGenerateAudioD_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioD__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioD__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnGenerateAudioD_DelegateWrapper(const FMulticastScriptDelegate& OnGenerateAudioD, TArray<uint8> const& OutAudio)
{
	struct _Script_RealAvatarN_eventOnGenerateAudioD_Parms
	{
		TArray<uint8> OutAudio;
	};
	_Script_RealAvatarN_eventOnGenerateAudioD_Parms Parms;
	Parms.OutAudio=OutAudio;
	OnGenerateAudioD.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnGenerateAudioD

// Begin Delegate FOnGenerateAudioF
struct Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioF__DelegateSignature_Statics
{
	struct _Script_RealAvatarN_eventOnGenerateAudioF_Parms
	{
		TArray<float> OutAudioFloat;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/NewAudioCaptureComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutAudioFloat_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OutAudioFloat_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutAudioFloat;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioF__DelegateSignature_Statics::NewProp_OutAudioFloat_Inner = { "OutAudioFloat", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioF__DelegateSignature_Statics::NewProp_OutAudioFloat = { "OutAudioFloat", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_RealAvatarN_eventOnGenerateAudioF_Parms, OutAudioFloat), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutAudioFloat_MetaData), NewProp_OutAudioFloat_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioF__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioF__DelegateSignature_Statics::NewProp_OutAudioFloat_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioF__DelegateSignature_Statics::NewProp_OutAudioFloat,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioF__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioF__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_RealAvatarN, nullptr, "OnGenerateAudioF__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioF__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioF__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioF__DelegateSignature_Statics::_Script_RealAvatarN_eventOnGenerateAudioF_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioF__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioF__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioF__DelegateSignature_Statics::_Script_RealAvatarN_eventOnGenerateAudioF_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioF__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioF__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnGenerateAudioF_DelegateWrapper(const FMulticastScriptDelegate& OnGenerateAudioF, TArray<float> const& OutAudioFloat)
{
	struct _Script_RealAvatarN_eventOnGenerateAudioF_Parms
	{
		TArray<float> OutAudioFloat;
	};
	_Script_RealAvatarN_eventOnGenerateAudioF_Parms Parms;
	Parms.OutAudioFloat=OutAudioFloat;
	OnGenerateAudioF.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnGenerateAudioF

// Begin Class UNewAudioCaptureComponent
void UNewAudioCaptureComponent::StaticRegisterNativesUNewAudioCaptureComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UNewAudioCaptureComponent);
UClass* Z_Construct_UClass_UNewAudioCaptureComponent_NoRegister()
{
	return UNewAudioCaptureComponent::StaticClass();
}
struct Z_Construct_UClass_UNewAudioCaptureComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Synth" },
		{ "HideCategories", "Object ActorComponent Physics Rendering Mobility LOD Trigger PhysicsVolume" },
		{ "IncludePath", "NewAudioCaptureComponent.h" },
		{ "ModuleRelativePath", "Public/NewAudioCaptureComponent.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnceSendFloatDataNum_MetaData[] = {
		{ "Category", "Latency" },
		{ "ClampMax", "102400" },
		{ "ClampMin", "16" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xaf\x8f\xe6\xac\xa1\xe5\xb9\xbf\xe6\x92\xad\xe4\xb8\x80\xe5\x9d\x97\xe7\x9a\x84\xe6\xa0\xb7\xe6\x9c\xac\xe6\x95\xb0 (16kHz \xe5\x8d\x95\xe5\xa3\xb0\xe9\x81\x93)\xe3\x80\x82\xe4\xbe\x8b\xe5\xa6\x82 160 = 10ms, 320 = 20ms */" },
#endif
		{ "ModuleRelativePath", "Public/NewAudioCaptureComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xaf\x8f\xe6\xac\xa1\xe5\xb9\xbf\xe6\x92\xad\xe4\xb8\x80\xe5\x9d\x97\xe7\x9a\x84\xe6\xa0\xb7\xe6\x9c\xac\xe6\x95\xb0 (16kHz \xe5\x8d\x95\xe5\xa3\xb0\xe9\x81\x93)\xe3\x80\x82\xe4\xbe\x8b\xe5\xa6\x82 160 = 10ms, 320 = 20ms" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetSampleRate_MetaData[] = {
		{ "Category", "Latency" },
		{ "ClampMax", "48000" },
		{ "ClampMin", "8000" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe7\x9b\xae\xe6\xa0\x87\xe8\xbe\x93\xe5\x87\xba\xe9\x87\x87\xe6\xa0\xb7\xe7\x8e\x87\xef\xbc\x8c\xe5\x9b\xba\xe5\xae\x9a 16000 \xe5\x8d\xb3\xe5\x8f\xaf\xef\xbc\x9b\xe4\xbf\x9d\xe7\x95\x99\xe4\xb8\xba\xe5\x8f\x82\xe6\x95\xb0\xe6\x96\xb9\xe4\xbe\xbf\xe4\xbb\xa5\xe5\x90\x8e\xe6\x94\xb9 */" },
#endif
		{ "ModuleRelativePath", "Public/NewAudioCaptureComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe7\x9b\xae\xe6\xa0\x87\xe8\xbe\x93\xe5\x87\xba\xe9\x87\x87\xe6\xa0\xb7\xe7\x8e\x87\xef\xbc\x8c\xe5\x9b\xba\xe5\xae\x9a 16000 \xe5\x8d\xb3\xe5\x8f\xaf\xef\xbc\x9b\xe4\xbf\x9d\xe7\x95\x99\xe4\xb8\xba\xe5\x8f\x82\xe6\x95\xb0\xe6\x96\xb9\xe4\xbe\xbf\xe4\xbb\xa5\xe5\x90\x8e\xe6\x94\xb9" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bBroadcastEnabled_MetaData[] = {
		{ "Category", "Latency" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x93\x9d\xe5\x9b\xbe\xe5\xbc\x80\xe5\x85\xb3\xef\xbc\x9a\xe6\x98\xaf\xe5\x90\xa6\xe5\xb9\xbf\xe6\x92\xad */" },
#endif
		{ "ModuleRelativePath", "Public/NewAudioCaptureComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x93\x9d\xe5\x9b\xbe\xe5\xbc\x80\xe5\x85\xb3\xef\xbc\x9a\xe6\x98\xaf\xe5\x90\xa6\xe5\xb9\xbf\xe6\x92\xad" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUseFloat_MetaData[] = {
		{ "Category", "Latency" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe9\x80\x89\xe6\x8b\xa9\xe5\xb9\xbf\xe6\x92\xad\xe7\x9a\x84\xe6\xa0\xbc\xe5\xbc\x8f\xef\xbc\x9atrue \xe8\xb5\xb0 OnAudioOutFloat\xef\xbc\x8c""false \xe8\xb5\xb0 OnAudioOut(uint8 PCM) */" },
#endif
		{ "ModuleRelativePath", "Public/NewAudioCaptureComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe9\x80\x89\xe6\x8b\xa9\xe5\xb9\xbf\xe6\x92\xad\xe7\x9a\x84\xe6\xa0\xbc\xe5\xbc\x8f\xef\xbc\x9atrue \xe8\xb5\xb0 OnAudioOutFloat\xef\xbc\x8c""false \xe8\xb5\xb0 OnAudioOut(uint8 PCM)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnAudioOut_MetaData[] = {
		{ "ModuleRelativePath", "Public/NewAudioCaptureComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnAudioOutFloat_MetaData[] = {
		{ "ModuleRelativePath", "Public/NewAudioCaptureComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_OnceSendFloatDataNum;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TargetSampleRate;
	static void NewProp_bBroadcastEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bBroadcastEnabled;
	static void NewProp_bUseFloat_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseFloat;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnAudioOut;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnAudioOutFloat;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UNewAudioCaptureComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UNewAudioCaptureComponent_Statics::NewProp_OnceSendFloatDataNum = { "OnceSendFloatDataNum", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNewAudioCaptureComponent, OnceSendFloatDataNum), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnceSendFloatDataNum_MetaData), NewProp_OnceSendFloatDataNum_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UNewAudioCaptureComponent_Statics::NewProp_TargetSampleRate = { "TargetSampleRate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNewAudioCaptureComponent, TargetSampleRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetSampleRate_MetaData), NewProp_TargetSampleRate_MetaData) };
void Z_Construct_UClass_UNewAudioCaptureComponent_Statics::NewProp_bBroadcastEnabled_SetBit(void* Obj)
{
	((UNewAudioCaptureComponent*)Obj)->bBroadcastEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UNewAudioCaptureComponent_Statics::NewProp_bBroadcastEnabled = { "bBroadcastEnabled", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UNewAudioCaptureComponent), &Z_Construct_UClass_UNewAudioCaptureComponent_Statics::NewProp_bBroadcastEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bBroadcastEnabled_MetaData), NewProp_bBroadcastEnabled_MetaData) };
void Z_Construct_UClass_UNewAudioCaptureComponent_Statics::NewProp_bUseFloat_SetBit(void* Obj)
{
	((UNewAudioCaptureComponent*)Obj)->bUseFloat = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UNewAudioCaptureComponent_Statics::NewProp_bUseFloat = { "bUseFloat", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UNewAudioCaptureComponent), &Z_Construct_UClass_UNewAudioCaptureComponent_Statics::NewProp_bUseFloat_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUseFloat_MetaData), NewProp_bUseFloat_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UNewAudioCaptureComponent_Statics::NewProp_OnAudioOut = { "OnAudioOut", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNewAudioCaptureComponent, OnAudioOut), Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioD__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnAudioOut_MetaData), NewProp_OnAudioOut_MetaData) }; // 2262819966
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UNewAudioCaptureComponent_Statics::NewProp_OnAudioOutFloat = { "OnAudioOutFloat", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNewAudioCaptureComponent, OnAudioOutFloat), Z_Construct_UDelegateFunction_RealAvatarN_OnGenerateAudioF__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnAudioOutFloat_MetaData), NewProp_OnAudioOutFloat_MetaData) }; // 546920370
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UNewAudioCaptureComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNewAudioCaptureComponent_Statics::NewProp_OnceSendFloatDataNum,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNewAudioCaptureComponent_Statics::NewProp_TargetSampleRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNewAudioCaptureComponent_Statics::NewProp_bBroadcastEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNewAudioCaptureComponent_Statics::NewProp_bUseFloat,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNewAudioCaptureComponent_Statics::NewProp_OnAudioOut,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNewAudioCaptureComponent_Statics::NewProp_OnAudioOutFloat,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNewAudioCaptureComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UNewAudioCaptureComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_USynthComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_RealAvatarN,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNewAudioCaptureComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UNewAudioCaptureComponent_Statics::ClassParams = {
	&UNewAudioCaptureComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UNewAudioCaptureComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UNewAudioCaptureComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNewAudioCaptureComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UNewAudioCaptureComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UNewAudioCaptureComponent()
{
	if (!Z_Registration_Info_UClass_UNewAudioCaptureComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UNewAudioCaptureComponent.OuterSingleton, Z_Construct_UClass_UNewAudioCaptureComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UNewAudioCaptureComponent.OuterSingleton;
}
template<> REALAVATARN_API UClass* StaticClass<UNewAudioCaptureComponent>()
{
	return UNewAudioCaptureComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UNewAudioCaptureComponent);
UNewAudioCaptureComponent::~UNewAudioCaptureComponent() {}
// End Class UNewAudioCaptureComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_UE_Project_UE5_5_test_MyProject_Plugins_RealAvatarN_Source_RealAvatarN_Public_NewAudioCaptureComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UNewAudioCaptureComponent, UNewAudioCaptureComponent::StaticClass, TEXT("UNewAudioCaptureComponent"), &Z_Registration_Info_UClass_UNewAudioCaptureComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UNewAudioCaptureComponent), 3068499875U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE_Project_UE5_5_test_MyProject_Plugins_RealAvatarN_Source_RealAvatarN_Public_NewAudioCaptureComponent_h_2281289856(TEXT("/Script/RealAvatarN"),
	Z_CompiledInDeferFile_FID_UE_Project_UE5_5_test_MyProject_Plugins_RealAvatarN_Source_RealAvatarN_Public_NewAudioCaptureComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE_Project_UE5_5_test_MyProject_Plugins_RealAvatarN_Source_RealAvatarN_Public_NewAudioCaptureComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
