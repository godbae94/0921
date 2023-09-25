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
			scanf_s("%f %f", &num1, &num2);
			printf("�μ��� ������� %d�Դϴ�.\n", DivideNum(num1, num2));
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