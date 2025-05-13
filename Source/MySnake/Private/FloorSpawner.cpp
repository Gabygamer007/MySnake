// Fill out your copyright notice in the Description page of Project Settings.


#include "FloorSpawner.h"
#include "Engine/World.h"
#include "TimerManager.h"

// Sets default values
AFloorSpawner::AFloorSpawner()
{
	PrimaryActorTick.bCanEverTick = false;

}

void AFloorSpawner::BeginPlay()
{
	Super::BeginPlay();

	if (BlockClass) {
		CurrentRow = 0;
		CurrentCol = 0;
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AFloorSpawner::SpawnNextBlock, SpawnDelay, true);
	}
	
}

void AFloorSpawner::SpawnNextBlock() 
{
	if (CurrentRow >= Rows) {
		GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
		return;
	}
	
	FVector Location = FVector(CurrentCol * BlockSize + 50.0f, CurrentRow * BlockSize + 50.0f, 0.f);
	GetWorld()->SpawnActor<AActor>(BlockClass, Location, FRotator::ZeroRotator);

	++CurrentCol;
	if (CurrentCol >= Cols) {
		CurrentCol = 0;
		++CurrentRow;
	}
}

