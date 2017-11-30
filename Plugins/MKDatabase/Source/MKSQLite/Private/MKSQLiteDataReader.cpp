// Fill out your copyright notice in the Description page of Project Settings.

#include "MKSqliteDataReader.h"
#include "sqlite3.h"

MKSQLiteDataReader::MKSQLiteDataReader(sqlite3_stmt* InStmt)
	: mStmt(InStmt)
{
}

MKSQLiteDataReader::~MKSQLiteDataReader()
{
	mStmt = NULL;
}

bool MKSQLiteDataReader::MoveNext() {
	if (mStmt == NULL)
		return false;

	if (sqlite3_step(mStmt) == SQLITE_ROW)
		return true;

	mStmt = NULL;
	return false;
}

void MKSQLiteDataReader::GetBlob(int InColumn, TArray<BYTE>& OutBlob) {
	OutBlob.Empty();

	if (mStmt == NULL)
		return;

	if (InColumn < 0 || InColumn >= sqlite3_column_count(mStmt))
		return;

	if (sqlite3_column_type(mStmt, InColumn) != SQLITE_BLOB)
		return;

	int size = sqlite3_column_bytes(mStmt, InColumn);
	if (size <= 0)
		return;

	OutBlob.AddUninitialized(size);
	BYTE* data = (BYTE*)sqlite3_column_blob(mStmt, InColumn);
	memcpy(OutBlob.GetData(), data, size);
}

int MKSQLiteDataReader::GetInt(int InColumn) {
	if (mStmt == NULL)
		return NULL;
	
	if (InColumn < 0 || InColumn >= sqlite3_column_count(mStmt))
		return NULL;

	if (sqlite3_column_type(mStmt, InColumn) != SQLITE_INTEGER)
		return NULL;

	return sqlite3_column_int(mStmt, InColumn);
}

const unsigned char * MKSQLiteDataReader::GetText(int InColumn) {
	if (mStmt == NULL)
		return NULL;

	if (InColumn < 0 || InColumn >= sqlite3_column_count(mStmt))
		return NULL;

	if (sqlite3_column_type(mStmt, InColumn) != SQLITE_TEXT)
		return NULL;
	
	return sqlite3_column_text(mStmt, InColumn);
}

