#include <stdio.h>
#include "calcfunc.h"


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
			printf("�μ��� ���� %d�Դϴ�.\n", AddNum(num1, num2));
		}
		break;

		case 1://����
		{
			printf("���� 2���� �Է��ϼ���(num1 num2):");
			scanf_s("%d %d", &num1, &num2);
			printf("�μ��� ����� %d�Դϴ�.\n", MinusNum(num1, num2));
		}
		break;

		case 2://���ϱ�
		{
			printf("���� 2���� �Է��ϼ���(num1 num2):");
			scanf_s("%d %d", &num1, &num2);
			printf("�μ��� ���� %d�Դϴ�.\n", MultiplyNum(num1, num2));
		}
		break;

		case 3://������
		{
			printf("���� 2���� �Է��ϼ���(num1 num2):");
			scanf_s("%d %d", &num1, &num2);
			printf("�μ��� ������� %f�Դϴ�.\n", DivideNum(num1, num2));
		}
		break;

		case 4://������
		{
			printf("���� 2���� �Է��ϼ���(num1 num2):");
			scanf_s("%d %d", &num1, &num2);
			printf("�μ��� �������� %d�Դϴ�.\n", RemainNum(num1, num2));
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