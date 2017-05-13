// Fill out your copyright notice in the Description page of Project Settings.

#include "FreedomGeometrics.h"
#include "FreedomGeometricsEnemy.h"


// Sets default values
AFreedomGeometricsEnemy::AFreedomGeometricsEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

void AFreedomGeometricsEnemy::AttackPlayer()
{
	TimeSinceLastAttack = 0;
}

bool AFreedomGeometricsEnemy::IsInRangeOfPlayer()
{
	return InRangeOfPlayer;
}

bool AFreedomGeometricsEnemy::IsReadyToAttack()
{
	return TimeSinceLastAttack > SecondsPerAttack;
}

void AFreedomGeometricsEnemy::SetInRangeOfPlayer(bool b)
{
	InRangeOfPlayer = b;
}

int AFreedomGeometricsEnemy::getHealth()
{
	return Health;
}

void AFreedomGeometricsEnemy::isHit(int damageValue)
{
	Health -= damageValue;
	
	if(Health < 0) Health = 0;
}