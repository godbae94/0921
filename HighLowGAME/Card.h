#pragma once
#include<string>

enum CardMark //배열변수를 생성한다. 이름은 CardMark이다.
{
	None = 0, //None을0으로 설정하고 밑으로 이름을쓰고 1, 2, 3 .... 순서를 정의해준다.
	Clover,//1
	Heart,//2
	Dia,//3
	Spade,//4
	MaxMark//5
};


//class 여러 변수를 한번에 컨트롤해준다.
class CCard //class변수를 생성한다. 이름은CCard로한다.
{
public:
	//CardMark의변수를가진 mark(이름) 기본값 배열의 None의 값으로 설정한다.int변수number를생성하고 기본값0으로설정.
	// mark를변수로가진m_mark생성. number를변수로가진m_number생성 {}로 닫아준다.
	CCard(CardMark mark = CardMark::None, int number = 0);

	std::string GetMarkStr();//std::string변수를 가진 GetMarkStr()함수를 정의한다

	std::string GetCardStr();//std::string변수를 가진 GetCardStr()함수를 정의한다
	
	void printCard();//보이드변수함수를만든다. 이름은printCard
	
public:
	CardMark m_mark;//CardMark변수를가진 m_mark(이름)를 정의한다.
	int m_number;//int변수를가진 m_number(이름)을 정의한다.
};