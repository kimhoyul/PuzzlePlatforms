// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);

	MoveSpeed = 0.0f;
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);	
	}
}

void AMovingPlatform::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (HasAuthority()) // HasAuthority() 함수는 서버에서는 true, 클라이언트 에서는 false 를 내보낸다.
	{
		FVector Location = GetActorLocation();
		Location += FVector(MoveSpeed * DeltaSeconds,0,0);
		SetActorLocation(Location);
	}
}
