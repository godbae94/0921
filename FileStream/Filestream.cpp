#include<stdio.h>
#include<string>
#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
using namespace std;

struct stTest//struct 구조체를 만든다. 이름은 stTest
{
	string m_name ;//string변수를생성한다. m_name이라고 이름짓는다. 
	int m_math ;//int변수를 생성한다.m_math라고 이름짓는다.
	int m_eng ;//int변수를 생성한다.m_eng라고 이름짓는다.
	int m_lang ;//int변수를 생선한다.m_lang라고 이름짓는다.
	
	stTest(string name= "", int math=0, int eng=0, int lang=0) ://stTest구조체안에 변수들을 만들고 기본값을 정한다.
	     m_name(name), m_math(math), m_eng(eng), m_lang(lang) {}//각각매치 시켜준다.

	void printTest()
	{
		printf("name=%s, math=%d, eng=%d, lang=%d\n", m_name.c_str(), m_math, m_eng, m_lang);
	}

	//& = 레퍼런스 참조 , 원본을 보여주는것
	void SetData(string& str)//보이드함수를 만든다.반환값은없다. 이름은 SetData이고 ()안에 변수를 넣는다.
		 
		//string& 참조변수생성하고 이름은 str
	{
		stringstream ssTest(str);// str문자열을 stringstream 변수형태로 만든다. 이름은 ssTest로 짓는다.
		string line; // 읽어온 string 담아둘 변수

		//ssTest을 왼쪽부터 ','를 기준으로 문자를 읽어서 line에 넣는다.
		//getline 결과가 false(더이상 읽을 문자열이 없다)면 종료
		//while ()안에 값이 true면 진행 false면 종료
		while (getline(ssTest, line, ','))
		{
			//line에서 erase기능을 사용한다.()
			line.erase(remove(line.begin(), line.end(), ' '), line.end());
			// 범위는(remove(line.begin(), line.end(), ' ')) 부터 line.end()까지
			// line.begin(), line.end(), ' '  : 라인 처음 부터 끝까지 ' '의영역을 표시한다 
			//printf("line=[%s]\n", line.c_str());//line.c_str() = line에 문자열을 %s안에 넣어 프린트한다.

			int index = line.find('=');//int변수를생성한다.이름은index라고짓는다. line.find('=') : line 안에서 '='의 포인트를 찾는다.
			string leftstr = line.substr(0, index);//string변수를생성한다.이름은 leftstr이라짓는다.line을 0부터 index길이만큼 자른다.
			string rightstr = line.substr(index + 1, line.length() - index);//string변수를생성한다. 이름은 rightstr이라고짓는다. 
			//line을 index+1위치부터 line의전체길이에서 index길이만큼뺀 길이만큼 자른다.
			if (leftstr == "name")//만약 leftstr값이 name와 같다면 바로 밑에 코드를 실행한다.
			{
				m_name = rightstr;//rightstr값을 m_name에 넣어준다.
			}
			else if (leftstr == "math")//만약 leftstr값이 math와  같다면 바로 밑에 코드를 실행한다.
			{
				m_math = stoi(rightstr);//rightstr(int변수이므로 앞에 stoi를 붙여서 써준다.)에 값을 m_math에 넣어준다.
			}
			else if (leftstr == "eng")//만약 leftstr값이 eng와  같다면 바로 밑에 코드를 실행한다.
			{
				m_eng = stoi(rightstr);//rightstr(int변수이므로 앞에 stoi를 붙여서 써준다.)에 값을 m_eng에 넣어준다.
			}
			else if (leftstr == "lang")//만약 leftstr값이 lang와 같다면 바로 밑에 코드를 실행한다
			{
				m_lang = stoi(rightstr);//rightstr(int변수이므로 앞에 stoi를 붙여서 써준다.)에 값을 m_lang에 넣어준다.
			}
		}

	}


};




int main()
{
	////파일 쓰기
	//std::ofstream writeFile;
	//writeFile.open("test.txt");//"test.txt"파일을 연다(파일이 없다면은 생성한다.)

	//std::string strTest = "test 1234 abcd 입니다.\n";
	//writeFile.write(strTest.c_str(), strTest.size());
	//writeFile.write(strTest.c_str(), strTest.size());

	//writeFile.close();//파일을 열었으면 반드시 닫기 실행

	//파일 읽기
	std::ifstream readFile;//std::ifstream라는 변수를생성하고 readFile이라고 이름붙인다.
	readFile.open("test.txt");//"test.txt"를 모두 가져와서 readFile에 집어넣는다

	vector <stTest> vectest;//stTest구조체공간을 배열로적용한다. 이름은 vectest라고한다
	stTest aaa("aaa", 80, 60, 70);//stTest 함수를 만들고 aaa라고 이름짓는다. "aaa", 80, 60, 70을 대입한다.
	vectest.push_back(aaa); //push_back = 배열 뒤에다  stTest aaa("aaa", 80, 60, 70);의 값을 넣는다.
	stTest bbb("bbb", 90, 30, 40);//stTest 함수에 bbb라고 이름짓고 bbb, 90, 30, 40을 대입한다.
	vectest.push_back(bbb); //배열 뒤에다  stTest bbb("bbb", 90, 30, 40);의 값을 넣는다.
	stTest ccc("ccc", 20, 90, 80);//stTest 함수에 ccc라고 이름짓고 bbb, 20, 90, 80을 대입한다.
	vectest.push_back(ccc); //배열 뒤에다  stTest ccc("ccc", 20, 90, 80);의 값을 넣는다.
	stTest ddd("ddd", 30, 40, 50);
	vectest.push_back(ddd);


	if (readFile.is_open())//만약 readFile이 열려있다면 실행한다.
	{
		while (!readFile.eof())//읽는 (eof=)포인트가 더이상 없으면 false
		{
			std::string str;//std::string이라는 변수를 생성하고 str이라고 이름짓는다.
			std::getline(readFile, str);//readFile에 텍스트를 한줄 읽어서 str에 넣는다
			printf("str=%s\n", str.c_str());//str의 전체문자열을 프린트한다.
			SetData(str);//pushStTest함수에 str을 집어넣는다.
        }
		readFile.close(); //readFile을 모두 닫는다
	}

	for (stTest& test : vectest)//stTest& =구조체를 참조하고 test라고 이름짓고 vectest를 집어넣어 처음부터 끝까지 반복한다.
	{
		test.printTest();//vectest를 집어넣은 test를 프린트한다.
	}
}