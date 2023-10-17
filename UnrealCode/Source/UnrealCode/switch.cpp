// Fill out your copyright notice in the Description page of Project Settings.


#include "switch.h"
#include "MoveLeftRight.h"
#include "moverect2.h"
#include "Public/Tools/interface_play_obj.h"

// Sets default values
Aswitch::Aswitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRootRoot4"));
    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mymyMesh4"));

	SetRootComponent(Scene);

	StaticMesh->AttachToComponent(Scene, FAttachmentTransformRules::KeepRelativeTransform);

	

	StaticMesh->OnComponentBeginOverlap.AddDynamic(this, &Aswitch::OnSwitchBeginOverlap);
	StaticMesh->OnComponentEndOverlap.AddDynamic(this, &Aswitch::OnSwitchEndOverlap);
}

// Called when the game starts or when spawned
void Aswitch::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Aswitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void Aswitch::OnSwitchBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// GEngine->AddOnScreenDebugMessage : print string ���
	// -1 : ����Ű ���� �ִ´� Ư���� ������ -1
	// 10.0f : ��½ð�
	// FColor::Green : �ؽ�Ʈ ����
	// TEXT("BeginOverlap") : ����� �ؽ�Ʈ
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, TEXT("BeginOverlap"));

	// (if (IsValid(leftright) == false) return;)�� �ϴ������� ��ü�� ���峪������ leftright->isplay = true;�� ���������ʱ����ؼ��̴�.
	// IsValid : �𸮾󿡼� ���ξ� ��ü�� �����ϴ��� �ı������� �� Ȯ���ؼ�  ���� �ȿ� ��ü�� ���������� ���� üũ�ϴ� ����
	//if (IsValid(leftright) == false)// leftright�� ���������� ������ ����(�Լ��� ����ȴ�.)���ϰڴ�.
		//return; //�Լ��� ����ȴ�.(��ȯ���� ������ ��ȯ���� �Ѱ��ش�.)

	//if (IsValid(moverect) == false)//moverect�� �����������ʴٸ� ����(�Լ��������Ѵ�).
		//return;//�Լ�����

	//leftright->isplay = true;//leftright�� isplay�� true���Ѵ�.
	//moverect->isplay2 = true;//moverect�� isplay2�� true���Ѵ�.
	//for (int i = 0; i < leftright.Num(); ++i)
	//{
	//	leftright[i]->isplay = true; //leftright�� ������ �迭�̱� ������ "->"�� �̿��ؼ� ����
	//}

	/*for (AMoveLeftRight* pActor : leftright)
	{
		pActor->isplay = true;
	}*/

	/*for (Amoverect2* qActor : moverect)
	{
		qActor->isplay2 = true;
	}*/

	//for (AActor* pActor : actors)//actors�迭���� AActor*�� ������ ���� pActor����̸�����
	//{
	//	AMoveLeftRight* pleftright = Cast<AMoveLeftRight>(pActor);
	//	if (pleftright)
	//	{
	//		pleftright->isplay = true;
	//		continue;
	//	}
	//	Amoverect2* prect = Cast<Amoverect2>(pActor);
	//	if (prect)
	//	{
	//		prect->isplay2 = true;
	//		continue;
	//	}
	//}

	//for (AActor* pActor : actors)
	//{
	//	Iinterface_play_obj* interfaceobj = Cast<Iinterface_play_obj>(pActor);//����� interface casting(����ȯ)
	//	if (interfaceobj)
	//	{
	//		//interface casting(����ȯ) ������ Execute_(�Լ��̸�)���� interface �Լ� ȣ��
	//		//Execute_(�Լ��̸�)�� ù��° �Ķ��Ÿ���Լ� ȣ�� ��� ��ü, ���Ĵ� �Լ� �Ķ��Ÿ
	//		interfaceobj->Execute_Code_DoPlay(pActor, true);
	//	}
	//}

	if (FDele_EventOverlap.IsBound())//���ε� �ɷ��ִ� �Լ����ִ��� üũ
		FDele_EventOverlap.Broadcast(true);//��������Ʈ �̺�Ʈ ȣ��(Didpatcher ȣ��� ����)

}

void Aswitch::OnSwitchEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	// GEngine->AddOnScreenDebugMessage() : print string ��� ȣ��
	//-1 : ����Ű���Է� ������ -1// 10.0f : �޼�����½ð� // FColor::Red : �ؽ�Ʈ ����(����)//TEXT("EndOverlap") : ""�ȿ� �ؽ�Ʈ����
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("EndOverlap"));
	//if (IsValid(leftright) == false)// leftright�� ���������� ������ ����(�Լ��� ����ȴ�.)���ϰڴ�.
		//return;//�Լ��� ����ȴ�.

	//if (IsValid(moverect) == false)
		//return;

	//leftright->isplay = false; //leftright�� isplay�� false���Ѵ�.
	//moverect->isplay2 = false;

	/*for (AMoveLeftRight* pActor : leftright)
	{
		pActor->isplay = false;
	}*/

	/*for (Amoverect2* qActor : moverect)
	{
		qActor->isplay2 = false;
	}*/

	//for (AActor* pActor : actors)//actors�迭���� AActor*�� ������ ���� pActor����̸�����
	//{
	//	Iinterface_play_obj* interfaceobj = Cast<Iinterface_play_obj>(pActor);//����� interface casting(����ȯ)
	//	if (interfaceobj)
	//	{
	//		//interface casting(����ȯ) ������ Execute_(�Լ��̸�)���� interface �Լ� ȣ��
	//		//Execute_(�Լ��̸�)�� ù��° �Ķ��Ÿ���Լ� ȣ�� ��� ��ü, ���Ĵ� �Լ� �Ķ��Ÿ
	//		interfaceobj->Execute_Code_DoPlay(pActor, false);
	//	}
	//}


	if (FDele_EventOverlap.IsBound())//���ε� �ɷ��ִ� �Լ����ִ��� üũ
		FDele_EventOverlap.Broadcast(false);//��������Ʈ �̺�Ʈ ȣ��(Didpatcher ȣ��� ����)

}