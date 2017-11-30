// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MKSQLite.h"

class MKSQLiteConnection;
class MKSQLiteParameter;
class MKSQLiteDataReader;

/**
 * 
 */
class MKSQLITE_API MKSQLiteCommand : public IMKDatabaseCommand, public TSharedFromThis<MKSQLiteCommand>
{
public:
	MKSQLiteCommand() {}
	MKSQLiteCommand(const TSharedRef<MKSQLiteConnection>& InConn);
	~MKSQLiteCommand();

public:

	virtual void Reset(const FString& InSQL, const TArray<TSharedPtr<IMKDatabaseParameter>>& InParams) override;

	virtual bool ExecuteNonQuery() override;
	virtual TSharedPtr<IMKDatabaseReader> ExecuteReader() override;

public:
	FString Command;
	TArray<TSharedPtr<IMKDatabaseParameter>> Parameters;

private:
	int Prepare(sqlite3_stmt*& OutStmt);

	TSharedRef<MKSQLiteConnection> mConn;
};
