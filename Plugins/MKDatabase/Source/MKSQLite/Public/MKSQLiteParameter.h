// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MKSQLite.h"

enum MKSQLiteParameterDataType {
	kInt,
	kString,
};

class MKSQLiteParameterData{
public:
	virtual ~MKSQLiteParameterData() {}
	virtual MKSQLiteParameterDataType GetType() = 0;
	virtual void Bind(const FString& InName, struct sqlite3_stmt* InStmt) = 0;
};

class MKSQLiteParameterIntData : public MKSQLiteParameterData, public TSharedFromThis<MKSQLiteParameterIntData>{
public:
	int Value;
	virtual MKSQLiteParameterDataType GetType() override { return MKSQLiteParameterDataType::kInt; }
	virtual void Bind(const FString& InName, struct sqlite3_stmt* InStmt) override;
};

class MKSQLiteParameterStringData : public MKSQLiteParameterData, public TSharedFromThis<MKSQLiteParameterStringData> {
public:
	FString Value;
	virtual MKSQLiteParameterDataType GetType() override { return MKSQLiteParameterDataType::kString; }
	virtual void Bind(const FString& InName, struct sqlite3_stmt* InStmt) override;
};
/**
 * 
 */
class MKSQLiteParameter : public IMKDatabaseParameter, public TSharedFromThis<MKSQLiteParameter>
{
public:
	MKSQLiteParameter() {}

	MKSQLiteParameter(const FString& InName) {
		Name = InName;
	}

	void Bind(struct sqlite3_stmt* InStmt) {
		if (Data.IsValid()) {
			Data->Bind(Name, InStmt);
		}
	}

#define SetValue(Type) \
if (!Data.IsValid() || Data->GetType() != MKSQLiteParameterDataType::k##Type) {\
	Data = MakeShareable(new MKSQLiteParameter##Type##Data()); \
} \
((MKSQLiteParameter##Type##Data*)Data.Get())->Value = InValue

	virtual void SetInt(int InValue) override {
		SetValue(Int);
	}

	virtual void SetString(const FString& InValue) override {
		SetValue(String);
	}

#undef SetValue

public:
	FString Name;

	TSharedPtr<MKSQLiteParameterData> Data;
};
