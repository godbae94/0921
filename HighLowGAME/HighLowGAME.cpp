#include <stdio.h>
#include <vector>
#include <string>
#include"Card.h"
#include <random>

/*
1. 52���� ī������ ������ �մϴ�.
2. 52���� ī�带 �������� �����ϴ�.
3. ������ ���۵Ǹ� ī�� �ϳ��� ���� �մϴ�.
4. �÷��̾�� ����ī�尡 ���µ� ī�庸�� ���� ī������ ���� ī�������� ���� ������ �մϴ�.
5. ���� ī�带 �����ϰ� ������ �������� ���� ������ ������ �¸� Ʋ���� �й�
6. ī�带 1�� ���� ���� K�� ���� �����ϴ�. ���� ���ڶ�� ���� ������ ī�尡 �¸��Ѵ�.
7. ������ �����̵� > ���̾� > ��Ʈ > Ŭ�ι� ������ �����ϴ�.
*/

void Shuffle(std::vector<CCard>& Cards)//���̵��Լ����� Shuffle�̸�.std::vector<CCard>&�������� Cards���������Ѵ�.
{
	std::random_device rd;//std::random_device ��������. �̸���rd
	//std::mt19937 mt(1234);//1234�� �õ�(seed)���̶�� �ؼ� �ʱ⿡ �־����� Ű��, �����õ�� ���� ���ڰ� �����ϰԳ��´�.
	std::mt19937 mt(rd.entropy());// �õ尪�� �������� �ο��ؼ� ���� ���� ����� ������ �ʴ´�.
	std::uniform_int_distribution<int> dist(0, Cards.size()-1);
	//std::uniform_int_distribution<int>�������� �̸��� dist ������ 0���� Cards��������-1������ ������ �ϳ��� ���´�.
	
	for (int i = 0; i < 100;++i)//int i�� 0, i�� 100����ũ���ʴ�, i�� 1��Ŀ����.
	{
		int firstindex = dist(mt);//int������ firstindex������. dist(mt){����}���� �־��ش�. firstindex�ǹ����� 0~[Cards.size()-1]
		int secondindex = dist(mt);//int������ secondindex������. dist(mt){����}���� �־��ش�. secondindex�� ������ 0~[Cards.size()-1]
		//�ΰ��Ƿ������� ������.

		CCard temp = Cards[firstindex]; //CCard���������ϴ� temp����. Cards������ [firstindex]��ġ���� ��Ÿ���� ���� temp���־��ش�.
		Cards[firstindex] = Cards[secondindex];//Cards������[secondindex]��ġ���� [firstindex]�� �־��ش�
		Cards[secondindex] = temp;//temp�ǰ��� [secondindex]���ִ´�.

	}


}
//bool������ CompareCard �Լ����� const CCard& CardA �� const CCard& CardB�� �Ķ��Ÿ���Ѵ�
bool CompareCard(const CCard& CardA, const CCard& CardB)
{
	int ScoreA = CardA.m_number * 10 + CardA.m_mark;//int���� ScoreA������.m_number�� �켱���ϱ����� 10�����Ͽ� �����̸� Ȯ�����Ѵ�.
	             //CardA�� m_number�����ִ´�...// CardA�� m_mark�����ִ´�.
	int ScoreB = CardB.m_number * 10 + CardB.m_mark;//int���� ScoreB������.m_number�� �켱���ϱ����� 10�����Ͽ� �����̸� Ȯ�����Ѵ�.
	             //CardB�� m_number�����ִ´�. // CardB�� m_mark�����ִ´�.
	return ScoreA > ScoreB; //ScoreA��ScoreB����ũ�� TRUE �ƴϸ� FALSE�� ��ȯ�Ѵ�.
}




int main()//int�� main �Լ��� �����Ѵ�.
{
	std::vector<CCard> Cards;//std::vector<CCard>�������¸� �����Ѵ�.�̸��� Cards�̴�.
	
	// for���� �����Ѵ�.
	//int�� i�� �����Ѵ�. �⺻���� CardMark::Clover(1)�� �����μ����Ѵ�. i�ǹ�����CardMark::MaxMark(5)�ǰ������۴�.i�� 1�� �þ��.
	for (int i = CardMark::Clover; i < CardMark::MaxMark; ++i)
	{
		//1,2,3,4,5,6,7,8,9,10,J(11),Q(12),K(13)
		for (int j = 1; j <= 13; ++j)//int��j�� �����Ѵ�.�⺻����1.j�ǹ����� 13���� �۰ų�����. j�� 1���þ��.
		{
			CCard card;//CCard�� �������ϴ� card�� ����
			card.m_mark = (CardMark)i;//card.m_mark�� (CardMark)i�� ���� �ִ´�.
			card.m_number = j;//card.m_number�� j�� ���� �־��ش�.
			Cards.push_back(card); //�迭�ڿ� card�� ���� ���δ�
		}
	}

	Shuffle(Cards);//Shuffle�Լ���  Cards�ǰ��� �־��۵��Ѵ�.

	bool bRun = true;// bRun�����̸� true�̴�.
	int i = 0;//int������ ����i������.�⺻����0�̴�.
	while (bRun)//�ٷιؿ� �ڵ尡 bRun(true)�̸������ϰ� �ƴ�(false)�� ���߰� �����Ѵ�.
	{
		printf("ù��° ī��� %s �Դϴ�.\n", Cards[i].GetCardStr().c_str());
		//Cards[i]������  GetCardStr()������ �����ְ� ��Ʈ������ ����ϱ����� c_str()�� ���� ����Ʈ�Ѵ�.
		int input = 0;//input = 1 �̸� Cards[0] ����.
		printf("�ι�° ī�尡 ������ 0, ������ 1�� �Է����ּ��� : ");
		scanf_s("%d", &input);//input ���� �����ؼ� %d�� �Է��Ѵ�.
		system("cls");//�������ڵ带 �����Ѵ�.

		printf("ù��° ī��� %s �Դϴ�.\n", Cards[i].GetCardStr().c_str());
		//Cards[i]������  GetCardStr()������ �����ְ� c_str()�� �̿��� string�� ����Ʈ�Ѵ�
		printf("�ι�° ī��� %s �Դϴ�.\n", Cards[i + 1].GetCardStr().c_str());
		//Cards[i+1]������  GetCardStr()������ �����ְ� c_str()�� �̿��� string�� ����Ʈ�Ѵ�
		
		// IsFirstHigh = 1 �̸� Cards[0] ����.
		bool IsFirstHigh = CompareCard(Cards[i], Cards[i + 1]);//bool�� ���� IsFirstHigh�� �����Ѵ�.
		//IsFirstHigh�� Cards[i]�� Cards[i + 1]�� ���ϴ� CompareCard�Լ����ִ´�.
		
		//IsFirstHigh�� true�̸� 1, false�̸� 0�̴�.
		//input���� "�ι�° ī�尡 ������ 0, ������ 1�� �Է����ּ���"���� �����Ѱ��̴�.
		if (IsFirstHigh == input) //IsFirstHigh���� input������ ������(true�̸�) �Ʒ��ڵ带 �����Ѵ�.
		{
			printf("�����.\n"); //����ٸ� ����Ʈ�Ѵ�.
		}
		else //false�̸�
		{
			printf("Ʋ�ȴ�.\n");//Ʋ�ȴٸ� ����Ʈ�Ѵ�.
		}

		i += 2;//�����ī��� �����ʱ����� +2�� ���ش�
	}


	//for (CCard& card : Cards)
	//{
	//	card.printCard();//card���� ���� �Լ��� ����Ѵ�.
	//}
}