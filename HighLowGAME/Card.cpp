#include "Card.h"
#include <stdio.h>
#include <string>
#include <iostream>

//CardMark�Ǻ��������� mark�� �Ķ��Ÿ�λ��� 
//int����number�� �Ķ��Ÿ����
//:�ڿ� �迭�� �°� mark�������ΰ���m_mark����. number�������ΰ���m_number���� {}�� �ݾ��ش�.
CCard::CCard(CardMark mark, int number) : m_mark(mark), m_number(number){}

std::string CCard::GetMarkStr()//std::string�������ϴ� �Լ��� ����. �̸��� GetMarkStr 
{
	switch (m_mark)//m_mark������ �۵��ϴ� ����ġ�� �����.
	{
	case Clover://clover(1)�� ��� �۵��Ѵ�
		return "Clover"; //clover�� �����Ѵ�,
		break;//�����.
	case Heart://heart(2)�� ��� �۵��Ѵ�.
		return "Heart";//heart�� �����Ѵ�.
		break;//�����.
	case Dia://dia(3)�� ��� �۵��Ѵ�.
		return "Dia";//dia�� �����Ѵ�.
		break;//�����,
	case Spade://spade(4)�� ��� �۵��Ѵ�.
		return "Spade";//spade�� �����Ѵ�.
		break;//�����.
	}

	return "None";//����ġ �۵��� ������ none�� �����Ѵ�.
}

std::string CCard::GetCardStr()//std::string CCard::�� �������ϴ� GetCardStr()�Լ�����
{
	return GetMarkStr() + "[" + std::to_string(m_number) + "]";//std::to_string(m_number) : m_number�Ǻ����� string������ ��ȯ�Ѵ�.
	//GetMarkStr()�ǰ��� "[" �� std::to_string(m_number)�ǰ� �� "]"�� ���Ѵ�. string������ ���ڸ� ��ġ�ڴٴ¶� 
	//ex)GetMarkStr(2)   std::to_string(10) �̸� : hreat + [ + 10 + ] -> hreat[10]
}



void CCard::printCard()//���̵庯���Լ��������. �̸���printCard
{
	printf("%s[%d]\n", GetMarkStr().c_str(), m_number);//GetMarkStr().c_str()�ǰ���, [m_number]�� ���� ����Ʈ�Ѵ�.
}