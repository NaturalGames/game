// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "MissingBlueprintFunctions.generated.h"


UENUM()
enum class EINICategory : uint8
{
	INI_Game			UMETA(DisplayName = "Game"),
	INI_Input			UMETA(DisplayName = "Input"),
	INI_Scalability		UMETA(DisplayName = "Scalability"),
	INI_UserSettings	UMETA(DisplayName = "User Settings")
};


/**
 * 
 */
UCLASS()
class MISSINGUE4_API UMissingBlueprintFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	
public:
	UFUNCTION(BlueprintCallable, Category = "Missing|Utilities")
	static void SetINIConfigValue(EINICategory INICategory, FString SectionName, FString KeyString, FString ValueString);
	
	UFUNCTION(BlueprintCallable, Category = "Missing|Utilities")
	static FString GetINIConfigValue(EINICategory INICategory, const FString& SectionName, const FString& KeyString);

	UFUNCTION(BlueprintCallable, Category = "Missing|Utilities")
	static void RemoveINIConfigKey(EINICategory INICategory, FString SectionName, FString KeyString);

	UFUNCTION(BlueprintCallable, Category = "Missing|Utilities")
	static FString GetSteamUsername();


private:
	static FString GetINIStringFromCategory(const EINICategory& INICategory);
};

// EoF