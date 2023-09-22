#include <stdio.h>

// 함수형
// unsigned int : 반환 <-Output
// CalculatorSum : 함수 이름
// (int x, int y) : 매개 변수(파라메타)<-Input
unsigned int CalculatorSum(int x, int y)
{//-> 함수 시작
	printf("함수 시작했다.\n");

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
	printf("더하기 실행 결과 = %d\n", nResult);
	printf("빼기 실행 결과 = %f\n", a);
	printf("곱하기 실행 결과 = %f\n", b);
	printf("나누기 실행 결과 = %f\n", c);
	printf("나머지 실행 결과 = %f\n", d);
	printf("수퍼함수 실행 결과 = %d\n", e);
	printf("함수 종료!\n");
	CallFunction();
}