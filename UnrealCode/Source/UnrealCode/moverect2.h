// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Public/Tools/interface_play_obj.h"//Actor.h위에 해당 인터페이스 경로를 include한다.
#include "GameFramework/Actor.h"//↑↑↑
#include "moverect2.generated.h"//generated.h 코드밑에는 아무것도오면안된다.

UENUM(BlueprintType)//언리얼 ENUM을 블루프린트에서도 사용가능하도록 선언
enum class EN_MoveTypeCode : uint8
{
	//Moveright(c++에서 사용하는 이름), UMETA 옵션중 DisplayName = "right"는 블루프린트에서 보여질 이름
	Moveright UMETA(DisplayName = "right"),
	Moveup UMETA(DisplayName = "up"),//
    Moveleft UMETA(DisplayName = "left"),//
    Movedown UMETA(DisplayName = "down"),//

};



UCLASS()
class UNREALCODE_API Amoverect2 : public AActor, public Iinterface_play_obj//public Iinterface_play_obj기능을 상속받겠다.
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Amoverect2();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void EventOverlap(bool IsBegin);

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Code_DoPlay(bool isplay);//블루프린트 호출용 함수명 선언

	virtual void Code_DoPlay_Implementation(bool isplay) override;// c++에서 실행될 함수 "오버라이드!!"

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USceneComponent* Scene;

	//UPROPERTY https://docs.unrealengine.com/4.26/ko/ProgrammingAndScripting/GameplayArchitecture/Properties/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh;

	EN_MoveTypeCode m_MoveType;
	float m_LocX;
	float m_LocZ;
	bool m_isplay2;

	UPROPERTY(Editanywhere, BlueprintReadOnly)
	TObjectPtr<class Aswitch> m_Switch;

};
