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

	if (size < destlen + sourcelen + 1)// \0공간 1개가 더필요
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
	//문자 처리
	//아스키 코드 링크 : https://namu.wiki/w/아스키%20코드
	//multi-byte
	//127개 아스키 코드 문자 표기, 문자에 따라 가변형으로 크기가 변경됨
	//국가간의 호환이 되지 않는 방식으로 다른 시스템으로 보내면 글자를 알아볼 수 없게 깨짐
	//일본어 텍스트 파일을 한글 윈도우에서 열었을 때 뷁어로 깨지는현상이 예시
	//철저히 자국어 표기만을 위한 인코딩. 외국어 교재 같이 다른 문자체계가 필요한 경우 불편함

	char c1 = 'a'; //1바이트(0~255), 한글자 일때는 ' '사용
	printf("c1=%c\n", c1);// 한글자 char 출력시 %c 사용

	setlocale(LC_ALL, "korean");// multi-byte 언어설정

	char arrC1[10] = "abc한글"; // 영어는 1바이트, 한글은 2바이트 사용, 문자열 일때는 " "사용
	printf("arrC1=%s\n", arrC1);// 문자열 char 출력시 %s 사용

	// 와이드 문자(wide character)
	// multi-byte에 문제를 해결하기 위해 나온 유니코드 방식
	// 세계의 거의 모든 문자를 표현할 수 있기 때문에 최근에 많이 사용됨
	// 가장 자주 사용하는 방식은 UTF-8이 있다
	// 2byte(0~65535에서 앞에 검증용 1비트를 제외하면 32767개 표현가능)

	wchar_t wc1 = L'a'; //wchar_t형에 문자를 넣을때 앞에 L을 붙인다.
	wprintf(L"wc1=%c\n", wc1);// wchar_t 형을 출력할때는 wprintf를사용, 출력문자열(L"") 앞에 L을 붙인다.

	_wsetlocale(LC_ALL, L"korean"); //와이드 문자 언어 설정

	wchar_t arrWC1 [10] = L"abc한글";// wchar_t배열에 문자열을 넣을때 앞에 L을 붙인다.
	wprintf(L"arrWC1=%s\n", arrWC1); //wchar_t 형을 출력할때는 wprintf를사용, 출력문자열(L"") 앞에 L을 붙인다.

	wchar_t szWchar[10] = L"abcdefghi";//마지막에 문자에 마지막이라는 표기로 '\0'가 문자로 들어간다.
	wprintf(L"szWchar=%s\n", szWchar);

	wchar_t szWcharlen[20] = L"abcdefg";
	int size = wcslen(szWcharlen); // 문자열 길이 구하기 (iostream 라이브러리 함수)
	size = getstringlength(szWcharlen); // 문자열 길이 구하기 (직접 만든 함수)
	printf("szWcharlen size=%d\n", size);


	stringcat(szWcharlen, 20, L"hijk"); // 문자열 붙이기(iostream 라이브러리 함수)
	wprintf(L"szWcharlen=%s\n", szWcharlen);

	wcscpy_s(szWcharlen, L"abcdef");//앞쪽 문자열에다가 뒤에 문자열을 복사해서 넣는다.
	
	

	int nResult = stringcmp(L"cbcdef", L"abcdef"); //같으면 0 ,앞에 문자의 순번이 빠르면 1, 뒤에 문자 순번이 빠르면 -1
	printf("nResult=%d\n", nResult);
}