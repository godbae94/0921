#include <stdio.h>

int Sum(int a, int b)
{
	return a + b;
}

int Minus(int a, int b)
{
	return a - b;
}

int Multiply(int a, int b)
{
	return a * b;
}

int divide(int a, int b)
{
	return a / b;
}

int remain(int a, int b)
{
	return a % b;
}

int main()
{

	bool bRun = true;
	while (bRun)
	{
		int ninput = 0;
		int num1, num2;

		printf("� ������ �Ͻðڽ��ϱ�?(0:���ϱ�, 1:����, 2:���ϱ�, 3:������, 4:������:");

		scanf_s("%d", &ninput);
		switch (ninput)
		{
		case 0://���ϱ�
		{
			printf("���� 2���� �Է��ϼ���(num1 num2):");
			scanf_s("%d %d", &num1, &num2);
			printf("�μ��� ���� %d�Դϴ�.\n", Sum(num1, num2));
		}
		break;

		case 1://����
		{
			printf("���� 2���� �Է��ϼ���(num1 num2):");
			scanf_s("%d %d", &num1, &num2);
			printf("�μ��� ����� %d�Դϴ�.\n", Minus(num1, num2));
		}
		break;

		case 2://���ϱ�
		{
			printf("���� 2���� �Է��ϼ���(num1 num2):");
			scanf_s("%d %d", &num1, &num2);
			printf("�μ��� ���� %d�Դϴ�.\n", Multiply(num1, num2));
		}
		break;

		case 3://������
		{
			printf("���� 2���� �Է��ϼ���(num1 num2):");
			scanf_s("%d %d", &num1, &num2);
			printf("�μ��� ������� %d�Դϴ�.\n", divide(num1, num2));
		}
		break;

		case 4://������
		{
			printf("���� 2���� �Է��ϼ���(num1 num2):");
			scanf_s("%d %d", &num1, &num2);
			printf("�μ��� �������� %d�Դϴ�.\n", remain(num1, num2));
		}
		break;



		printf("���⸦ �����Ͻðڽ��ϱ�?(0:no 1:yes)\n");
		scanf_s("%d", &ninput);

		switch (ninput)
		{
		case 1:
			bRun = false;
			break;
		}
		}

		return 0;

	}
}