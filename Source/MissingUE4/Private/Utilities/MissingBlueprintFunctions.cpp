// Fill out your copyright notice in the Description page of Project Settings.

#include "MissingUE4.h"
#include "MissingBlueprintFunctions.h"


void UMissingBlueprintFunctions::SetINIConfigValue(EINICategory INICategory, FString SectionName, FString KeyString, FString ValueString)
{
	if (GConfig)
	{
		const FString categoryString = GetINIStringFromCategory(INICategory);
		GConfig->SetString(*SectionName, *KeyString, *ValueString, categoryString);
		GConfig->Flush(false, categoryString);
	}
}

FString UMissingBlueprintFunctions::GetINIConfigValue(EINICategory INICategory, const FString& SectionName, const FString& KeyString)
{
	FString valueString = TEXT("");

	if (GConfig)
	{
		const FString categoryString = GetINIStringFromCategory(INICategory);
		if (!GConfig->GetString(*SectionName, *KeyString, valueString, categoryString))
		{
			GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("Invalid section or key name while retrieving from config file"));
		}
	}

	return valueString;
}

void UMissingBlueprintFunctions::RemoveINIConfigKey(EINICategory INICategory, FString SectionName, FString KeyString)
{
	if (GConfig)
	{
		const FString categoryString = GetINIStringFromCategory(INICategory);
		GConfig->RemoveKey(*SectionName, *KeyString, categoryString);
		GConfig->Flush(false, categoryString);
	}
}

FString UMissingBlueprintFunctions::GetSteamUsername()
{
	return TEXT("<Buddy>: WIP come back later ^_^");
}

FString UMissingBlueprintFunctions::GetINIStringFromCategory(const EINICategory& INICategory) const
{
	switch (INICategory)
	{
		case EINICategory::INI_Game:
			return GGameIni;

		case EINICategory::INI_Input:
			return GInputIni;

		case EINICategory::INI_Scalability:
			return GScalabilityIni;

		case EINICategory::INI_UserSettings:
			return GGameUserSettingsIni;
	}

	return TEXT("");
}

// EoF