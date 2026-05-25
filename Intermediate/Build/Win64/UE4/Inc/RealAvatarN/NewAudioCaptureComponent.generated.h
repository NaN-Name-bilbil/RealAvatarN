// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef REALAVATARN_NewAudioCaptureComponent_generated_h
#error "NewAudioCaptureComponent.generated.h already included, missing '#pragma once' in NewAudioCaptureComponent.h"
#endif
#define REALAVATARN_NewAudioCaptureComponent_generated_h

#define TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_NewAudioCaptureComponent_h_10_DELEGATE \
struct _Script_RealAvatarN_eventOnGenerateAudioF_Parms \
{ \
	TArray<float> OutAudioFloat; \
}; \
static inline void FOnGenerateAudioF_DelegateWrapper(const FMulticastScriptDelegate& OnGenerateAudioF, TArray<float> const& OutAudioFloat) \
{ \
	_Script_RealAvatarN_eventOnGenerateAudioF_Parms Parms; \
	Parms.OutAudioFloat=OutAudioFloat; \
	OnGenerateAudioF.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_NewAudioCaptureComponent_h_9_DELEGATE \
struct _Script_RealAvatarN_eventOnGenerateAudioD_Parms \
{ \
	TArray<uint8> OutAudio; \
}; \
static inline void FOnGenerateAudioD_DelegateWrapper(const FMulticastScriptDelegate& OnGenerateAudioD, TArray<uint8> const& OutAudio) \
{ \
	_Script_RealAvatarN_eventOnGenerateAudioD_Parms Parms; \
	Parms.OutAudio=OutAudio; \
	OnGenerateAudioD.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_NewAudioCaptureComponent_h_15_SPARSE_DATA
#define TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_NewAudioCaptureComponent_h_15_RPC_WRAPPERS
#define TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_NewAudioCaptureComponent_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_NewAudioCaptureComponent_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUNewAudioCaptureComponent(); \
	friend struct Z_Construct_UClass_UNewAudioCaptureComponent_Statics; \
public: \
	DECLARE_CLASS(UNewAudioCaptureComponent, USynthComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/RealAvatarN"), NO_API) \
	DECLARE_SERIALIZER(UNewAudioCaptureComponent)


#define TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_NewAudioCaptureComponent_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUNewAudioCaptureComponent(); \
	friend struct Z_Construct_UClass_UNewAudioCaptureComponent_Statics; \
public: \
	DECLARE_CLASS(UNewAudioCaptureComponent, USynthComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/RealAvatarN"), NO_API) \
	DECLARE_SERIALIZER(UNewAudioCaptureComponent)


#define TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_NewAudioCaptureComponent_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UNewAudioCaptureComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UNewAudioCaptureComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UNewAudioCaptureComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UNewAudioCaptureComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UNewAudioCaptureComponent(UNewAudioCaptureComponent&&); \
	NO_API UNewAudioCaptureComponent(const UNewAudioCaptureComponent&); \
public:


#define TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_NewAudioCaptureComponent_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UNewAudioCaptureComponent(UNewAudioCaptureComponent&&); \
	NO_API UNewAudioCaptureComponent(const UNewAudioCaptureComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UNewAudioCaptureComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UNewAudioCaptureComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UNewAudioCaptureComponent)


#define TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_NewAudioCaptureComponent_h_15_PRIVATE_PROPERTY_OFFSET
#define TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_NewAudioCaptureComponent_h_12_PROLOG
#define TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_NewAudioCaptureComponent_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_NewAudioCaptureComponent_h_15_PRIVATE_PROPERTY_OFFSET \
	TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_NewAudioCaptureComponent_h_15_SPARSE_DATA \
	TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_NewAudioCaptureComponent_h_15_RPC_WRAPPERS \
	TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_NewAudioCaptureComponent_h_15_INCLASS \
	TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_NewAudioCaptureComponent_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_NewAudioCaptureComponent_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_NewAudioCaptureComponent_h_15_PRIVATE_PROPERTY_OFFSET \
	TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_NewAudioCaptureComponent_h_15_SPARSE_DATA \
	TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_NewAudioCaptureComponent_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_NewAudioCaptureComponent_h_15_INCLASS_NO_PURE_DECLS \
	TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_NewAudioCaptureComponent_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> REALAVATARN_API UClass* StaticClass<class UNewAudioCaptureComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_NewAudioCaptureComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
