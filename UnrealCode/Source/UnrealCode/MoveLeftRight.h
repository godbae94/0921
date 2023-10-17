// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"// ������ �ӵ��� ������ �ϱ����� �⺻���� �ּ��忡 ���̺귯���� ������ ���
#include "Public/Tools/interface_play_obj.h"
#include "GameFramework/Actor.h"//AActor Ŭ���� �������

// ��generated.h �𸮾� Ŭ���� ���� ó���ϴ� ��� - �𸮾� Ŭ���� ���� �⺻ ��Ģ
// ���𸮾� Ŭ������ �����Ƿ��� ���� �ڵ带 �־�����Ѵ�.
// �ݵ�� ��� #include �������� ��ġ�ؾ��Ѵ�.
#include "MoveLeftRight.generated.h"

 
//UNREALCODE_API : �� Ŭ������ UNREALCODE_API ��⿡ ���Եȴ�.
UCLASS()// �𸮾� Ŭ���� ���� - �𸮾� Ŭ���� ���� �⺻ ��Ģ
class UNREALCODE_API AMoveLeftRight : public AActor, public Iinterface_play_obj//public AActor : AActor�� ����� ��� �ްڴ�.
{
	GENERATED_BODY()//�𸮾� �ڵ� ���� �Լ� - �𸮾� Ŭ���� ���� �⺻ ��Ģ
	
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

	UFUNCTION()//����� �ֱ����� �ʼ��� UFUNCTION �ڵ带 �ۼ��Ѵ�.
	void EventOverlap(bool IsBegin);//void�Լ� EventOverlap�������. bool������������IsBegin�� �Ķ��Ÿ���Ѵ�.


public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Code_DoPlay(bool isplay);//�������Ʈ ȣ��� �Լ��� ����

	virtual void Code_DoPlay_Implementation(bool isplay) override;// c++���� ����� �Լ�
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USceneComponent* Scene;

	//UPROPERTY https://docs.unrealengine.com/4.26/ko/ProgrammingAndScripting/GameplayArchitecture/Properties/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh;

	float m_LocX;	
	bool m_ismoveright;
	bool m_isplay;
	
	//TObjectPtr �𸮾󿡼� Aswitch�� ��� ���� ��� Ŭ������ ����ų�� �ִ� ����
	//Editanywhere : �ν��Ͻ� ��������(������ ��ġ�� �ν��Ͻ����� ������ â���� ������ �����ϰ� �����ش�.)
	// class : #include Ŭ������ �߰����� �ʰ� ���Ŀ� Ŭ������ �����Ŷ�� ������ �ܰ迡���� �˷��ִ� Ű����
	UPROPERTY(Editanywhere, BlueprintReadOnly)
	TObjectPtr<class Aswitch> m_Switch;


};
