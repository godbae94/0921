#pragma once
#include<string>

enum CardMark //�迭������ �����Ѵ�. �̸��� CardMark�̴�.
{
	None = 0, //None��0���� �����ϰ� ������ �̸������� 1, 2, 3 .... ������ �������ش�.
	Clover,//1
	Heart,//2
	Dia,//3
	Spade,//4
	MaxMark//5
};


//class ���� ������ �ѹ��� ��Ʈ�����ش�.
class CCard //class������ �����Ѵ�. �̸���CCard���Ѵ�.
{
public:
	//CardMark�Ǻ��������� mark(�̸�) �⺻�� �迭�� None�� ������ �����Ѵ�.int����number�������ϰ� �⺻��0���μ���.
	// mark�������ΰ���m_mark����. number�������ΰ���m_number���� {}�� �ݾ��ش�.
	CCard(CardMark mark = CardMark::None, int number = 0);

	std::string GetMarkStr();//std::string������ ���� GetMarkStr()�Լ��� �����Ѵ�

	std::string GetCardStr();//std::string������ ���� GetCardStr()�Լ��� �����Ѵ�
	
	void printCard();//���̵庯���Լ��������. �̸���printCard
	
public:
	CardMark m_mark;//CardMark���������� m_mark(�̸�)�� �����Ѵ�.
	int m_number;//int���������� m_number(�̸�)�� �����Ѵ�.
};