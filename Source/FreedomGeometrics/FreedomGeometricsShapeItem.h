// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "FreedomGeometricsShapeItem.generated.h"

UCLASS()
class FREEDOMGEOMETRICS_API AFreedomGeometricsShapeItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFreedomGeometricsShapeItem();

    UFUNCTION()
    void OnOverlapBegin(AActor* MyOverlappedActor, AActor* OtherActor);
    
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    
    float RotationSpeed = 0.5;
	float OscillateRange = 10;

    //UStaticMeshComponent* StaticMeshComponent;
    
private:
	FVector StartLocation;

	float AnimationCount = 0;
	float AnimationSpeed = 100;
	int SinOffset = 0;
};
