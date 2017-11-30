// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "MKSqlite.h"
#include "Core.h"
#include "ModuleManager.h"
#include "IPluginManager.h"
#include "MKSQLiteConnection.h"  

#define LOCTEXT_NAMESPACE "FMKSQLiteModule"

void FMKSQLiteModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	// Get the base directory of this plugin
	FString BaseDir = IPluginManager::Get().FindPlugin("MKDatabase")->GetBaseDir();

	// Add on the relative location of the third party dll and load it
	FString LibraryPath;
	LibraryPath = FPaths::Combine(*BaseDir, TEXT("Binaries/ThirdParty/MKSqliteLibrary/Win64/sqlite3.dll"));

	//MessageBox(GetForegroundWindow(), L"asdf", *BaseDir, 1);

	SQLiteLibraryHandle = !LibraryPath.IsEmpty() ? FPlatformProcess::GetDllHandle(*LibraryPath) : nullptr;

}

void FMKSQLiteModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	// Free the dll handle
	FPlatformProcess::FreeDllHandle(SQLiteLibraryHandle);
	SQLiteLibraryHandle = nullptr;
}

TSharedPtr<IMKDatabaseConnection> FMKSQLiteModule::CreateConnection(const FString& InConnectString) {
	return MakeShareable(new MKSQLiteConnection(InConnectString));
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMKSQLiteModule, MKSQLite)