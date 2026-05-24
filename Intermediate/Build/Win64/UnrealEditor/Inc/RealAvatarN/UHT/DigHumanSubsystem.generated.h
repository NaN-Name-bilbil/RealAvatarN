// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DigHumanSubsystem.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UAudioComponent;
class UImage;
class UObject;
#ifdef REALAVATARN_DigHumanSubsystem_generated_h
#error "DigHumanSubsystem.generated.h already included, missing '#pragma once' in DigHumanSubsystem.h"
#endif
#define REALAVATARN_DigHumanSubsystem_generated_h

#define FID_UE_Project_UE5_5_test_MyProject_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_21_DELEGATE \
REALAVATARN_API void FOnModelLoaded_DelegateWrapper(const FMulticastScriptDelegate& OnModelLoaded, bool result);


#define FID_UE_Project_UE5_5_test_MyProject_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_22_DELEGATE \
REALAVATARN_API void FOnModelReady_DelegateWrapper(const FMulticastScriptDelegate& OnModelReady, bool result);


#define FID_UE_Project_UE5_5_test_MyProject_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_23_DELEGATE \
REALAVATARN_API void FOnCalcViedoFinished_DelegateWrapper(const FMulticastScriptDelegate& OnCalcViedoFinished, bool result);


#define FID_UE_Project_UE5_5_test_MyProject_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_24_DELEGATE \
REALAVATARN_API void FOnWavPushFinished_DelegateWrapper(const FMulticastScriptDelegate& OnWavPushFinished, bool result);


#define FID_UE_Project_UE5_5_test_MyProject_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_45_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execStopWavStreamTest); \
	DECLARE_FUNCTION(execStartWavStream); \
	DECLARE_FUNCTION(execSetSceneRendering); \
	DECLARE_FUNCTION(execComputeViedoFromFile); \
	DECLARE_FUNCTION(execIsReady); \
	DECLARE_FUNCTION(execThreadTick); \
	DECLARE_FUNCTION(execChangeAvatarStatue); \
	DECLARE_FUNCTION(execPushAudioSamples); \
	DECLARE_FUNCTION(execStartRealtimeDrive); \
	DECLARE_FUNCTION(execInitSystemModel);


#define FID_UE_Project_UE5_5_test_MyProject_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_45_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDigHumanSubsystem(); \
	friend struct Z_Construct_UClass_UDigHumanSubsystem_Statics; \
public: \
	DECLARE_CLASS(UDigHumanSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/RealAvatarN"), NO_API) \
	DECLARE_SERIALIZER(UDigHumanSubsystem)


#define FID_UE_Project_UE5_5_test_MyProject_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_45_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDigHumanSubsystem(); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UDigHumanSubsystem(UDigHumanSubsystem&&); \
	UDigHumanSubsystem(const UDigHumanSubsystem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDigHumanSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDigHumanSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UDigHumanSubsystem) \
	NO_API virtual ~UDigHumanSubsystem();


#define FID_UE_Project_UE5_5_test_MyProject_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_42_PROLOG
#define FID_UE_Project_UE5_5_test_MyProject_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_45_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UE_Project_UE5_5_test_MyProject_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_45_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UE_Project_UE5_5_test_MyProject_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_45_INCLASS_NO_PURE_DECLS \
	FID_UE_Project_UE5_5_test_MyProject_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_45_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> REALAVATARN_API UClass* StaticClass<class UDigHumanSubsystem>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UE_Project_UE5_5_test_MyProject_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
