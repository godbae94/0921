#include <stdio.h>
#include <iostream>

int cSum(int a, int b) 
{
	// int�� �������� i�� �����. i�� a�� ����ִ´�. 
	// i <= b�� ���̸� �ٷξƷ��� ���� �ȿ� �ڵ带 �����Ѵ�. �����̸�  for���� ����ǰ� ���� �ڵ尡 ����ȴ�.        
	// i�� �ٷξƷ��� ���� �ȿ� �ڵ带 ������ �Ŀ� 1�� �þ��.    
	int j = 0;// int�� �������� j�� �����. �⺻���� 0�����Ѵ�.
	for (int i = a; i <= b; ++i)
	{
		
		j +=i;// j�� i���� ���Ѵ�.
		
	}
	return j;

}





void ScanfinputNum(int& a, int& b)
{
	printf("\n���� �ϳ��� �Է��ϼ���:");
	scanf_s("%d", &a);
	printf("\n���� �ϳ� �� �Է��ϼ���:");
	scanf_s("%d", &b);
}



int main()
{
	int a = 0, b = 0;
	ScanfinputNum(a, b);
	printf("\nSum ����� %d �Դϴ�.\n", cSum(a, b));

}