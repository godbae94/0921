#include<stdio.h>
#include<string>
#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
using namespace std;

struct stTest//struct ����ü�� �����. �̸��� stTest
{
	string m_name ;//string�����������Ѵ�. m_name�̶�� �̸����´�. 
	int m_math ;//int������ �����Ѵ�.m_math��� �̸����´�.
	int m_eng ;//int������ �����Ѵ�.m_eng��� �̸����´�.
	int m_lang ;//int������ �����Ѵ�.m_lang��� �̸����´�.
	
	stTest(string name= "", int math=0, int eng=0, int lang=0) ://stTest����ü�ȿ� �������� ����� �⺻���� ���Ѵ�.
	     m_name(name), m_math(math), m_eng(eng), m_lang(lang) {}//������ġ �����ش�.

	void printTest()
	{
		printf("name=%s, math=%d, eng=%d, lang=%d\n", m_name.c_str(), m_math, m_eng, m_lang);
	}

	//& = ���۷��� ���� , ������ �����ִ°�
	void SetData(string& str)//���̵��Լ��� �����.��ȯ��������. �̸��� SetData�̰� ()�ȿ� ������ �ִ´�.
		 
		//string& �������������ϰ� �̸��� str
	{
		stringstream ssTest(str);// str���ڿ��� stringstream �������·� �����. �̸��� ssTest�� ���´�.
		string line; // �о�� string ��Ƶ� ����

		//ssTest�� ���ʺ��� ','�� �������� ���ڸ� �о line�� �ִ´�.
		//getline ����� false(���̻� ���� ���ڿ��� ����)�� ����
		//while ()�ȿ� ���� true�� ���� false�� ����
		while (getline(ssTest, line, ','))
		{
			//line���� erase����� ����Ѵ�.()
			line.erase(remove(line.begin(), line.end(), ' '), line.end());
			// ������(remove(line.begin(), line.end(), ' ')) ���� line.end()����
			// line.begin(), line.end(), ' '  : ���� ó�� ���� ������ ' '�ǿ����� ǥ���Ѵ� 
			//printf("line=[%s]\n", line.c_str());//line.c_str() = line�� ���ڿ��� %s�ȿ� �־� ����Ʈ�Ѵ�.

			int index = line.find('=');//int�����������Ѵ�.�̸���index������´�. line.find('=') : line �ȿ��� '='�� ����Ʈ�� ã�´�.
			string leftstr = line.substr(0, index);//string�����������Ѵ�.�̸��� leftstr�̶����´�.line�� 0���� index���̸�ŭ �ڸ���.
			string rightstr = line.substr(index + 1, line.length() - index);//string�����������Ѵ�. �̸��� rightstr�̶�����´�. 
			//line�� index+1��ġ���� line����ü���̿��� index���̸�ŭ�� ���̸�ŭ �ڸ���.
			if (leftstr == "name")//���� leftstr���� name�� ���ٸ� �ٷ� �ؿ� �ڵ带 �����Ѵ�.
			{
				m_name = rightstr;//rightstr���� m_name�� �־��ش�.
			}
			else if (leftstr == "math")//���� leftstr���� math��  ���ٸ� �ٷ� �ؿ� �ڵ带 �����Ѵ�.
			{
				m_math = stoi(rightstr);//rightstr(int�����̹Ƿ� �տ� stoi�� �ٿ��� ���ش�.)�� ���� m_math�� �־��ش�.
			}
			else if (leftstr == "eng")//���� leftstr���� eng��  ���ٸ� �ٷ� �ؿ� �ڵ带 �����Ѵ�.
			{
				m_eng = stoi(rightstr);//rightstr(int�����̹Ƿ� �տ� stoi�� �ٿ��� ���ش�.)�� ���� m_eng�� �־��ش�.
			}
			else if (leftstr == "lang")//���� leftstr���� lang�� ���ٸ� �ٷ� �ؿ� �ڵ带 �����Ѵ�
			{
				m_lang = stoi(rightstr);//rightstr(int�����̹Ƿ� �տ� stoi�� �ٿ��� ���ش�.)�� ���� m_lang�� �־��ش�.
			}
		}

	}


};




int main()
{
	////���� ����
	//std::ofstream writeFile;
	//writeFile.open("test.txt");//"test.txt"������ ����(������ ���ٸ��� �����Ѵ�.)

	//std::string strTest = "test 1234 abcd �Դϴ�.\n";
	//writeFile.write(strTest.c_str(), strTest.size());
	//writeFile.write(strTest.c_str(), strTest.size());

	//writeFile.close();//������ �������� �ݵ�� �ݱ� ����

	//���� �б�
	std::ifstream readFile;//std::ifstream��� �����������ϰ� readFile�̶�� �̸����δ�.
	readFile.open("test.txt");//"test.txt"�� ��� �����ͼ� readFile�� ����ִ´�

	vector <stTest> vectest;//stTest����ü������ �迭�������Ѵ�. �̸��� vectest����Ѵ�
	stTest aaa("aaa", 80, 60, 70);//stTest �Լ��� ����� aaa��� �̸����´�. "aaa", 80, 60, 70�� �����Ѵ�.
	vectest.push_back(aaa); //push_back = �迭 �ڿ���  stTest aaa("aaa", 80, 60, 70);�� ���� �ִ´�.
	stTest bbb("bbb", 90, 30, 40);//stTest �Լ��� bbb��� �̸����� bbb, 90, 30, 40�� �����Ѵ�.
	vectest.push_back(bbb); //�迭 �ڿ���  stTest bbb("bbb", 90, 30, 40);�� ���� �ִ´�.
	stTest ccc("ccc", 20, 90, 80);//stTest �Լ��� ccc��� �̸����� bbb, 20, 90, 80�� �����Ѵ�.
	vectest.push_back(ccc); //�迭 �ڿ���  stTest ccc("ccc", 20, 90, 80);�� ���� �ִ´�.
	stTest ddd("ddd", 30, 40, 50);
	vectest.push_back(ddd);


	if (readFile.is_open())//���� readFile�� �����ִٸ� �����Ѵ�.
	{
		while (!readFile.eof())//�д� (eof=)����Ʈ�� ���̻� ������ false
		{
			std::string str;//std::string�̶�� ������ �����ϰ� str�̶�� �̸����´�.
			std::getline(readFile, str);//readFile�� �ؽ�Ʈ�� ���� �о str�� �ִ´�
			printf("str=%s\n", str.c_str());//str�� ��ü���ڿ��� ����Ʈ�Ѵ�.
			SetData(str);//pushStTest�Լ��� str�� ����ִ´�.
        }
		readFile.close(); //readFile�� ��� �ݴ´�
	}

	for (stTest& test : vectest)//stTest& =����ü�� �����ϰ� test��� �̸����� vectest�� ����־� ó������ ������ �ݺ��Ѵ�.
	{
		test.printTest();//vectest�� ������� test�� ����Ʈ�Ѵ�.
	}
}