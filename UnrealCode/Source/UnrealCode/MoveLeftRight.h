// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"// ������ �ӵ��� ������ �ϱ����� �⺻���� �ּ��忡 ���̺귯���� ������ ���
#include "GameFramework/Actor.h"//AActor Ŭ���� �������

// ��generated.h �𸮾� Ŭ���� ���� ó���ϴ� ��� - �𸮾� Ŭ���� ���� �⺻ ��Ģ
// ���𸮾� Ŭ������ �����Ƿ��� ���� �ڵ带 �־�����Ѵ�.
// �ݵ�� ��� #include �������� ��ġ�ؾ��Ѵ�.
#include "MoveLeftRight.generated.h"

 
//UNREALCODE_API : �� Ŭ������ UNREALCODE_API ��⿡ ���Եȴ�.
UCLASS()// �𸮾� Ŭ���� ���� - �𸮾� Ŭ���� ���� �⺻ ��Ģ
class UNREALCODE_API AMoveLeftRight : public AActor//public AActor : AActor�� ����� ��� �ްڴ�.
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
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USceneComponent* Scene;

	//UPROPERTY https://docs.unrealengine.com/4.26/ko/ProgrammingAndScripting/GameplayArchitecture/Properties/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh;

	float LocX;
	float LocZ;
	bool ismoveright;


};
