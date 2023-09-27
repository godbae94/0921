#include <stdio.h>


// c++ �� ������
// c++���� ����� �ۼ��� �ҽ��ڵ带 ��ǻ�Ͱ� ������ �ִ� �ڵ�� ��ȯ�Ͽ� �����Ҽ� �ִ� ���Ϸ� ��ȯ�ϴ� ����
// 1. ��ó��(Preprocessing) �ܰ� : #include �� #define �� ���� ��ó���� ��ũ�ε��� ó���ϴ� �ܰ�
// 2. ������(Comfile) �ܰ� : ������ �ҽ� ���ϵ��� ����� ��ɾ�� ����
// 3. �����(Assemble) �ܰ� : ����� �ڵ���� ���� ����� �̷���� ���� �ڵ�(Object file)�� ��ȯ�ϴ� �ܰ�
// 4. ��ŷ(Linking) �ܰ� : ������ ���� �ڵ���� �ѵ� ��Ƽ� �ϳ��� ���� ������ �����ϴ� �ܰ�

// �޸� ����
// 1. Code ���� : ������ �ڵ尡 ����Ǿ��ִ� ����(����� ����)
// 2. Data ���� : ��������, Static �������� ����, ���μ����� ����ɋ� ���� �޸𸮿� �����
// 3. Stack ���� : ��������, �Ű��������� ����, �Լ��� ȣ��Ǹ� �����ǰ� �Լ��� ����Ǹ� �ý��ۿ� ��ȯ
// 4. Heap ���� : malloc �Ǵ� new �Լ��� ���ؼ� �������� �Ҵ�Ǵ� ����, malloc() �Ǵ� new �����ڷ� �Ҵ�, free() �Ǵ� delete �����ڷ� ����

int g_money = 0;//��������

static int s_money = 0;
 
int num1, num2;

#include "money.h"
#include "calcfunc.h"

struct fruitShop
{
	//����ü ���� ������ ������ ����ü�� ������� ������ �Ȼ������.
	int appleA;
	int mangoA;
	int strawberryA;
	
	//����ü ������ ":"�� ���� �����ʿ� ������ �ʱⰪ�� �����Ѵ�
	fruitShop() : appleA(1000), mangoA(1000), strawberryA(1000)
	{

	}

	//����ü�� �Լ� ����
	void SetFruitValue(int apple, int mango, int strawberry)
	{
		appleA = apple;
		mangoA = mango;
		strawberryA = strawberry;
	}

	void printShopValue()
	{
		printf("���ϰ��� ���� ���:%d, ����:%d, ����:%d\n", appleA, mangoA, strawberryA);
	}

};

struct PhoneShop
{
	int numberA;
	int iPhoneA;
	int zFlipA;
	int GalaxyS23A;
	int GalaxyFoldA;
		
	PhoneShop() : numberA(0), iPhoneA(100), zFlipA(100), GalaxyS23A(100), GalaxyFoldA(100)
	{

	}

	void SetPhoneValue(int number, int iPhone, int zFlip, int GalaxyS23, int GalaxyFold)
	{
		numberA = number;
		iPhoneA = iPhone;
		zFlipA = zFlip;
		GalaxyS23A = GalaxyS23;
		GalaxyFoldA = GalaxyFold;
	}

	void printPhoneValue()
	{
		printf("�ڵ�������%d ���� ������ : % d, ��Ʈ�ø� : % d, �����ÿ���23 : % d, ���������� : %d\n", numberA, iPhoneA, zFlipA, GalaxyS23A, GalaxyFoldA);
		
	}


};





int Add(int a, int b)
{
	printf("int�� Add�� ���Ǿ����ϴ�.\n");
	return a + b;
}

float Add(float a, float b)
{
	printf("float�� Add�� ���Ǿ����ϴ�.\n");
	return a + b;
}

double Add(double a, double b)
{
	printf("double�� Add�� ���Ǿ����ϴ�.\n");
	return a + b;
}



int main()
{
	//int t_money = 0;//���� ����
	//addmoney(100);
 //   addmoney(100);
	//addmoney(100);
	//addmoney(100);
	//addmoney(100);

	//printf("main t_money=%d\n", t_money);
	//printf("main g_money=%d\n", g_money);
	//printf("sum =%d\n", AddNum(1, 2));
	//printf("multi=%d\n", MultiplyNum(1, 2));

	//Add(1, 1);
	//Add(1.0f, 1.0f);//f�� ���̰� �Ǽ��� ���� float��
	//Add(1.0, 1.0);//f�� ������ �ʰ� �Ǽ��� ���� double��

	//�迭
	
	//int arrint[10] = { 0 };//�迭 ���� �� ���� 0���� �ʱ�ȭ
	//int arrint[10] = { 0, };//�迭 ���� �� ���� 0���� �ʱ�ȭ
	//int arrint[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };//�迭 ���� �� ������ �迭�� �ʱⰪ�� �ִ� ���
	//arrint[0] = 10;//�迭 1��°�� �� �ֱ�
	//arrint[4] = 40;//�迭 5��°�� �� �ֱ�
	//arrint[9] = 90;//0�� ���� �迭�� ���� �ǹǷ� 10��°�� 9���̴�

	//for (int i = 0; i < 10; i++)
	//{
	//	printf("%d��° �迭 ���� %d�Դϴ�\n", i, arrint[i]);// 2�� �̻��� �Ķ��Ÿ ���
	//	arrint[i];
	//}

	//int number = 0;
	//for (int value : arrint)//for each��
	//{
	//	printf("for each %d��° �迭 ���� %d�Դϴ�\n", number, value);
	//	number++;
	//}

	// struct�� ���
	// fruitShop : ������
	// shop : ������ �̸�
	//fruitShop shop[3];

	//// struct �Լ� ����
	//shop[0].SetFruitValue(1000, 2000, 3000);
	//shop[1].SetFruitValue(1100, 2100, 3100);
	//shop[2].SetFruitValue(900, 1900, 2900);
	//
	//for (fruitShop stValue : shop)
	//{
	//	stValue.printShopValue();
	//}

	PhoneShop shop[3];

	shop[0].SetPhoneValue(1, 100, 90, 80, 150);
	shop[1].SetPhoneValue(2, 110, 100, 90, 160);
	shop[2].SetPhoneValue(3, 90, 80, 70, 140);
	
	for (PhoneShop value : shop)
	{
		value.printPhoneValue();
	}





	
}