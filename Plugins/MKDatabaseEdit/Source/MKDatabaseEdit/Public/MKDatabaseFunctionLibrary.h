// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MKDBConnection.h"
#include "MKDatabaseFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class MKDATABASEEDIT_API UMKDatabaseFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, Category = "MKDatabaseLibrary")
	static UMKDBConnection* OpenDatabase(FString OpenString, FString DatabaseType);	
};
