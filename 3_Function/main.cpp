#include <stdio.h>

// �Լ���
// unsigned int : ��ȯ <-Output
// CalculatorSum : �Լ� �̸�
// (int x, int y) : �Ű� ����(�Ķ��Ÿ)<-Input
unsigned int CalculatorSum(int x, int y)
{//-> �Լ� ����
	//printf("�Լ� �����ߴ�.\n");

	return x + y;//<-��ȯ �� ���� ó��

	printf("�Լ� ������.\n");
}//->�Լ� ��

// ���� �Լ� �����
unsigned int CalculatorMinus(int x, int y)
{//-> �Լ� ����

	return x - y;//<-��ȯ �� ���� ó��

	printf("�Լ� ������.\n");
}//->�Լ� ��

 // ���ϱ� �Լ� �����

unsigned int CalculatorMultiply(int x, int y)
{//-> �Լ� ����

	return x * y;//<-��ȯ �� ���� ó��

	printf("�Լ� ������.\n");
}//->�Լ� ��
 
 // ������ �Լ� �����

float CalculatorDivide(float x, float y)
{//-> �Լ� ����
	return float(x / y);//<-��ȯ �� ���� ó��

	printf("�Լ� ������.\n");
}//->�Լ� ��
 
 // ������ �Լ� �����

unsigned int CalculatorRemain(int x, int y)
{//-> �Լ� ����
	return x % y;//<-��ȯ �� ���� ó��

	printf("�Լ� ������.\n");
}//->�Լ� ��

unsigned int CalculatorSUPER(int x, int y)
{//-> �Լ� ����
	return (x*x+ y*y)*(x + y);//<-��ȯ �� ���� ó��

	printf("�Լ� ������.\n");
}//->�Լ� ��
//
//factorial �Լ�
//int Factorial(int Num)
//{
//	int FacResult = 1;
//	for (int i = 5; i > 0; --i)
//	{
//		FacResult *= i;
//	}
//
//	return FacResult;
//
//	printf("FacResult = %d", FacResult);
//}


int ReFactorial(int Num)
{
	if (Num == 1)
	{
		return 1;
	}

	return Num * ReFactorial(Num - 1);
}

int SumToN(int Num)
{
	if (Num == 1)
	{
		return 1;
	}

	return Num + SumToN(Num - 1);
}

int AAA()
{
	while (1)
	{
		printf("1st while! start\n");
		break;
		printf("1st while! end\n");
	}

	while (1)
	{
		printf("2nd while! start\n");
		return 0;
		printf("2nd while! end\n");
	}

	while (1)
	{
		printf("3rd while! start\n");
		break;
		printf("3rd while! end\n");
	}

	return 0;
}


int main()
{/*
	unsigned int nResult = 0, e = 0;
	float  a = 0, b = 0, c = 0, d = 0;
	nResult = CalculatorSum(1, 1);
	a = CalculatorMinus(20, 10);
	b = CalculatorMultiply(2, 3);
	c = CalculatorDivide(10, 3);
	d = CalculatorRemain(10, 3);
	e = CalculatorSUPER(10, 2);*/
	/*printf("���ϱ� ���� ��� = %d\n", nResult);
	printf("���� ���� ��� = %f\n", a);
	printf("���ϱ� ���� ��� = %f\n", b);
	printf("������ ���� ��� = %f\n", c);
	printf("������ ���� ��� = %f\n", d);
	printf("�����Լ� ���� ��� = %d\n", e);
	printf("�Լ� ����!\n");
	CallFunction();*/

	//// �ݺ���
	//// for��
	//for (/*�ʱ� ����*/int i = 0;/*�ݺ� ���� üũ*/ i < 10;/*�ݺ� �� ó��*/++i)
	//{   //  <-�ݺ� ó���� �ڵ� ����
	//	
	//	printf("%d hello\n", i);
	//}   //  <-�ݺ� ó���� �ڵ� ��

	///*for (int i = 0; i < 10; ++i)
	//{
	//	printf("hello\n");
	//}*/

	//for (int a = 0; a < 5; ++a)
	//{
	//	printf("%d hello a\n", a);
	//}

	//for (int b = 0; b < 10; b += 2)
	//{
	//	printf("%d hello b\n", b);
	//}

	// factoria
	// 5 factoria ���ض�
	// 5 * 4 * 3 * 2 * 1 =
	
	/*for (int i = 1; i <= 10; ++i)
	{
		facresult *= i;
	}*/

	/*int facresult = 1;
	int facnum = 5;
	for (int i = facnum; i > 0; --i)
	{
		facresult *= i;
	}
	printf("facresult = %d", facresult);*/

	/*int Factorial(int Num);
	{
		int FacResult = 1;
		for (int i = 5; i > 0; --i)
		{
			FacResult *= i;
		}

		return FacResult;

		printf("FacResult = %d", FacResult);
	}*/
	
	//printf("ReFactorial = %d\n", ReFactorial(5));

	
	//printf("SumToN = %d\n", SumToN(5));

	//while ��
	//int nResult = 1;
	//int i = 1;
	//while (i <= 10) // <- �� ���ǽ��� true�� �Ʒ� ���� �ȿ� �ڵ带 �����Ѵ�. false�̸� while���� �����ϰ� �����ڵ����
	//{ //<- �ݺ� ó���� �ڵ� ����
	//	nResult *= i;
	//	i++;

	//	break; //<- �� ��ɾ ������ while ��� ����. �Ʒ� �ڵ� ���� �ȵ�
	//} //<- �ݺ� ó���� �ڵ� ����

	//printf("while Factorial = %d", nResult);

	// 0~Num ¦���� ���ϱ�
	//int i = 0, Num = 10;
	//int nResult = 0;
	//while (i <= Num)
	//{
	//	i++;
	//	if (i % 2 != 0)
	//		continue; // ���� �ڵ带 ���������ʰ� while �ڵ带 ��� ����
	//		
	//  nResult += i;
	//}
	//printf("0~Num EvenSum=%d", nResult);

	//���� �ڵ� for������

     int nResult = 0;
	 int fResult = 0;
	for (int i = 0; i <= 10; ++i)
	{
		if (i % 2 != 0)
		{
			fResult += i;
			continue;
		}
		nResult += i;
		
	}
	printf("0~Num EvenSum=%d\n", nResult);
	printf("0~Num EvenSum=%d\n", fResult);
  
	AAA();

}
