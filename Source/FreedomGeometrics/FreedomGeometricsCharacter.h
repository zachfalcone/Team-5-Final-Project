// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/Character.h"
#include "FreedomGeometricsCharacter.generated.h"

UCLASS(config = Game)
class AFreedomGeometricsCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

public:
	AFreedomGeometricsCharacter();

	virtual void Tick(float DeltaTime) override;

	float MinSpinSpeed = 1;
	float MaxSpinSpeed = 10;
	float SpinAcceleration = 0.025;
	float CurrentSpinSpeed = MinSpinSpeed;

	FVector CurrentLocation;
	FVector PreviousLocation;

	UFUNCTION(BlueprintPure, Category = "C++ Functions")
	float GetCurrentSpinSpeed();

	UFUNCTION(BlueprintPure, Category = "C++ Functions")
	FVector GetDeltaLocation();

	void UpdateSpinSpeed();
	void UpdateDeltaLocation();

	void Fire();
	void BeginFire();
	void EndFire();

	bool IsFiring = false;
	float FireDelaySeconds = 0.15;
	float TimeSinceLastShotFired = 0;

	bool ReadyToSpawnProjectile = false;
	FVector AimDirection;

	UFUNCTION(BlueprintPure, Category = "C++ Functions")
	FVector GetAimDirection();

	UFUNCTION(BlueprintPure, Category = "C++ Functions")
	bool IsProjectileReady();

	UFUNCTION(BlueprintCallable, Category = "C++ Functions")
	void SetReadyToSpawnProjectile(bool b);

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	class USoundBase* FireSound;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseLookUpRate;


protected:

	void OnResetVR();

	void MoveForward(float Value);
	void MoveRight(float Value);

	void TurnAtRate(float Rate);
	void LookUpAtRate(float Rate);

	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

