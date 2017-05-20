// Fill out your copyright notice in the Description page of Project Settings.

#include "FreedomGeometrics.h"
#include "FreedomGeometricsEnemy.h"


// Sets default values
AFreedomGeometricsEnemy::AFreedomGeometricsEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Get EnemyLight
    EnemyLight = CreateDefaultSubobject<UPointLightComponent>(FName("PointLightE"));
}

// Called when the game starts or when spawned
void AFreedomGeometricsEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFreedomGeometricsEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TimeSinceLastAttack += DeltaTime;
}

// Called to bind functionality to input
void AFreedomGeometricsEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AFreedomGeometricsEnemy::AttackedPlayer()
{
	TimeSinceLastAttack = 0;
}

bool AFreedomGeometricsEnemy::IsReadyToAttack()
{
	return TimeSinceLastAttack > SecondsPerAttack;
}
int AFreedomGeometricsEnemy::getHealth()
{
	return Health;
}

void AFreedomGeometricsEnemy::isHit(int damageValue)
{
	Health -= damageValue;
	
	if(Health < 0) Health = 0;
    
    float healthRatio = (float)Health / (float)100;
    
    if (healthRatio > 1) healthRatio = 1;
    else if (healthRatio < 0) healthRatio = 0;
    
    // Make health color
    FLinearColor HealthColor;
    HealthColor.R = (1 - healthRatio);
    HealthColor.G = healthRatio;
    HealthColor.B = 0.0f;
    HealthColor.A = 1;

    if (EnemyLight) {
        EnemyLight->SetLightColor(HealthColor, 0);
    }
}
