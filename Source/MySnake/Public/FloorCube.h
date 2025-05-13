// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloorCube.generated.h"

UCLASS()
class MYSNAKE_API AFloorCube : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloorCube();

protected:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;
};
