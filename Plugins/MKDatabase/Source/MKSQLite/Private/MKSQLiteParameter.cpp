// Fill out your copyright notice in the Description page of Project Settings.

#include "MKSqliteParameter.h"
#include "sqlite3.h"

void MKSQLiteParameterIntData::Bind(const FString& InName, sqlite3_stmt* InStmt) {
	int index = sqlite3_bind_parameter_index(InStmt, TCHAR_TO_UTF8(*InName));
	if (index == 0)
		return;

	sqlite3_bind_int(InStmt, index, Value);
}

void MKSQLiteParameterStringData::Bind(const FString& InName, sqlite3_stmt* InStmt) {
	int index = sqlite3_bind_parameter_index(InStmt, TCHAR_TO_UTF8(*InName));
	if (index == 0)
		return;

	char* data = TCHAR_TO_UTF8(*Value);
	sqlite3_bind_text(InStmt, index, data, strlen(data), NULL);
}