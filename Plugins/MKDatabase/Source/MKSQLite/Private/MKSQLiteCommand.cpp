// Fill out your copyright notice in the Description page of Project Settings.

#include "MKSqliteCommand.h"
#include "MKSqliteConnection.h"
#include "MKSqliteDataReader.h"
#include "MKSqliteParameter.h"
#include "sqlite3.h"

MKSQLiteCommand::MKSQLiteCommand(const TSharedRef<MKSQLiteConnection>& InConn)
	:mConn(InConn)
{
}

MKSQLiteCommand::~MKSQLiteCommand()
{
}

void MKSQLiteCommand::Reset(const FString& InSQL, const TArray<TSharedPtr<IMKDatabaseParameter>>& InParams) {
	Command = InSQL;
	Parameters = InParams;
}

bool MKSQLiteCommand::ExecuteNonQuery() {
	if (mConn->db == NULL)
		return false;

	sqlite3_stmt* stmt = NULL;
	int code = Prepare(stmt);
	if (code != MKSQLITE_OK)
		return false;

	sqlite3_step(stmt);
	return true;
}

TSharedPtr<IMKDatabaseReader> MKSQLiteCommand::ExecuteReader() {
	sqlite3_stmt* stmt = NULL;
	int code = Prepare(stmt);
	if (code != MKSQLITE_OK)
		return NULL;

	return MakeShareable(new MKSQLiteDataReader(stmt));
}

int MKSQLiteCommand::Prepare(sqlite3_stmt*& OutStmt) {
	ANSICHAR* cmd = TCHAR_TO_UTF8(*Command);
	int code = sqlite3_prepare(mConn->db, cmd, strlen(cmd), &OutStmt, NULL);
	if (code != MKSQLITE_OK)
		return code;

	for (int i = 0; i < Parameters.Num(); ++i) {
		TSharedPtr<IMKDatabaseParameter> param = Parameters[i];
		if (!param.IsValid())
			continue;

		((MKSQLiteParameter*)param.Get())->Bind(OutStmt);
	}

	return MKSQLITE_OK;
}