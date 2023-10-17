// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "switch.generated.h"


//DECLARE_DYNAMIC_MULTICAST_DELEGATE : 여러개 이벤트를 바인딩 가능함, 블루프린트에서 호출 가능
//_OneParam : 파라메타 갯수 1개 이기 때문에 OneParam 사용
//FDele_EventOverlap_OneParam : 델리게이트 이름
//bool, isbegin : 파라메타 변수형, 파라메타 변수 이름
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDele_EventOverlap_OneParam, bool, IsBegin);

UCLASS()
class UNREALCODE_API Aswitch : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Aswitch();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
// public : 밑에 코드를 외부로 호출을 할수있다.
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION()// 바인디 함수는 반드시  UFUNCTION으로 만들어야 됨
	void OnSwitchBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
public:
	UFUNCTION()
	void OnSwitchEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	

public:

	//TObjectPtr 언리얼에서 AMoveLeftRight를 상속 받은 모든 클래스를 가르킬수 있는 변수
	//Editanywhere : 인스턴스 편집가능(레벨에 배치한 인스턴스에서 디테일 창으로 편집이 가능하게 보여준다.)
	// class : #include 클래스를 추가하지 않고 차후에 클래스가 있을거라고 컴파일 단계에서만 알려주는 키워드
	// TArray : 언리얼에서 배열(vector) 변수 [예) TArray<int> arr;]
	UPROPERTY(Editanywhere, BlueprintReadOnly)
	TArray<TObjectPtr<class AMoveLeftRight>> leftright;

	UPROPERTY(Editanywhere, BlueprintReadOnly)
	TArray<TObjectPtr<class Amoverect2>> moverect;

	UPROPERTY(Editanywhere, BlueprintReadOnly)
	TArray<TObjectPtr<AActor>> actors;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USceneComponent* Scene;

	//UPROPERTY https://docs.unrealengine.com/4.26/ko/ProgrammingAndScripting/GameplayArchitecture/Properties/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh;


	//FDele_EventOverlap_OneParam을 편집가능하게 변수를 생성
	UPROPERTY(BlueprintAssignable, VisibleAnywhere, BlueprintCallable)
	FDele_EventOverlap_OneParam FDele_EventOverlap;

};
