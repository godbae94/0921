#include<stdio.h>
#include<iostream>

int main()
{
	//2�� ��� ����ϱ�(0~100)
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

	//n�� ���� �ϳ��� �Է¹ޱ� ��ĵ����
	//n�� ��� ����ϱ� (0~100)

	/*int n = 0;
	scanf_s("%d", &n);

	for (int i = 0; i < 100; ++i)
	{
		if (i * n % n == 0, i*n < 100)
			printf("%d\n", n * i);

	}*/

	// (0~100) 2�� ����� ���� ���
	/*int a = 0;

	for (int i = 1; i <= 10; ++i)
	{
		if (i % 2 == 0)
		{
			a++;
					}
	}
	printf("%d", a);*/


	// abcdef�� ������ ����ϱ� fedcba
    /* wchar_t szWChar[20] = L"abcdef";
    
    for (int i = 5; i >= 0; --i)
    {
       wprintf(L"%c", szWChar[i]);
    }*/
     
	//wchar_t ������ ���� �Է� �ޱ�
	
	 
	//"szWCharInput" ��� �̸��� ���� ����
	//"wchar_t" ���������� �����ϰ�
	//[20] �� ũ��� �����ϰ�
	// L"" ���� �ʱⰪ�� �ִ´�.
    wchar_t szWCharInput[20] = L"";
	 
	//  wscanf_s�� �Է��� �޴� ����� ����ϰڴ�.
	//  L"%Ls"�������·� �Է��� �ްڴ�.
	//  szWCharInput ������ �Է��� ���� �־��ְڴ�.
	//  (unsigned)_countof(szWCharInput)�� ���� ���� ������ ũ��
	wscanf_s(L"%Ls", szWCharInput, (unsigned)_countof(szWCharInput));
	 
	//wprintf ����ϴ� ����� ����ϰڴ�.
	//L"szWCharInput=%s\n\n" �������·� ����ϰڴ�.
	// %s��ġ�� szWCharInput�� ���� ����Ѵ�.
	wprintf(L"szWCharInput=%s\n\n", szWCharInput);

	//�Է� ���� ���ڿ����� 'a' ���� ���� ���
	
	int a = 0;// 'a'�� int������ �����ϰڴ�. �ʱⰪ�� 0�����Ѵ�.
	for (int i = 0; i < 20; ++i) // for���� �̿��Ѵ�. int�� i�� �ʱⰪ�� 0�̰� 20���� �۴�, i�� 1�� ��������. i�ǹ�����ŭ �ݺ��ϰڴ�.
	{ //�ڵ� �ݺ��� �����Ѵ�.
		if (szWCharInput[i]=='a')//if���� �̿��Ѵ�. szWCharInput[i]�� ���� a��� 
		{
			a++;                 //a++�� �����Ѵ�.
		}
	} // �ڵ�ݺ��� ������.
	printf("%d", a);//a�ǰ��� %d ��ġ�� ����Ѵ�.



}