#include <stdio.h>

// 함수형
// unsigned int : 반환 <-Output
// CalculatorSum : 함수 이름
// (int x, int y) : 매개 변수(파라메타)<-Input
unsigned int CalculatorSum(int x, int y)
{//-> 함수 시작
	//printf("함수 시작했다.\n");

	return x + y;//<-반환 및 종료 처리

	printf("함수 끝났다.\n");
}//->함수 끝

// 빼기 함수 만들기
unsigned int CalculatorMinus(int x, int y)
{//-> 함수 시작

	return x - y;//<-반환 및 종료 처리

	printf("함수 끝났다.\n");
}//->함수 끝

 // 곱하기 함수 만들기

unsigned int CalculatorMultiply(int x, int y)
{//-> 함수 시작

	return x * y;//<-반환 및 종료 처리

	printf("함수 끝났다.\n");
}//->함수 끝
 
 // 나누기 함수 만들기

float CalculatorDivide(float x, float y)
{//-> 함수 시작
	return float(x / y);//<-반환 및 종료 처리

	printf("함수 끝났다.\n");
}//->함수 끝
 
 // 나머지 함수 만들기

unsigned int CalculatorRemain(int x, int y)
{//-> 함수 시작
	return x % y;//<-반환 및 종료 처리

	printf("함수 끝났다.\n");
}//->함수 끝

unsigned int CalculatorSUPER(int x, int y)
{//-> 함수 시작
	return (x*x+ y*y)*(x + y);//<-반환 및 종료 처리

	printf("함수 끝났다.\n");
}//->함수 끝
//
//factorial 함수
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
	/*printf("더하기 실행 결과 = %d\n", nResult);
	printf("빼기 실행 결과 = %f\n", a);
	printf("곱하기 실행 결과 = %f\n", b);
	printf("나누기 실행 결과 = %f\n", c);
	printf("나머지 실행 결과 = %f\n", d);
	printf("수퍼함수 실행 결과 = %d\n", e);
	printf("함수 종료!\n");
	CallFunction();*/

	//// 반복문
	//// for문
	//for (/*초기 설정*/int i = 0;/*반복 조건 체크*/ i < 10;/*반복 후 처리*/++i)
	//{   //  <-반복 처리할 코드 시작
	//	
	//	printf("%d hello\n", i);
	//}   //  <-반복 처리할 코드 끝

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
	// 5 factoria 구해라
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

	//while 문
	//int nResult = 1;
	//int i = 1;
	//while (i <= 10) // <- 이 조건식이 true면 아래 가로 안에 코드를 실행한다. false이면 while문을 종료하고 다음코드실행
	//{ //<- 반복 처리할 코드 시작
	//	nResult *= i;
	//	i++;

	//	break; //<- 이 명령어를 만나면 while 즉시 종료. 아래 코드 실행 안됨
	//} //<- 반복 처리할 코드 종료

	//printf("while Factorial = %d", nResult);

	// 0~Num 짝수만 더하기
	//int i = 0, Num = 10;
	//int nResult = 0;
	//while (i <= Num)
	//{
	//	i++;
	//	if (i % 2 != 0)
	//		continue; // 다음 코드를 실행하지않고 while 코드를 계속 실행
	//		
	//  nResult += i;
	//}
	//printf("0~Num EvenSum=%d", nResult);

	//위에 코드 for문으로

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
