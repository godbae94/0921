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
	// GEngine->AddOnScreenDebugMessage : print string 기능
	// -1 : 에러키 값을 넣는다 특별히 없으면 -1
	// 10.0f : 출력시간
	// FColor::Green : 텍스트 색상
	// TEXT("BeginOverlap") : 출력할 텍스트
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, TEXT("BeginOverlap"));

	// (if (IsValid(leftright) == false) return;)을 하는이유는 객체가 고장나있으면 leftright->isplay = true;를 실행하지않기위해서이다.
	// IsValid : 언리얼에서 가로안 객체가 존재하는지 파괴중인지 등 확인해서  가로 안에 객체가 정상적인지 여부 체크하는 가능
	//if (IsValid(leftright) == false)// leftright가 정상적이지 않을때 리턴(함수가 종료된다.)을하겠다.
		//return; //함수가 종료된다.(반환값이 있으면 반환값을 넘겨준다.)

	//if (IsValid(moverect) == false)//moverect가 정상적이지않다면 리턴(함수를종료한다).
		//return;//함수종료

	//leftright->isplay = true;//leftright에 isplay를 true로한다.
	//moverect->isplay2 = true;//moverect에 isplay2를 true로한다.
	//for (int i = 0; i < leftright.Num(); ++i)
	//{
	//	leftright[i]->isplay = true; //leftright가 포인터 배열이기 때문에 "->"를 이용해서 참조
	//}

	/*for (AMoveLeftRight* pActor : leftright)
	{
		pActor->isplay = true;
	}*/

	/*for (Amoverect2* qActor : moverect)
	{
		qActor->isplay2 = true;
	}*/

	//for (AActor* pActor : actors)//actors배열에서 AActor*를 참조한 값을 pActor라고이름짓고
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
	//	Iinterface_play_obj* interfaceobj = Cast<Iinterface_play_obj>(pActor);//상속한 interface casting(형변환)
	//	if (interfaceobj)
	//	{
	//		//interface casting(형변환) 성공후 Execute_(함수이름)으로 interface 함수 호출
	//		//Execute_(함수이름)에 첫번째 파라메타는함수 호출 대상 객체, 이후는 함수 파라메타
	//		interfaceobj->Execute_Code_DoPlay(pActor, true);
	//	}
	//}

	if (FDele_EventOverlap.IsBound())//바인드 걸려있는 함수가있는지 체크
		FDele_EventOverlap.Broadcast(true);//델리게이트 이벤트 호출(Didpatcher 호출과 같다)

}

void Aswitch::OnSwitchEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	// GEngine->AddOnScreenDebugMessage() : print string 기능 호출
	//-1 : 에러키값입력 없으면 -1// 10.0f : 메세지출력시간 // FColor::Red : 텍스트 색상(레드)//TEXT("EndOverlap") : ""안에 텍스트내용
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("EndOverlap"));
	//if (IsValid(leftright) == false)// leftright가 정상적이지 않을때 리턴(함수가 종료된다.)을하겠다.
		//return;//함수가 종료된다.

	//if (IsValid(moverect) == false)
		//return;

	//leftright->isplay = false; //leftright에 isplay를 false로한다.
	//moverect->isplay2 = false;

	/*for (AMoveLeftRight* pActor : leftright)
	{
		pActor->isplay = false;
	}*/

	/*for (Amoverect2* qActor : moverect)
	{
		qActor->isplay2 = false;
	}*/

	//for (AActor* pActor : actors)//actors배열에서 AActor*를 참조한 값을 pActor라고이름짓고
	//{
	//	Iinterface_play_obj* interfaceobj = Cast<Iinterface_play_obj>(pActor);//상속한 interface casting(형변환)
	//	if (interfaceobj)
	//	{
	//		//interface casting(형변환) 성공후 Execute_(함수이름)으로 interface 함수 호출
	//		//Execute_(함수이름)에 첫번째 파라메타는함수 호출 대상 객체, 이후는 함수 파라메타
	//		interfaceobj->Execute_Code_DoPlay(pActor, false);
	//	}
	//}


	if (FDele_EventOverlap.IsBound())//바인드 걸려있는 함수가있는지 체크
		FDele_EventOverlap.Broadcast(false);//델리게이트 이벤트 호출(Didpatcher 호출과 같다)

}