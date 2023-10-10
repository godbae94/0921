#include <stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<sstream>

// ���ӽ����̽��� ���� �ĺ��ڷ� �������� ���̺귯���� ����Ҷ� �̸� ���� �浹�� �����ϱ� ���ؼ� ���
using namespace std;//std �� �̸� ������ �������ڴ�. std ���̺귯�� �Լ� �տ� std�� �������ʾƵ� �ȴ�.

int main()
{
	/*
	* string �̶�?
	*  - c++ stl���� �����ϴ� Ŭ������, ���ڿ��� �ٷ�� Ŭ����
	*  c������ char[]�� ���·� ���ڿ��� �ٷ���ٸ�, c++������ ���ڿ��� �ϳ��� ���� typeó�� ���
	*  ���ڿ��� �پ��ϰ� ���� �ٷ� �� �ְ� ���ش�.
	*  char*, char[] �� �ٸ��� ���ڿ��� ���� '\0' ���ڰ� ���� ������, ���ڿ��� ���̸� �������� ���� �����ϴ�.
	*/

	wchar_t chars[20] = L"abcdef";
	int result = wcscmp(chars, L"abcdef");
	wcscpy_s(chars, 20, L"ghijkl");

	//������ : std::string
	//�����̸� : strA
	//�⺻�� : ("abcdef")
	std::string strA("abcdef");
	printf("strA = %s\n", strA.c_str());//���ڿ� ����� c_str()�� ����Ͽ� ���
	size_t size = strA.size();// ���ڿ� ũ�� ���ϱ�
	size_t len = strA.length(); // ���ڿ� ���� ���ϱ�

	std::string A("12");
	std::string B("34");
	A += B;//A���ٰ�B�� ���δ�.
	printf("A = %s, B = %s\n", A.c_str(), B.c_str());
	
	A = B;//A�� B�� �����Ѵ�.
	printf("A = %s, B = %s\n", A.c_str(), B.c_str());
	if (A == B)// ���ڿ� �� ������ ����
	{
		printf("A�� B�� ����.\n");
	}

	std::wstring wstr;//wchar_t�� string
	//auto : ������ ���� ���¿� ���� �ڵ����� �������� ���� �ȴ�.
	//literals : https://learn.microsoft.com/ko-kr/cpp/cpp/string-and-character-literals-cpp?view=msvc-170
	auto stringS = L"abcdef"s; // stirng ������ ǥ��

	double d = 3.14;
	string strD = to_string(d);//���� -> ���� ��ȯ
	printf("strD = %s\n", strD.c_str());

	string toParse = " 123USD";
	size_t index = 0;
	// stoi(int), stof(float), stod(double), stol(long)
	int nresult = stoi(toParse, &index);//���� -> ���ڷ� ��ȯ
	printf("stoi nresult = %d\n", nresult);// nresult : ��ȯ�� ����
	printf("toParse index Character = %c\n", toParse[index]);// index : Parse�� �Ұ����� ���� ����Ʈ

	string findstr = "123SABC456SORRY";
	int nPointL = findstr.find('S');//����ã��
	printf("find point[%d] character = %c\n", nPointL, findstr[nPointL]);// nPointL : ã�� ���ڿ� ��ġ
	int nPointR = findstr.rfind('S');
	printf("rfind point[%d] character = %c\n", nPointR, findstr[nPointR]);// nPointR : ã�� ���ڿ� ��ġ

	string strleft = findstr.substr(0, nPointL);// ���ڿ� �߶���� 0���� nPointL�� ���̸�ŭ
	string strcenter = findstr.substr(nPointL, nPointR - nPointL);//nPointL�� ������ nPointR(11)���� - nPointL(4)���� = 7�� ���̸�ŭ
	string strright = findstr.substr(nPointR, findstr.length() - nPointR);
	printf("strleft=%s\nstrcenter=%s\nstrright=%s\n"
		, strleft.c_str(), strcenter.c_str(), strright.c_str());

	string testStr = "1,2,3,4,5,6,7,8,9";

	stringstream ssTest(testStr);// string ���ڿ��� stringstream �������·� �����.
	string line; // �о�� string ��Ƶ� ����
	
	//ssTest�� ���ʺ��� ','�� �������� ���ڸ� �о line�� �ִ´�.
	//getline ����� false(���̻� ���� ���ڿ��� ����)�� ����

	//while ()�ȿ� ���� true�� ���� false�� ����
	while (getline(ssTest, line, ','))
	{
		printf("line=%s\n", line.c_str());
	}

	// ��Ʈ������ Ư�� ���� ����
	// testStr.erase : testStr���� esrase ����� ȣ���Ѵ�.
	// 
	testStr.erase(remove(testStr.begin(), testStr.end(), ','), testStr.end());
	printf("testStr=%s\n", testStr.c_str());

}