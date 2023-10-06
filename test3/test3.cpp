#include <stdio.h>
#include <iostream>

int cSum(int a, int b) 
{
	// int를 변수로한 i를 만든다. i에 a를 집어넣는다. 
	// i <= b가 참이면 바로아래쪽 가로 안에 코드를 실행한다. 거짓이면  for문이 종료되고 다음 코드가 실행된다.        
	// i는 바로아래쪽 가로 안에 코드를 실행한 후에 1씩 늘어난다.    
	int j = 0;// int를 변수로한 j를 만든다. 기본값은 0으로한다.
	for (int i = a; i <= b; ++i)
	{
		
		j +=i;// j에 i값을 더한다.
		
	}
	return j;

}





void ScanfinputNum(int& a, int& b)
{
	printf("\n숫자 하나를 입력하세요:");
	scanf_s("%d", &a);
	printf("\n숫자 하나 더 입력하세요:");
	scanf_s("%d", &b);
}



int main()
{
	int a = 0, b = 0;
	ScanfinputNum(a, b);
	printf("\nSum 결과는 %d 입니다.\n", cSum(a, b));

}