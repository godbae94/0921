#include <stdio.h>

// �Լ���
// unsigned int : ��ȯ <-Output
// CalculatorSum : �Լ� �̸�
// (int x, int y) : �Ű� ����(�Ķ��Ÿ)<-Input
unsigned int CalculatorSum(int x, int y)
{//-> �Լ� ����
	printf("�Լ� �����ߴ�.\n");

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


void CallFunction()
{
	printf("void CallFunction!!\n");
 }

int main()
{
	unsigned int nResult = 0, e = 0;
	float  a = 0, b = 0, c = 0, d = 0;
	nResult = CalculatorSum(1, 1);
	a = CalculatorMinus(20, 10);
	b = CalculatorMultiply(2, 3);
	c = CalculatorDivide(10, 3);
	d = CalculatorRemain(10, 3);
	e = CalculatorSUPER(10, 2);
	printf("���ϱ� ���� ��� = %d\n", nResult);
	printf("���� ���� ��� = %f\n", a);
	printf("���ϱ� ���� ��� = %f\n", b);
	printf("������ ���� ��� = %f\n", c);
	printf("������ ���� ��� = %f\n", d);
	printf("�����Լ� ���� ��� = %d\n", e);
	printf("�Լ� ����!\n");
	CallFunction();
}