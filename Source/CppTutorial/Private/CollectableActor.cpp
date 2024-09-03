// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectableActor.h"

// Sets default values
ACollectableActor::ACollectableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = StaticMeshComponent;

}

void ACollectableActor::Jump(const float Velocity)
{
	StaticMeshComponent->AddImpulse({0.f, 0.f, Velocity * 500.f});
}

void ACollectableActor::JumpAndDestroy(const float Velocity)
{
	Jump(Velocity);
	GetWorld()->GetTimerManager().SetTimer(
		TimerHandle,
		[this]
		{
			Destroy();
		},
		2.f,
		false);
}

// Called when the game starts or when spawned
void ACollectableActor::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(TimerHandle, [this]{JumpAndDestroy(5);}, 4.f, false);
}

// Called every frame
void ACollectableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

