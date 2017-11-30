// Fill out your copyright notice in the Description page of Project Settings.

#include "MKDBConnection.h"

void UMKDBConnection::Initialize(TSharedPtr<IMKDatabaseConnection> connection)
{
	if (!connection.IsValid()) return;

	DBConnection = connection;

	Open();

	if (isOpen)
	{
		TArray<TSharedPtr<IMKDatabaseParameter>> parameters;
		DBCommand = DBConnection->CreateCommand("", parameters);
	}
}

void UMKDBConnection::Close()
{
	if (!DBConnection.IsValid() | !isOpen)	return;

	DBConnection->Close();
	isOpen = false;
}

void UMKDBConnection::Open()
{
	if (!DBConnection.IsValid())
	{
		isOpen = false;
		return;
	}

	if (isOpen)
		return;

	isOpen = DBConnection->Open();;
}

bool UMKDBConnection::ExcuteNoQuery(FString SQLCommand)
{
	if (!DBConnection.IsValid() | !isOpen)	return false;

	TArray<TSharedPtr<IMKDatabaseParameter>> params;
	DBCommand->Reset(SQLCommand, params);
	return DBCommand->ExecuteNonQuery();
}

UMKDBReader* UMKDBConnection::ExcuteReader(FString SQLCommand)
{
	if (!DBConnection.IsValid() | !isOpen)	return NULL;
	TArray<TSharedPtr<IMKDatabaseParameter>> params;
	DBCommand->Reset(SQLCommand, params);

	TSharedPtr<IMKDatabaseReader> ireader = DBCommand->ExecuteReader();
	if (!ireader.IsValid()) return NULL;


	UMKDBReader* reader = NewObject<UMKDBReader>();
	reader->Initialize(ireader);

	return reader;
}