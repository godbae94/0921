// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "moverect.generated.h"

UCLASS()
class UNREALCODE_API Amoverect : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Amoverect();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	USceneComponent* Scene;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh;

	float LocX;
	float LocZ;

	enum MoveType
	{
		right=0,
		up,
		left,
		down
	};



};
