// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "interface_play_obj.generated.h"

UINTERFACE(Blueprintable)// 블루프린트 호출 Interface 클래스 선언
class UNREALCODE_API Uinterface_play_obj : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class UNREALCODE_API Iinterface_play_obj// Interface 함수 구현 클래스
{
	GENERATED_BODY()

public:
	//BlueprintCallable : 블루프린트에서 호출 가능
	//BlueprintNativeEvent : 블루프린트에서 상속 재구현 가능 함수처리
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Code_DoPlay(bool isplay);//블루프린트 호출용 함수명 선언

	virtual void Code_DoPlay_Implementation(bool isplay) {};// c++에서 실행될 함수

};
