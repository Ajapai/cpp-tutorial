// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveComponentVisualizer.h"

#include "MoveComponent.h"


void FMoveComponentVisualizer::DrawVisualization(const UActorComponent* Component, const FSceneView* View,
                                                 FPrimitiveDrawInterface* PDI)
{
	const UMoveComponent* MoveComponent = Cast<UMoveComponent>(Component);

	if (!MoveComponent)
	{
		return;
	}

	PDI->DrawLine(
		MoveComponent->GetRelativeLocation(),
		MoveComponent->GetRelativeLocation() + MoveComponent->Offset,
		FLinearColor::Red,
		SDPG_Foreground,
		2.f);
}
