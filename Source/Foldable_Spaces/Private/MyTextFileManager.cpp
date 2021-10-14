// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTextFileManager.h"
#include "Misc/FileHelper.h"
#include "HAL/PlatformFilemanager.h"

bool UMyTextFileManager::SaveArrayText(FString SaveDirectory, FString FileName, TArray<FString> SaveText, bool AllowOverwriting = false)
{
	// Set complete path
	SaveDirectory += "\\";
	SaveDirectory += FileName; 

	if (!AllowOverwriting)
	{
		if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*SaveDirectory))
		{
			return false;
		}
	}
	FString FinalString = "";
	for (FString& Each : SaveText)
	{
		FinalString += Each; 
		FinalString += LINE_TERMINATOR;
	}
	return FFileHelper::SaveStringToFile(FinalString, *SaveDirectory);
}