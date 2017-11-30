// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleInterface.h"

class IMKDatabaseParameter {
public:
	virtual ~IMKDatabaseParameter() {}

	virtual void SetInt(int InValue) = 0;
	virtual void SetString(const FString& InValue) = 0;
};

class IMKDatabaseReader {
public:
	virtual ~IMKDatabaseReader() {}
	
	virtual bool MoveNext() = 0;
	virtual void GetBlob(int InColumn, TArray<BYTE>& OutBlob) = 0;
	virtual int GetInt(int InColumn) = 0;
	virtual const unsigned char * GetText(int InColumn) = 0;
};

class IMKDatabaseCommand {
public:
	virtual ~IMKDatabaseCommand() {}

	virtual void Reset(const FString& InSQL, const TArray<TSharedPtr<IMKDatabaseParameter>>& InParams) = 0;

	virtual bool ExecuteNonQuery() = 0;
	virtual TSharedPtr<IMKDatabaseReader> ExecuteReader() = 0;
};

class IMKDatabaseConnection {
public:
	virtual ~IMKDatabaseConnection() {}

	virtual bool Open() = 0;
	virtual void Close() = 0;

	virtual TSharedPtr<IMKDatabaseCommand> CreateCommand(const FString& InSQL, const TArray<TSharedPtr<IMKDatabaseParameter>>& InParams) = 0;

	virtual TSharedPtr<IMKDatabaseParameter> CreateParameter(const FString& name) = 0;
};

class IMKDatabaseModule : public IModuleInterface {
public:
	virtual TSharedPtr<IMKDatabaseConnection> CreateConnection(const FString& InConnectString) = 0;
};