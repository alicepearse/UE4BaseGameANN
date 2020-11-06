// Fill out your copyright notice in the Description page of Project Settings.


#include "TextFileManager.h"
#include "Misc/FileHelper.h"
#include "HAL/PlatformFilemanager.h"
#include "Math/Vector4.h"



bool UTextFileManager::SaveArrayText(FString SaveDirectory, FString FileName, TArray<FString> SaveText, bool AllowOverWriting) 
{
	SaveDirectory += "\\";
    SaveDirectory += FileName;

    if(!AllowOverWriting)
    {
        if(FPlatformFileManager::Get().GetPlatformFile().FileExists(*SaveDirectory))
        {
            return false;
        }
    }

    FString FinalString = "";
    for(FString& Each : SaveText)
    {
        FinalString += Each;
        FinalString += LINE_TERMINATOR;
    }

    return FFileHelper::SaveStringToFile(FinalString, *SaveDirectory); 
}

void UTextFileManager::MakeFloatsToString(float VelocityX, float VelocityY, float LocationX, float LocationY, FString& VelocityXstr, FString& VelocityYstr, FString& LocationXstr, FString& LocationYstr) 
{
	VelocityXstr = FString::SanitizeFloat(VelocityX);
    VelocityYstr = FString::SanitizeFloat(VelocityY);
    LocationXstr = FString::SanitizeFloat(LocationX);
    LocationYstr = FString::SanitizeFloat(LocationY);
}

void UTextFileManager::Float4ToString(float VelocityX, float VelocityY, float LocationX, float LocationY, FString& StringArray) 
{
    StringArray = FString::Printf(TEXT("%f, %f, %f, %f"), VelocityX, VelocityY, LocationX, LocationY);
}

void UTextFileManager::Float2ToString(float LocationX, float LocationY, FString& Floatstr) 
{
	Floatstr = FString::Printf(TEXT("%f, %f"), LocationX, LocationY);
}

// FString UTextFileManager::MakeVector4String(float VelocityX, float VelocityY, float LocationX, float LocationY) 
// {
// 	FString Vector4String;
//     FString VelocityXstr = FString::SanitizeFloat(VelocityX);
//     // Vector4String.Add(VelocityXstr);
//     FString VelocityYstr = FString::SanitizeFloat(VelocityY);
//     // Vector4String.Add(VelocityYstr);
//     FString LocationXstr = FString::SanitizeFloat(LocationX);
//     // Vector4String.Add(LocationXstr);
//     FString LocationYstr = FString::SanitizeFloat(LocationY);
//     // Vector4String.Add(LocationYstr);
//     // return Vector4String;
//     // FString Vector4String = (VelocityX, VelocityY, LocationX, LocationY).ToString();
// }

// bool UTextFileManager::Vector4ToString(FVector4 Vector4) 
// {
// 	FString Vector4String = Vector4.ToString();
//     return Vector4String;
// }

// FString UTextFileManager::Vector4ToString(FVector4 Vector4) 
// {
// 	FString Vector4String = Vector4.ToString();
//     return Vector4String;
// }

// FString UTextFileManager::Vector4ArrayToString(TArray<FVector4> Vector4Array) 
// {
//     for (index = 0; index < Vector4Array.Length; ++index)
//     {
//         FVector Vector4String = Vector4Array[index].ToString();
//         Vector4StringArray.
//     }
// 	// FString Vector4StringArray = Vector4.ToString();
    
//     return Vector4StringArray;
// }