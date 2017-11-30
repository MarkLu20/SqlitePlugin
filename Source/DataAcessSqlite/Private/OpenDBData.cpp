// Fill out your copyright notice in the Description page of Project Settings.

//#include "OpenDBData.h"
#include "../Public/OpenDBData.h"

FString UOpenDBData::OpenDBData(FString _path)
{
	FString data = FPaths::GameDir() / *_path;
	return data;
}
