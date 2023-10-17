// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "interface_play_obj.generated.h"

UINTERFACE(Blueprintable)// �������Ʈ ȣ�� Interface Ŭ���� ����
class UNREALCODE_API Uinterface_play_obj : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class UNREALCODE_API Iinterface_play_obj// Interface �Լ� ���� Ŭ����
{
	GENERATED_BODY()

public:
	//BlueprintCallable : �������Ʈ���� ȣ�� ����
	//BlueprintNativeEvent : �������Ʈ���� ��� �籸�� ���� �Լ�ó��
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Code_DoPlay(bool isplay);//�������Ʈ ȣ��� �Լ��� ����

	virtual void Code_DoPlay_Implementation(bool isplay) {};// c++���� ����� �Լ�

};
