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
		printf("\n소득세를 계산하시겠습니까? 0)NO 1)YES  : ");
		scanf_s("%d", &nInput);


		int  value = 0;
		switch (nInput)
		{
		case InputType::Quit:
			bRun = false;
			break;
			
			
		case InputType::Start:
			
			printf("연간 총 소득을 입력해주세요(만 단위) :");
			scanf_s("%d", &value);


			if (value > 100000)
			{
				printf("당신의 소득세는 45per 입니다.");
			}
			else if (value <= 100000 && value > 50000)
			{
				printf("당신의 소득세는 42per 입니다.");
			}
			else if (value <= 50000 && value > 30000)
			{
				printf("당신의 소득세는 40per 입니다.");
			}
			else if (value <= 30000 && value > 15000)
			{
				printf("당신의 소득세는 38per 입니다.");
			}
			else if (value <= 15000 && value > 8800)
			{
				printf("당신의 소득세는 35per 입니다.");
			}
			else if (value <= 8800 && value > 4600)
			{
				printf("당신의 소득세는 24per 입니다.");
			}
			else if (value <= 4600 && value > 1200)
			{
				printf("당신의 소득세는 15per 입니다.");
			}
			else if (value <= 1200)
			{
				printf("당신의 소득세는 6per 입니다.");
			}
			break;

		default:
			break;
		}
		
		

	}
}
