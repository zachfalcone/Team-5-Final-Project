// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "RivalBox_AI.generated.h"

/**
 * 
 */
UCLASS()
class FREEDOMGEOMETRICS_API ARivalBox_AI : public AAIController
{
	GENERATED_BODY()
	
	UPROPERTY(transient)
	class UBlackboardComponent* BlackboardComp;
	
    UPROPERTY(transient)
    class UBehaviorTreeComponent* BehaviorComp;
    
public:

    ARivalBox_AI();
    
    virtual void Possess(APawn* InPawn) override;
    
    uint8 BoxKeyID;
};
