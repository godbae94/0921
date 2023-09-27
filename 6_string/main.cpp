#include <stdio.h>
#include <iostream>
#include <assert.h>

//_pstring="abcdefg";
unsigned int getstringlength(const wchar_t* _pstring)
{
	int i = 0;
	while (1)
	{
		wchar_t c = *(_pstring + i);

		if (c == '\0')
		{
			break;
		}
		++i;
	}
	return i;
}

//_dest : "abcde"
//_psource : "fghi"
void stringcat(wchar_t* _dest, unsigned int size, const wchar_t* _psource)
{
	int destlen = getstringlength(_dest);
	int sourcelen = getstringlength(_psource);

	if (size < destlen + sourcelen + 1)// \0���� 1���� ���ʿ�
	{
		assert(nullptr);
	}

	wchar_t c = *(_dest + destlen);

	for (int i = 0; i < sourcelen + 1 ; ++i)
	{
		*(_dest + destlen + i) = *(_psource + i);
	}

}

int stringcmp(const wchar_t* _pleft, const wchar_t* _pright)
{
	int leftlen = getstringlength(_pleft);
	int rightlen = getstringlength(_pright);

	int nloop = (leftlen > rightlen) ? leftlen : rightlen;

	for (int i = 0; i < nloop; i++)
	{
		if (_pleft[i] == _pright[i])
			continue;
		return (_pleft[i] > _pright[i]) ? 1 : -1;
	}

	return 0;

}




int main()
{
	//���� ó��
	//�ƽ�Ű �ڵ� ��ũ : https://namu.wiki/w/�ƽ�Ű%20�ڵ�
	//multi-byte
	//127�� �ƽ�Ű �ڵ� ���� ǥ��, ���ڿ� ���� ���������� ũ�Ⱑ �����
	//�������� ȣȯ�� ���� �ʴ� ������� �ٸ� �ý������� ������ ���ڸ� �˾ƺ� �� ���� ����
	//�Ϻ��� �ؽ�Ʈ ������ �ѱ� �����쿡�� ������ �� ���� ������������ ����
	//ö���� �ڱ��� ǥ�⸸�� ���� ���ڵ�. �ܱ��� ���� ���� �ٸ� ����ü�谡 �ʿ��� ��� ������

	char c1 = 'a'; //1����Ʈ(0~255), �ѱ��� �϶��� ' '���
	printf("c1=%c\n", c1);// �ѱ��� char ��½� %c ���

	setlocale(LC_ALL, "korean");// multi-byte ����

	char arrC1[10] = "abc�ѱ�"; // ����� 1����Ʈ, �ѱ��� 2����Ʈ ���, ���ڿ� �϶��� " "���
	printf("arrC1=%s\n", arrC1);// ���ڿ� char ��½� %s ���

	// ���̵� ����(wide character)
	// multi-byte�� ������ �ذ��ϱ� ���� ���� �����ڵ� ���
	// ������ ���� ��� ���ڸ� ǥ���� �� �ֱ� ������ �ֱٿ� ���� ����
	// ���� ���� ����ϴ� ����� UTF-8�� �ִ�
	// 2byte(0~65535���� �տ� ������ 1��Ʈ�� �����ϸ� 32767�� ǥ������)

	wchar_t wc1 = L'a'; //wchar_t���� ���ڸ� ������ �տ� L�� ���δ�.
	wprintf(L"wc1=%c\n", wc1);// wchar_t ���� ����Ҷ��� wprintf�����, ��¹��ڿ�(L"") �տ� L�� ���δ�.

	_wsetlocale(LC_ALL, L"korean"); //���̵� ���� ��� ����

	wchar_t arrWC1 [10] = L"abc�ѱ�";// wchar_t�迭�� ���ڿ��� ������ �տ� L�� ���δ�.
	wprintf(L"arrWC1=%s\n", arrWC1); //wchar_t ���� ����Ҷ��� wprintf�����, ��¹��ڿ�(L"") �տ� L�� ���δ�.

	wchar_t szWchar[10] = L"abcdefghi";//�������� ���ڿ� �������̶�� ǥ��� '\0'�� ���ڷ� ����.
	wprintf(L"szWchar=%s\n", szWchar);

	wchar_t szWcharlen[20] = L"abcdefg";
	int size = wcslen(szWcharlen); // ���ڿ� ���� ���ϱ� (iostream ���̺귯�� �Լ�)
	size = getstringlength(szWcharlen); // ���ڿ� ���� ���ϱ� (���� ���� �Լ�)
	printf("szWcharlen size=%d\n", size);


	stringcat(szWcharlen, 20, L"hijk"); // ���ڿ� ���̱�(iostream ���̺귯�� �Լ�)
	wprintf(L"szWcharlen=%s\n", szWcharlen);

	wcscpy_s(szWcharlen, L"abcdef");//���� ���ڿ����ٰ� �ڿ� ���ڿ��� �����ؼ� �ִ´�.
	
	

	int nResult = stringcmp(L"cbcdef", L"abcdef"); //������ 0 ,�տ� ������ ������ ������ 1, �ڿ� ���� ������ ������ -1
	printf("nResult=%d\n", nResult);
}