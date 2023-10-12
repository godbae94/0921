#include <stdio.h>
#include <vector>
#include <string>
#include"Card.h"
#include <random>

/*
1. 52개의 카드으로 게임을 합니다.
2. 52개의 카드를 무작위로 섞습니다.
3. 게임이 시작되면 카드 하나를 오픈 합니다.
4. 플레이어는 다음카드가 오픈된 카드보다 높은 카드인지 낮은 카드인지에 대해 배팅을 합니다.
5. 다음 카드를 오픈하고 높은지 낮은지에 대한 선택이 맞으면 승리 틀리면 패배
6. 카드를 1이 가장 낮고 K가 가장 높습니다. 같은 숫자라면 높은 문양의 카드가 승리한다.
7. 문양은 스페이드 > 다이아 > 하트 > 클로버 순으로 높습니다.
*/

void Shuffle(std::vector<CCard>& Cards)//보이드함수생성 Shuffle이름.std::vector<CCard>&변수생성 Cards를값으로한다.
{
	std::random_device rd;//std::random_device 변수생성. 이름은rd
	//std::mt19937 mt(1234);//1234는 시드(seed)값이라고 해서 초기에 주어지는 키값, 같은시드면 랜덤 숫자가 일정하게나온다.
	std::mt19937 mt(rd.entropy());// 시드값도 랜덤으로 부여해서 거의 같은 결과가 나오지 않는다.
	std::uniform_int_distribution<int> dist(0, Cards.size()-1);
	//std::uniform_int_distribution<int>변수생성 이름은 dist 범위는 0부터 Cards사이즈의-1까지의 숫자중 하나가 나온다.
	
	for (int i = 0; i < 100;++i)//int i는 0, i는 100보다크지않다, i는 1씩커진다.
	{
		int firstindex = dist(mt);//int형변수 firstindex를생성. dist(mt){난수}값을 넣어준다. firstindex의범위는 0~[Cards.size()-1]
		int secondindex = dist(mt);//int형변수 secondindex를생성. dist(mt){난수}값을 넣어준다. secondindex의 범위는 0~[Cards.size()-1]
		//두개의랜덤값을 가진다.

		CCard temp = Cards[firstindex]; //CCard를변수로하는 temp생성. Cards범위중 [firstindex]위치값을 나타내는 값을 temp에넣어준다.
		Cards[firstindex] = Cards[secondindex];//Cards범위중[secondindex]위치값을 [firstindex]에 넣어준다
		Cards[secondindex] = temp;//temp의값을 [secondindex]에넣는다.

	}


}
//bool변수로 CompareCard 함수생성 const CCard& CardA 와 const CCard& CardB를 파라메타로한다
bool CompareCard(const CCard& CardA, const CCard& CardB)
{
	int ScoreA = CardA.m_number * 10 + CardA.m_mark;//int형의 ScoreA를생성.m_number를 우선비교하기위해 10을곱하여 그차이를 확실히한다.
	             //CardA에 m_number값을넣는다...// CardA에 m_mark값을넣는다.
	int ScoreB = CardB.m_number * 10 + CardB.m_mark;//int형의 ScoreB를생성.m_number를 우선비교하기위해 10을곱하여 그차이를 확실히한다.
	             //CardB에 m_number값을넣는다. // CardB에 m_mark값을넣는다.
	return ScoreA > ScoreB; //ScoreA가ScoreB보다크면 TRUE 아니면 FALSE를 반환한다.
}




int main()//int형 main 함수를 생성한다.
{
	std::vector<CCard> Cards;//std::vector<CCard>변수형태를 생성한다.이름은 Cards이다.
	
	// for문을 설정한다.
	//int형 i를 생성한다. 기본값은 CardMark::Clover(1)의 값으로설정한다. i의범위는CardMark::MaxMark(5)의값보다작다.i는 1씩 늘어난다.
	for (int i = CardMark::Clover; i < CardMark::MaxMark; ++i)
	{
		//1,2,3,4,5,6,7,8,9,10,J(11),Q(12),K(13)
		for (int j = 1; j <= 13; ++j)//int형j를 생성한다.기본값은1.j의범위는 13보다 작거나같다. j는 1씩늘어난다.
		{
			CCard card;//CCard를 변수로하는 card를 생성
			card.m_mark = (CardMark)i;//card.m_mark에 (CardMark)i의 값을 넣는다.
			card.m_number = j;//card.m_number에 j에 값을 넣어준다.
			Cards.push_back(card); //배열뒤에 card에 값을 붙인다
		}
	}

	Shuffle(Cards);//Shuffle함수를  Cards의값을 넣어작동한다.

	bool bRun = true;// bRun상태이면 true이다.
	int i = 0;//int변수를 가진i를생성.기본값은0이다.
	while (bRun)//바로밑에 코드가 bRun(true)이면진행하고 아니(false)면 멈추고 종료한다.
	{
		printf("첫번째 카드는 %s 입니다.\n", Cards[i].GetCardStr().c_str());
		//Cards[i]에값을  GetCardStr()를통해 합쳐주고 스트링으로 출력하기위해 c_str()를 붙혀 프린트한다.
		int input = 0;//input = 1 이면 Cards[0] 높다.
		printf("두번째 카드가 높으면 0, 낮으면 1을 입력해주세요 : ");
		scanf_s("%d", &input);//input 값을 참조해서 %d에 입력한다.
		system("cls");//실행한코드를 삭제한다.

		printf("첫번째 카드는 %s 입니다.\n", Cards[i].GetCardStr().c_str());
		//Cards[i]에값을  GetCardStr()를통해 합쳐주고 c_str()를 이용해 string을 프린트한다
		printf("두번째 카드는 %s 입니다.\n", Cards[i + 1].GetCardStr().c_str());
		//Cards[i+1]에값을  GetCardStr()를통해 합쳐주고 c_str()를 이용해 string을 프린트한다
		
		// IsFirstHigh = 1 이면 Cards[0] 높다.
		bool IsFirstHigh = CompareCard(Cards[i], Cards[i + 1]);//bool형 변수 IsFirstHigh를 생성한다.
		//IsFirstHigh에 Cards[i]와 Cards[i + 1]를 비교하는 CompareCard함수를넣는다.
		
		//IsFirstHigh가 true이면 1, false이면 0이다.
		//input값은 "두번째 카드가 높으면 0, 낮으면 1을 입력해주세요"에서 선택한것이다.
		if (IsFirstHigh == input) //IsFirstHigh값과 input에값이 같으면(true이면) 아래코드를 실행한다.
		{
			printf("맞췄다.\n"); //맞췄다를 프린트한다.
		}
		else //false이면
		{
			printf("틀렸다.\n");//틀렸다를 프린트한다.
		}

		i += 2;//사용한카드는 뽑지않기위해 +2를 해준다
	}


	//for (CCard& card : Cards)
	//{
	//	card.printCard();//card값을 넣은 함수를 출력한다.
	//}
}