// Fill out your copyright notice in the Description page of Project Settings.

#include "FreedomGeometrics.h"
#include "RivalBox_AI.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "FreedomGeometricsRivalBox.h"

ARivalBox_AI::ARivalBox_AI()
{
    BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));
    
    BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));
}

void ARivalBox_AI::Possess(APawn* InPawn)
{
    Super::Possess(InPawn);
    
    AFreedomGeometricsRivalBox* Character = Cast<AFreedomGeometricsRivalBox>(InPawn);
    
    if (Character != NULL && Character->BoxBehavior != NULL)
    {
        BlackboardComp->InitializeBlackboard(*Character->BoxBehavior->BlackboardAsset);
        
        BoxKeyID = BlackboardComp->GetKeyID("Target");
        
        BehaviorComp->StartTree(*Character->BoxBehavior);
    }
}
