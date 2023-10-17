// Fill out your copyright notice in the Description page of Project Settings.


#include "moverect2.h"
#include "Public/Tools/interface_play_obj.h"//해당인터페이스 경로를 include 해준다.
#include "switch.h"

// Sets default values
Amoverect2::Amoverect2() : m_LocX(0), m_LocZ(0), m_MoveType(EN_MoveTypeCode::Moveright), m_isplay2(false)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRootRoot3"));
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mymyMesh3"));
	SetRootComponent(Scene);
	StaticMesh->AttachToComponent(Scene, FAttachmentTransformRules::KeepRelativeTransform);

}

// Called when the game starts or when spawned
void Amoverect2::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(m_Switch))
		m_Switch->FDele_EventOverlap.AddDynamic(this, &Amoverect2::EventOverlap);
	
}

// Called every frame
void Amoverect2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (m_isplay2 == false)
		return;

	switch (m_MoveType)
	{
	case EN_MoveTypeCode::Moveright:
		m_LocX += 2;
		StaticMesh->SetRelativeLocation(FVector(m_LocX, 0, m_LocZ));
		if (m_LocX >= 200)
		{
			m_MoveType = EN_MoveTypeCode::Moveup;
		}
		break;
	case EN_MoveTypeCode::Moveup:
		m_LocZ += 2;
		StaticMesh->SetRelativeLocation(FVector(m_LocX, 0, m_LocZ));
		if (m_LocZ >= 200)
		{
			m_MoveType = EN_MoveTypeCode::Moveleft;
		}
		break;
	case EN_MoveTypeCode::Moveleft:
		m_LocX -= 2;
		StaticMesh->SetRelativeLocation(FVector(m_LocX, 0, m_LocZ));
		if (m_LocX <= 0)
		{
			m_MoveType = EN_MoveTypeCode::Movedown;
		}
		break;
	case EN_MoveTypeCode::Movedown:
		m_LocZ -= 2;
		StaticMesh->SetRelativeLocation(FVector(m_LocX, 0, m_LocZ));
		if (m_LocZ <= 0)
		{
			m_MoveType = EN_MoveTypeCode::Moveright;
		}
		break;
	}
}

void Amoverect2::EventOverlap(bool IsBegin)
{
	m_isplay2 = IsBegin;
}

void Amoverect2::Code_DoPlay_Implementation(bool isplay)
{
	m_isplay2 = isplay;
}

