// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Paths.h"
#include "OpenDataFile.generated.h"

/**
 * 
 */
UCLASS()
class MKSQLITE_API UOpenDataFile : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()


		UFUNCTION(BlueprintCallable, Category = "MKSQLITE")
		static FString OpenDataFile(FString	_path);
	
};
