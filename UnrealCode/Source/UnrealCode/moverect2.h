// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Public/Tools/interface_play_obj.h"//Actor.h���� �ش� �������̽� ��θ� include�Ѵ�.
#include "GameFramework/Actor.h"//����
#include "moverect2.generated.h"//generated.h �ڵ�ؿ��� �ƹ��͵�����ȵȴ�.

UENUM(BlueprintType)//�𸮾� ENUM�� �������Ʈ������ ��밡���ϵ��� ����
enum class EN_MoveTypeCode : uint8
{
	//Moveright(c++���� ����ϴ� �̸�), UMETA �ɼ��� DisplayName = "right"�� �������Ʈ���� ������ �̸�
	Moveright UMETA(DisplayName = "right"),
	Moveup UMETA(DisplayName = "up"),//
    Moveleft UMETA(DisplayName = "left"),//
    Movedown UMETA(DisplayName = "down"),//

};



UCLASS()
class UNREALCODE_API Amoverect2 : public AActor, public Iinterface_play_obj//public Iinterface_play_obj����� ��ӹްڴ�.
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
	void Code_DoPlay(bool isplay);//�������Ʈ ȣ��� �Լ��� ����

	virtual void Code_DoPlay_Implementation(bool isplay) override;// c++���� ����� �Լ� "�������̵�!!"

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
