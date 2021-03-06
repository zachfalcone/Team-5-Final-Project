// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "FreedomGeometricsEnemy.generated.h"

UCLASS()
class FREEDOMGEOMETRICS_API AFreedomGeometricsEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFreedomGeometricsEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "C++ Functions")
	void AttackedPlayer();

	UFUNCTION(BlueprintCallable, Category = "C++ Functions")
	bool IsReadyToAttack();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "C++ Variables")
	float SecondsPerAttack = 1;

	float TimeSinceLastAttack = 0;

	int Health = 100;

	UFUNCTION(BlueprintPure, Category = "C++ Functions")
	int getHealth();

	UFUNCTION(BlueprintCallable, Category = "C++ Functions")
	void isHit(int damageValue);
    
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HealthLight")
    UPointLightComponent* EnemyLight;
};
