#include<stdio.h>
#include<iostream>
enum InputType
{
	Quit = 0,
	Start,
	
};





int main()
{
	bool bRun = true;

	while (bRun)
	{
		InputType nInput = InputType::Quit;
		int a = 0, b = 0;
		printf("\n�ҵ漼�� ����Ͻðڽ��ϱ�? 0)NO 1)YES  : ");
		scanf_s("%d", &nInput);


		int  value = 0;
		switch (nInput)
		{
		case InputType::Quit:
			bRun = false;
			break;
			
			
		case InputType::Start:
			
			printf("���� �� �ҵ��� �Է����ּ���(�� ����) :");
			scanf_s("%d", &value);


			if (value > 100000)
			{
				printf("����� �ҵ漼�� 45per �Դϴ�.");
			}
			else if (value <= 100000 && value > 50000)
			{
				printf("����� �ҵ漼�� 42per �Դϴ�.");
			}
			else if (value <= 50000 && value > 30000)
			{
				printf("����� �ҵ漼�� 40per �Դϴ�.");
			}
			else if (value <= 30000 && value > 15000)
			{
				printf("����� �ҵ漼�� 38per �Դϴ�.");
			}
			else if (value <= 15000 && value > 8800)
			{
				printf("����� �ҵ漼�� 35per �Դϴ�.");
			}
			else if (value <= 8800 && value > 4600)
			{
				printf("����� �ҵ漼�� 24per �Դϴ�.");
			}
			else if (value <= 4600 && value > 1200)
			{
				printf("����� �ҵ漼�� 15per �Դϴ�.");
			}
			else if (value <= 1200)
			{
				printf("����� �ҵ漼�� 6per �Դϴ�.");
			}
			break;

		default:
			break;
		}
		
		

	}
}
