// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"// 컴파일 속도를 빠르게 하기위해 기본적인 최소헌에 라이브러리만 포함한 헤더
#include "Public/Tools/interface_play_obj.h"
#include "GameFramework/Actor.h"//AActor 클래스 헤더파일

// ★generated.h 언리얼 클래스 생성 처리하는 헤더 - 언리얼 클래스 생성 기본 규칙
// 모든언리얼 클래스가 생성되려면 위에 코드를 넣어줘야한다.
// 반드시 모든 #include 마지막에 배치해야한다.
#include "MoveLeftRight.generated.h"

 
//UNREALCODE_API : 이 클래스는 UNREALCODE_API 모듈에 포함된다.
UCLASS()// 언리얼 클래스 선언 - 언리얼 클래스 생성 기본 규칙
class UNREALCODE_API AMoveLeftRight : public AActor, public Iinterface_play_obj//public AActor : AActor에 기능을 상속 받겠다.
{
	GENERATED_BODY()//언리얼 코드 생성 함수 - 언리얼 클래스 생성 기본 규칙
	
public:	
	// Sets default values for this actor's properties
	AMoveLeftRight();
	~AMoveLeftRight();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()//기능을 넣기위해 필수로 UFUNCTION 코드를 작성한다.
	void EventOverlap(bool IsBegin);//void함수 EventOverlap을만든다. bool형변수를가진IsBegin을 파라메타로한다.


public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Code_DoPlay(bool isplay);//블루프린트 호출용 함수명 선언

	virtual void Code_DoPlay_Implementation(bool isplay) override;// c++에서 실행될 함수
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USceneComponent* Scene;

	//UPROPERTY https://docs.unrealengine.com/4.26/ko/ProgrammingAndScripting/GameplayArchitecture/Properties/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh;

	float m_LocX;	
	bool m_ismoveright;
	bool m_isplay;
	
	//TObjectPtr 언리얼에서 Aswitch를 상속 받은 모든 클래스를 가르킬수 있는 변수
	//Editanywhere : 인스턴스 편집가능(레벨에 배치한 인스턴스에서 디테일 창으로 편집이 가능하게 보여준다.)
	// class : #include 클래스를 추가하지 않고 차후에 클래스가 있을거라고 컴파일 단계에서만 알려주는 키워드
	UPROPERTY(Editanywhere, BlueprintReadOnly)
	TObjectPtr<class Aswitch> m_Switch;


};
