// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Paths.h"
#include "OpenDBData.generated.h"

/**
 * 
 */
UCLASS()
class DATAACESSSQLITE_API UOpenDBData : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

		UFUNCTION(BlueprintCallable, Category = "MKSQLITE")
		static FString OpenDBData(FString _path);
	
	
};
