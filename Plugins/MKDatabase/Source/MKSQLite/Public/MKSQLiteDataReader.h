// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MKSQLite.h"

struct sqlite3_stmt;

/**
 * 
 */
class MKSQLITE_API MKSQLiteDataReader : public IMKDatabaseReader, public TSharedFromThis<MKSQLiteDataReader>
{
public:
	MKSQLiteDataReader();
	MKSQLiteDataReader(sqlite3_stmt* InStmt);
	~MKSQLiteDataReader();

	virtual bool MoveNext() override;

	virtual void GetBlob(int InColumn, TArray<BYTE>& OutBlob) override;

	virtual int GetInt(int InColumn) override;

	virtual const unsigned char * GetText(int InColumn) override;
	
private:
	friend class MKSQLiteConnection;
	friend class MKSQLiteCommand;

private:
	sqlite3_stmt* mStmt;
};
