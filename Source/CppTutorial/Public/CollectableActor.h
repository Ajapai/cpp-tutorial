// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CollectableActor.generated.h"

UCLASS()
class CPPTUTORIAL_API ACollectableActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACollectableActor();

	UFUNCTION(BlueprintCallable)
	void Jump(float Velocity);
	void JumpAndDestroy(float Velocity);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere) UStaticMeshComponent* StaticMeshComponent;
	FTimerHandle TimerHandle;
};
