// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "switch.generated.h"


//DECLARE_DYNAMIC_MULTICAST_DELEGATE : ������ �̺�Ʈ�� ���ε� ������, �������Ʈ���� ȣ�� ����
//_OneParam : �Ķ��Ÿ ���� 1�� �̱� ������ OneParam ���
//FDele_EventOverlap_OneParam : ��������Ʈ �̸�
//bool, isbegin : �Ķ��Ÿ ������, �Ķ��Ÿ ���� �̸�
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
// public : �ؿ� �ڵ带 �ܺη� ȣ���� �Ҽ��ִ�.
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION()// ���ε� �Լ��� �ݵ��  UFUNCTION���� ������ ��
	void OnSwitchBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
public:
	UFUNCTION()
	void OnSwitchEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	

public:

	//TObjectPtr �𸮾󿡼� AMoveLeftRight�� ��� ���� ��� Ŭ������ ����ų�� �ִ� ����
	//Editanywhere : �ν��Ͻ� ��������(������ ��ġ�� �ν��Ͻ����� ������ â���� ������ �����ϰ� �����ش�.)
	// class : #include Ŭ������ �߰����� �ʰ� ���Ŀ� Ŭ������ �����Ŷ�� ������ �ܰ迡���� �˷��ִ� Ű����
	// TArray : �𸮾󿡼� �迭(vector) ���� [��) TArray<int> arr;]
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


	//FDele_EventOverlap_OneParam�� ���������ϰ� ������ ����
	UPROPERTY(BlueprintAssignable, VisibleAnywhere, BlueprintCallable)
	FDele_EventOverlap_OneParam FDele_EventOverlap;

};
