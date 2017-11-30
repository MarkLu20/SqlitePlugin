// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MKDatabase/Public/MKDatabase.h"
#include "MKDBReader.generated.h"

/**
 * 
 */
UCLASS()
class MKDATABASEEDIT_API UMKDBReader : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "MKDatabaseLibrary")
		bool MoveNext();

	UFUNCTION(BlueprintCallable, Category = "MKDatabaseLibrary")
		int GetInt(int InColumn);

	UFUNCTION(BlueprintCallable, Category = "MKDatabaseLibrary")
		FString GetText(int InColumn);

	UFUNCTION(BlueprintCallable, Category = "MKDatabaseLibrary")
		TArray<UINT8> GetBlob(int InColumn);

public:
	void Initialize(TSharedPtr<IMKDatabaseReader> reader);

private:
	TSharedPtr<IMKDatabaseReader> DBReader;
};
