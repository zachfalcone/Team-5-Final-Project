// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "FreedomGeometricsRivalBox.generated.h"

UCLASS()
class FREEDOMGEOMETRICS_API AFreedomGeometricsRivalBox : public APawn
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFreedomGeometricsRivalBox();
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Attacking)
    bool bCanShoot = true;
    
    float secondsAfterShooting = 0.0;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Attacking)
    AFreedomGeometricsRivalBox* Box;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Attacking)
    float FireDelaySeconds = 1.0;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Attacking)
    bool bSpawnProjectile = false;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Attacking)
    float HitRadius = 500;
    
    // No health because box is indestructable
    
    // AI
    UPROPERTY(EditAnywhere, Category = Behavior)
    class UBehaviorTree* BoxBehavior;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
    UFUNCTION()
    float GetDistance();
};
