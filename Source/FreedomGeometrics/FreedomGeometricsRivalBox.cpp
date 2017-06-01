// Fill out your copyright notice in the Description page of Project Settings.

#include "FreedomGeometrics.h"
#include "FreedomGeometricsRivalBox.h"


// Sets default values
AFreedomGeometricsRivalBox::AFreedomGeometricsRivalBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AFreedomGeometricsRivalBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFreedomGeometricsRivalBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    
    secondsAfterShooting += DeltaTime;

    if (bCanShoot && GetDistance() < HitRadius && secondsAfterShooting >= FireDelaySeconds) {
        bSpawnProjectile = true;
        secondsAfterShooting = 0.0;
    }
}

float AFreedomGeometricsRivalBox::GetDistance()
{
    ACharacter* Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
    
    float distance = (Player->GetActorLocation() - Box->GetActorLocation()).Size();
    
    if (distance < 0) // absolute value
        distance = 0 - distance;
    
    return distance;
}
