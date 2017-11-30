// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDataFile.h"

FString UOpenDataFile::OpenDataFile(FString _path)
{
	FString data = FPaths::GameDir() / *_path;
	return data;
}
