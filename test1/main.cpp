#include<stdio.h>
#include<iostream>

int main()
{
	//2에 배수 출력하기(0~100)
	//0 2 4 6 8 ~ 96 98 100
	/*
	for (int i = 0; i <= 10; ++i)
	{
		if (i % 2 == 0)
		{
			printf(" %d \n", i);
		}
	}
	*/

	//n은 숫자 하나를 입력받기 스캔에프
	//n에 배수 출력하기 (0~100)

	/*int n = 0;
	scanf_s("%d", &n);

	for (int i = 0; i < 100; ++i)
	{
		if (i * n % n == 0, i*n < 100)
			printf("%d\n", n * i);

	}*/

	// (0~100) 2에 배수에 갯수 출력
	/*int a = 0;

	for (int i = 1; i <= 10; ++i)
	{
		if (i % 2 == 0)
		{
			a++;
					}
	}
	printf("%d", a);*/


	// abcdef를 역으로 출력하기 fedcba
    /* wchar_t szWChar[20] = L"abcdef";
    
    for (int i = 5; i >= 0; --i)
    {
       wprintf(L"%c", szWChar[i]);
    }*/
     
	//wchar_t 형으로 문자 입력 받기
	
	 
	//"szWCharInput" 라는 이름을 가진 것을
	//"wchar_t" 변수형으로 설정하고
	//[20] 의 크기로 설정하고
	// L"" 값을 초기값을 넣는다.
    wchar_t szWCharInput[20] = L"";
	 
	//  wscanf_s는 입력을 받는 기능을 사용하겠다.
	//  L"%Ls"변수형태로 입력을 받겠다.
	//  szWCharInput 변수에 입력한 값을 넣어주겠다.
	//  (unsigned)_countof(szWCharInput)는 값을 넣을 변수에 크기
	wscanf_s(L"%Ls", szWCharInput, (unsigned)_countof(szWCharInput));
	 
	//wprintf 출력하는 기능을 사용하겠다.
	//L"szWCharInput=%s\n\n" 문자형태로 출력하겠다.
	// %s위치에 szWCharInput을 값을 출력한다.
	wprintf(L"szWCharInput=%s\n\n", szWCharInput);

	//입력 받은 문자열에서 'a' 문자 갯수 출력
	
	int a = 0;// 'a'를 int형으로 설정하겠다. 초기값은 0으로한다.
	for (int i = 0; i < 20; ++i) // for문을 이용한다. int형 i의 초기값은 0이고 20보다 작다, i는 1씩 더해진다. i의범위만큼 반복하겠다.
	{ //코드 반복을 시작한다.
		if (szWCharInput[i]=='a')//if문을 이용한다. szWCharInput[i]의 값이 a라면 
		{
			a++;                 //a++를 실행한다.
		}
	} // 코드반복을 끝낸다.
	printf("%d", a);//a의값을 %d 위치에 출력한다.



}