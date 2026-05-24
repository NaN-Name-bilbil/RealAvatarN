// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
class UImage;
class UAudioComponent;
#ifdef REALAVATARN_DigHumanSubsystem_generated_h
#error "DigHumanSubsystem.generated.h already included, missing '#pragma once' in DigHumanSubsystem.h"
#endif
#define REALAVATARN_DigHumanSubsystem_generated_h

#define TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_24_DELEGATE \
struct _Script_RealAvatarN_eventOnWavPushFinished_Parms \
{ \
	bool result; \
}; \
static inline void FOnWavPushFinished_DelegateWrapper(const FMulticastScriptDelegate& OnWavPushFinished, bool result) \
{ \
	_Script_RealAvatarN_eventOnWavPushFinished_Parms Parms; \
	Parms.result=result ? true : false; \
	OnWavPushFinished.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_23_DELEGATE \
struct _Script_RealAvatarN_eventOnCalcViedoFinished_Parms \
{ \
	bool result; \
}; \
static inline void FOnCalcViedoFinished_DelegateWrapper(const FMulticastScriptDelegate& OnCalcViedoFinished, bool result) \
{ \
	_Script_RealAvatarN_eventOnCalcViedoFinished_Parms Parms; \
	Parms.result=result ? true : false; \
	OnCalcViedoFinished.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_22_DELEGATE \
struct _Script_RealAvatarN_eventOnModelReady_Parms \
{ \
	bool result; \
}; \
static inline void FOnModelReady_DelegateWrapper(const FMulticastScriptDelegate& OnModelReady, bool result) \
{ \
	_Script_RealAvatarN_eventOnModelReady_Parms Parms; \
	Parms.result=result ? true : false; \
	OnModelReady.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_21_DELEGATE \
struct _Script_RealAvatarN_eventOnModelLoaded_Parms \
{ \
	bool result; \
}; \
static inline void FOnModelLoaded_DelegateWrapper(const FMulticastScriptDelegate& OnModelLoaded, bool result) \
{ \
	_Script_RealAvatarN_eventOnModelLoaded_Parms Parms; \
	Parms.result=result ? true : false; \
	OnModelLoaded.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_45_SPARSE_DATA
#define TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_45_RPC_WRAPPERS \
 \
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


#define TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_45_RPC_WRAPPERS_NO_PURE_DECLS \
 \
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


#define TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_45_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDigHumanSubsystem(); \
	friend struct Z_Construct_UClass_UDigHumanSubsystem_Statics; \
public: \
	DECLARE_CLASS(UDigHumanSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/RealAvatarN"), NO_API) \
	DECLARE_SERIALIZER(UDigHumanSubsystem)


#define TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_45_INCLASS \
private: \
	static void StaticRegisterNativesUDigHumanSubsystem(); \
	friend struct Z_Construct_UClass_UDigHumanSubsystem_Statics; \
public: \
	DECLARE_CLASS(UDigHumanSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/RealAvatarN"), NO_API) \
	DECLARE_SERIALIZER(UDigHumanSubsystem)


#define TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_45_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDigHumanSubsystem(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDigHumanSubsystem) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDigHumanSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDigHumanSubsystem); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDigHumanSubsystem(UDigHumanSubsystem&&); \
	NO_API UDigHumanSubsystem(const UDigHumanSubsystem&); \
public:


#define TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_45_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDigHumanSubsystem() { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDigHumanSubsystem(UDigHumanSubsystem&&); \
	NO_API UDigHumanSubsystem(const UDigHumanSubsystem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDigHumanSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDigHumanSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UDigHumanSubsystem)


#define TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_45_PRIVATE_PROPERTY_OFFSET
#define TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_42_PROLOG
#define TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_45_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_45_PRIVATE_PROPERTY_OFFSET \
	TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_45_SPARSE_DATA \
	TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_45_RPC_WRAPPERS \
	TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_45_INCLASS \
	TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_45_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_45_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_45_PRIVATE_PROPERTY_OFFSET \
	TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_45_SPARSE_DATA \
	TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_45_RPC_WRAPPERS_NO_PURE_DECLS \
	TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_45_INCLASS_NO_PURE_DECLS \
	TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h_45_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> REALAVATARN_API UClass* StaticClass<class UDigHumanSubsystem>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TST_Plugins_RealAvatarN_Source_RealAvatarN_Public_DigHumanSubsystem_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
