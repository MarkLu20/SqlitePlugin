// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ModuleManager.h"
#include "MKDatabase/Public/MKDatabase.h"

class FMKSQLiteModule : public IMKDatabaseModule
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	virtual TSharedPtr<IMKDatabaseConnection> CreateConnection(const FString& InConnectString) override;

private:
	/** Handle to the test dll we will load */
	void*	SQLiteLibraryHandle;
};