// Fill out your copyright notice in the Description page of Project Settings.

#include "FreedomGeometrics.h"
#include "BTService_CheckForPlayer.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "FreedomGeometricsRivalBox.h"

#include "RivalBox_AI.h"
#include "FreedomGeometricsCharacter.h"

UBTService_CheckForPlayer::UBTService_CheckForPlayer()
{
    bCreateNodeInstance = true;
}

void UBTService_CheckForPlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    ARivalBox_AI* BoxPC = Cast<ARivalBox_AI>(OwnerComp.GetAIOwner());
    
    if (BoxPC)
    {
        AFreedomGeometricsCharacter* Box = Cast<AFreedomGeometricsCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
        
        if (Box)
        {
            OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(BoxPC->BoxKeyID, Box);
        }
    }
}
