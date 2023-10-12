// Fill out your copyright notice in the Description page of Project Settings.


#include "moverect.h"

// Sets default values
Amoverect::Amoverect(): LocX(0),LocZ(0)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRootRoot2"));

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mymyMesh2"));

	SetRootComponent(Scene);

	StaticMesh->AttachToComponent(Scene, FAttachmentTransformRules::KeepRelativeTransform);

}

// Called when the game starts or when spawned
void Amoverect::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Amoverect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//LocX += 2; , LocX -= 2;
	//Locz += 2; , Locz -= 2
	//StaticMesh->SetRelativeLocation(FVector(LocX, 0, 0));




}

