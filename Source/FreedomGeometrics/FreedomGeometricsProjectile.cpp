// Fill out your copyright notice in the Description page of Project Settings.

#include "FreedomGeometrics.h"
#include "FreedomGeometricsProjectile.h"


// Sets default values
AFreedomGeometricsProjectile::AFreedomGeometricsProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFreedomGeometricsProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFreedomGeometricsProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

