// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MKDatabase/Public/MKDatabase.h"
#include "MKDBReader.h"
#include "MKDBConnection.generated.h"

/**
 * 
 */
UCLASS()
class MKDATABASEEDIT_API UMKDBConnection : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "MKDatabaseLibrary")
		void Close();

	UFUNCTION(BlueprintCallable, Category = "MKDatabaseLibrary")
		void Open();

	UFUNCTION(BlueprintCallable, Category = "MKDatabaseLibrary")
		bool ExcuteNoQuery(FString SQLCommand);

	UFUNCTION(BlueprintCallable, Category = "MKDatabaseLibrary")
		UMKDBReader* ExcuteReader(FString SQLCommand);

public:
	void Initialize(TSharedPtr<IMKDatabaseConnection> connection);

private:
	bool isOpen = false;
	TSharedPtr<IMKDatabaseConnection> DBConnection;
	TSharedPtr<IMKDatabaseCommand> DBCommand;	
};
