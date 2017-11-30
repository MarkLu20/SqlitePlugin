// Fill out your copyright notice in the Description page of Project Settings.

#include "MKDatabaseFunctionLibrary.h"
#include "ModuleManager.h"
#include "Paths.h"

UMKDBConnection* UMKDatabaseFunctionLibrary::OpenDatabase(FString OpenString, FString DatabaseType)
{
	IMKDatabaseModule& DBModule = FModuleManager::Get().LoadModuleChecked<IMKDatabaseModule>(*DatabaseType);
	TSharedPtr<IMKDatabaseConnection> iconnection = DBModule.CreateConnection(OpenString);

	if (!iconnection.IsValid())	return NULL;

	UMKDBConnection* connection = NewObject<UMKDBConnection>();
	connection->Initialize(iconnection);

	return connection;
}


