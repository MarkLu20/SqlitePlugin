// Fill out your copyright notice in the Description page of Project Settings.

#include "MKSqliteConnection.h"
#include "MKSqliteParameter.h"
#include "MKSqliteDataReader.h"
#include "MKSQLiteCommand.h"
#include "sqlite3.h"

MKSQLiteConnection::MKSQLiteConnection(const FString& InConnectString)
{
	ConnectString = InConnectString.Replace(TEXT("/"), TEXT("\\"));
	db = NULL;
}

MKSQLiteConnection::~MKSQLiteConnection()
{
	Close();
}

bool MKSQLiteConnection::Open() {
	return sqlite3_open(TCHAR_TO_UTF8(*ConnectString), &db) == SQLITE_OK;
}

void MKSQLiteConnection::Close() {
	if (db != NULL) {
		sqlite3_close(db);
		db = NULL;
	}
}

TSharedPtr<IMKDatabaseCommand> MKSQLiteConnection::CreateCommand(const FString& InSQL, const TArray<TSharedPtr<IMKDatabaseParameter>>& InParams) {
	
	TSharedPtr<IMKDatabaseCommand> command = MakeShareable(new MKSQLiteCommand(AsShared()));
	command->Reset(InSQL, InParams);
	return command;
}

TSharedPtr<IMKDatabaseParameter> MKSQLiteConnection::CreateParameter(const FString& name) {
	return MakeShareable(new MKSQLiteParameter(name));
}