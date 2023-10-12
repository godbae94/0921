#include "Card.h"
#include <stdio.h>
#include <string>
#include <iostream>

//CardMark의변수를가진 mark를 파라메타로생성 
//int변수number를 파라메타생성
//:뒤에 배열에 맞게 mark를변수로가진m_mark생성. number를변수로가진m_number생성 {}로 닫아준다.
CCard::CCard(CardMark mark, int number) : m_mark(mark), m_number(number){}

std::string CCard::GetMarkStr()//std::string변수로하는 함수를 생성. 이름은 GetMarkStr 
{
	switch (m_mark)//m_mark변수로 작동하는 스위치를 만든다.
	{
	case Clover://clover(1)인 경우 작동한다
		return "Clover"; //clover를 리턴한다,
		break;//멈춘다.
	case Heart://heart(2)인 경우 작동한다.
		return "Heart";//heart를 리턴한다.
		break;//멈춘다.
	case Dia://dia(3)인 경우 작동한다.
		return "Dia";//dia를 리턴한다.
		break;//멈춘다,
	case Spade://spade(4)인 경우 작동한다.
		return "Spade";//spade를 리턴한다.
		break;//멈춘다.
	}

	return "None";//스위치 작동이 끝나면 none을 리턴한다.
}

std::string CCard::GetCardStr()//std::string CCard::를 변수로하는 GetCardStr()함수생성
{
	return GetMarkStr() + "[" + std::to_string(m_number) + "]";//std::to_string(m_number) : m_number의변수를 string변수로 변환한다.
	//GetMarkStr()의값과 "[" 와 std::to_string(m_number)의값 또 "]"를 더한다. string에서는 문자를 합치겠다는뜻 
	//ex)GetMarkStr(2)   std::to_string(10) 이면 : hreat + [ + 10 + ] -> hreat[10]
}



void CCard::printCard()//보이드변수함수를만든다. 이름은printCard
{
	printf("%s[%d]\n", GetMarkStr().c_str(), m_number);//GetMarkStr().c_str()의값과, [m_number]의 값을 프린트한다.
}