// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "MoveComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CPPTUTORIAL_API UMoveComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMoveComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


private:
	friend class FMoveComponentVisualizer;
	
	UPROPERTY(EditAnywhere) FVector Offset;
	UPROPERTY(EditAnywhere) float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess)) bool MoveEnabled;

	FVector StartPosition;
	FVector OffsetNormalized;
	float MaxDistance;
	float CurrentDistance;
	int Direction = 1;
};
