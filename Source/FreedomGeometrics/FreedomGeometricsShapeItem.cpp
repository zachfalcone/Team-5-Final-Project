// Fill out your copyright notice in the Description page of Project Settings.

#include "FreedomGeometrics.h"
#include "FreedomGeometricsShapeItem.h"


// Sets default values
AFreedomGeometricsShapeItem::AFreedomGeometricsShapeItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
    //StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    
    OnActorBeginOverlap.AddDynamic(this, &AFreedomGeometricsShapeItem::OnOverlapBegin);
}

void AFreedomGeometricsShapeItem::OnOverlapBegin(AActor* MyOverlappedActor, AActor* OtherActor)
{
    // Set static mesh of player to static mash of actor for a constant amount of time
    
    // Destroy();
}

// Called when the game starts or when spawned
void AFreedomGeometricsShapeItem::BeginPlay()
{
	Super::BeginPlay();
	
    StartLocation = GetActorLocation();

	int temp_x = StartLocation.X / 3;
	int temp_y = StartLocation.Y / 3;

	temp_x %= 360;
	temp_y %= 360;

	SinOffset = temp_x + temp_y;

	FRotator ActorRotation = GetActorRotation();
	ActorRotation.Yaw += SinOffset;
	SetActorRotation(ActorRotation);
}

// Called every frame
void AFreedomGeometricsShapeItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    AnimationCount += DeltaTime * AnimationSpeed;

	if (AnimationCount > 360) AnimationCount -= 360;

	int WaveFunction = AnimationCount + SinOffset;
	float SinWave = FMath::Sin(FMath::DegreesToRadians(WaveFunction));

	// ROTATION
	FRotator ActorRotation = GetActorRotation();
	ActorRotation.Yaw += RotationSpeed;
	SetActorRotation(ActorRotation);

	// OSCILLATION
	FVector NewLocation = StartLocation;
	NewLocation.Z += SinWave * OscillateRange;
	SetActorLocation(NewLocation);
}
