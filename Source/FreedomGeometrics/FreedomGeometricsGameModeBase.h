// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameModeBase.h"
#include "FreedomGeometricsGameModeBase.generated.h"

UCLASS()
class AFreedomGeometricsGameModeBase : public AGameMode
{
	GENERATED_BODY()
	
	
public:
	AFreedomGeometricsGameModeBase();

	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

protected:
	
};
