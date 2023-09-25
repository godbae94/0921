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

		printf("어떤 연산을 하시겠습니까?(0:더하기, 1:빼기, 2:곱하기, 3:나누기, 4:나머지:");

		scanf_s("%d", &ninput);
		switch (ninput)
		{
		case 0://더하기
		{
			printf("숫자 2개를 입력하세요(num1 num2):");
			scanf_s("%d %d", &num1, &num2);
			printf("두수의 합은 %d입니다.\n", Sum(num1, num2));
		}
		break;

		case 1://빼기
		{
			printf("숫자 2개를 입력하세요(num1 num2):");
			scanf_s("%d %d", &num1, &num2);
			printf("두수의 빼기는 %d입니다.\n", Minus(num1, num2));
		}
		break;

		case 2://곱하기
		{
			printf("숫자 2개를 입력하세요(num1 num2):");
			scanf_s("%d %d", &num1, &num2);
			printf("두수의 곱은 %d입니다.\n", Multiply(num1, num2));
		}
		break;

		case 3://나누기
		{
			printf("숫자 2개를 입력하세요(num1 num2):");
			scanf_s("%d %d", &num1, &num2);
			printf("두수의 나누기는 %d입니다.\n", divide(num1, num2));
		}
		break;

		case 4://나머지
		{
			printf("숫자 2개를 입력하세요(num1 num2):");
			scanf_s("%d %d", &num1, &num2);
			printf("두수의 나머지는 %d입니다.\n", remain(num1, num2));
		}
		break;



		printf("계산기를 종료하시겠습니까?(0:no 1:yes)\n");
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