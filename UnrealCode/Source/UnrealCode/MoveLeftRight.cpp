// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveLeftRight.h"
#include "Public/Tools/interface_play_obj.h"
#include "switch.h"//switch���� include

// Sets default values
AMoveLeftRight::AMoveLeftRight() :m_LocX(0), m_ismoveright(1), m_isplay(false)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//CreateDefaultSubobject : new Ű����� ���� �𸮾󿡼� �������� ��ü�� �����ϴ� Ű����
	//TEXT : �𸮾󿡼� ����ϴ� ������ �߿� �ϳ�
	//<USceneComponent>(TEXT("SceneRootRoot")); // USceneComponent ��ü�� "SceneRootRoot"�̸����� �������� ����
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRootRoot"));
	//UStaticMeshComponent ��ü�� "mymyMesh" �̸����� �������� ����
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mymyMesh"));

	SetRootComponent(Scene);//Scene�� RootComponent�� �ø��ڴ�.
	//RootComponent = Scene;//Scene�� RootComponent�� �ø��ڴ�.

	//AttachToComponent : Component ���̱� ���
	//Scene�� ���δ�, ���� ��ǥ���� Scene ���ؿ� Relative(���) ��ǥ���
	StaticMesh->AttachToComponent(Scene, FAttachmentTransformRules::KeepRelativeTransform);

	//RootComponent�� ���δ�, ���� ��ǥ���� RootComponent ���ؿ� Relative(���) ��ǥ���
	//StaticMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	//UAsset ��������
	//ConstructorHelpers::FObjectFinder : ������Ʈ ������ ã�´�.
	//<UStaticMesh> : ã�� ���� Ÿ��
	//sm ã�Ƽ� ���� ��ü�̸� 
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> sm(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Props/SM_Chair.SM_Chair'"));

	//if (sm.Succeeded())// ���� �ҷ����� ���� ���� üũ
	//{
	//	StaticMesh->SetStaticMesh(sm.Object);//StaticMeshComponent�� StaticMesh ����
	//}



}

AMoveLeftRight::~AMoveLeftRight()
{
}

// Called when the game starts or when spawned
void AMoveLeftRight::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(m_Switch))//m_Switch�� �������̶�� �ؿ��ڵ带 �����Ѵ�.
		m_Switch->FDele_EventOverlap.AddDynamic(this, &AMoveLeftRight::EventOverlap);
	    //m_Switch�� FDele_EventOverlap�� ���ε��ϰڴ�.

}

// Called every frame
void AMoveLeftRight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);//�������̵��� �Լ��� ��� �θ��Լ��� �����Ѵ�

	if (m_isplay == false)
		return;
			
	//ismoveright; //�����Ϲ���
	//LocX += 1;//������
	//SetRelativeLocation : ������� ��ġ���� �����Ѵ�
	//FVector : �𸮾󿡼� ����ϴ� 3���� ��ǥ ����
		
	if (m_ismoveright)
	{
		m_LocX += 2.0f;
		StaticMesh->SetRelativeLocation(FVector(m_LocX, 0, 0));
		if (m_LocX >= 300)
		{
			m_ismoveright = false;
		}
	}
	else
	{
		m_LocX -= 2.0f;
		StaticMesh->SetRelativeLocation(FVector(m_LocX, 0, 0));
		if (m_LocX <= 0)
		{
			m_ismoveright = true;
		}
	}
		
}

void AMoveLeftRight::EventOverlap(bool IsBegin)//AMoveLeftRight�� EventOverlap�� �����//bool IsBegin : �Ķ��Ÿ
{
	m_isplay = IsBegin; //m_isplay��IsBegin�� ���� �־��ش�.
}

void AMoveLeftRight::Code_DoPlay_Implementation(bool isplay)
{
	m_isplay = isplay;
}

