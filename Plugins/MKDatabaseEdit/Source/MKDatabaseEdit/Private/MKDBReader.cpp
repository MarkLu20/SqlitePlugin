// Fill out your copyright notice in the Description page of Project Settings.

#include "MKDBReader.h"

void UMKDBReader::Initialize(TSharedPtr<IMKDatabaseReader> reader)
{
	DBReader = reader;
}

bool UMKDBReader::MoveNext()
{
	if (DBReader.IsValid())
		return DBReader->MoveNext();
	return false;
}

int UMKDBReader::GetInt(int InColumn)
{
	return DBReader->GetInt(InColumn);
}

FString UMKDBReader::GetText(int InColumn)
{
	const unsigned char * str = DBReader->GetText(InColumn);

	return FString(UTF8_TO_TCHAR(str));
}

TArray<UINT8> UMKDBReader::GetBlob(int InColumn)
{
	TArray<UINT8> Out;
	DBReader->GetBlob(InColumn, Out);

	return Out;
}