// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloorSpawner.generated.h"

UCLASS()
class MYSNAKE_API AFloorSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloorSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	
	UPROPERTY(EditAnywhere, Category = "Floor")
	TSubclassOf<AActor> BlockClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> BlockClass;

	UPROPERTY(EditAnywhere)
	int32 Rows = 8;

	UPROPERTY(EditAnywhere)
	int32 Cols = 16;

	UPROPERTY(EditAnywhere)
	float BlockSize = 100.0f;

	UPROPERTY(EditAnywhere)
	float SpawnDelay = 0.05f;

	int32 CurrentRow = 0;
	int32 CurrentCol = 0;

	FTimerHandle TimerHandle;
	void SpawnNextBlock();
	

};
