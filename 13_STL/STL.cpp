#include<stdio.h>
#include<vector>
#include<list>

struct stMonster
{
	int index = 0;// 몬스터 타입
};

bool isfindmonindex(const stMonster& mon)
{
	return mon.index == 3;//만약 mon.index가 3이면 true반환, 아니면 false반환
}

class CShop
{
public:
	int isOpen = false;
};

int main()
{
	//stl
	//고정되지 않은 유동적인 배열
	//배열 생성하면서 처음부터 공간을 점유하지않고 필요할때 마다 늘리고 줄일수 있는 배열


	/*
	* 벡터(vector) - 스택(stack) 구조
	* 연속적인 메모리를 확보한다
	* 자신의 요소를 내부의 동적 배열(dynamic array)로 복사한다
	* 임의 접근 연산자를 제공([]) 하기 때문에 어떠한 값에 접근하든 상수시간(고정된 시간)이 소요된다.
	* 동적 배열이기 때문에 배열의 중간에 새로 추가 하거나 삭제하면 많은 값이 이동해야하기 때문에 오랜 시간이 걸린다.
	* 중간에 추가하는 것이 오버헤드가 크기 때문에 보통 뒷부분에 추가한다 (push_back)
	* 동적배열 이기 때문에 크기의 확장과 축소가 자유롭지만 재할당 비용은 크다.
	* 
	* 장점
	* -임의 접근을 상수시간(고정된 시간)에 가능 하므로, 읽기 속도가 매우 빠르다.
	* 
	* 단점
	* -중간에 값을 추가/제거 하는 비용이 크다.
	* -재할당 비용이 크다
	*/
	//std::vector<int> : int형에 vector 배열
	//vecint : vector 배열에 이름
	//{0, 1, 2, 3, 4} : vecint에 초기값 넣기
	//std::vector<int> vecint{ 0, 1, 2, 3, 4 };
	//int vectorSize = vecint.size();// 벡터의 요소 갯수 반환
	//int vec0 = vecint[0];//[] 명확한 위치를 넣어서 접근 가능
	//int* pData = vecint.data();//벡터 배열에 실제 데이터 메모리 공간에 주소(포인터)를 반환
	//int vCap = vecint.capacity();//데이터 크기 측면에서에 저장 공간 크기를 반환
	//printf("vecint capacity=%d\n", vCap);


	//for (int i = 0; i < vecint.size(); i++)
	//{
	//	printf("vecint[%d]=%d\n", i, vecint[i]);
	//}

	//for (int value : vecint)// 값복사 방식으로 값을 변경하면 원본데이터는 수정안됨
	//{
	//	value = 0;
	//	printf("vecint=%d\n", value);
	//}
	//for (int& value : vecint)
	//{
	//	
	//	printf("a vecint=%d\n", value);
	//}

	//for (int& value : vecint)// 레퍼런스 참조 방식으로 값을 변경하면 원본 데이터 변경
	//{
	//	value = 1;
	//	printf("ref vecint=%d\n", value);
	//}
	//for (int& value : vecint)
	//{

	//	printf("a vecint=%d\n", value);
	//}

	//for (const int& value : vecint)//레퍼런스 참조시 const변수로 참조하면 값 변경 불가능
	//{
	//	//value = 0;
	//	printf("vecint=%d\n", value);
	//}

	//std::vector<int> vecint{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//std::vector<int>::iterator veciter = vecint.begin();
	////veciter++;// 오른쪽 다음 배열에 위치를 가르키겠다.
	//veciter +=2;// 오른쪽으로 2번 이동한 배열에 위치를 가르키겠다.
	//veciter--;// 왼쪽으로 다음 배열에 위치를 가르키겠다.....
	////vecint.end();// 배열 끝났다는 의미(마지막 배열을 가르키는 것이 아니다.)
	//printf("veciter=%d", *veciter);

	//vecint.push_back(100);// 배열에 마지막에 100 요소를 추가하겠다.
	//
	//for (std::vector<int>::iterator iter = vecint.begin(); iter != vecint.end();++iter)
	//{
	//	printf("iter=%d\n", *iter);
	//}

	//vecint.pop_back();// 마지막 배열에 요소를 제거하겠다.

	//veciter = vecint.begin();
	//while (veciter != vecint.end())
	//{
	//	printf("while iter=%d\n", *veciter);
	//	veciter++;
	//}
	//	printf("\nvecint size=%d\n\n", int(vecint.size()));
	//
	//veciter = vecint.begin();
	//while (veciter != vecint.end())
	//{
	//	if (*veciter == 5)
	//	{
	//		veciter = vecint.erase(veciter);//vecint가 가리키고 있는 배열의 요소를 제거하겠다.
	//	}
	//	else
	//	{
	//		veciter++;
	//	}
	//}

	//veciter = vecint.begin();
	//while (veciter != vecint.end())
	//{
	//	printf("while iter=%d\n", *veciter);
	//	veciter++;
	//}


	/* 
	* 리스트(list)
	* 리스트는 요소들을 양방향 연결리스트의 형태로 관리한다.(doubly linked list)
	* 리시트객체는 앵커라 불리는 포이터 2개를 제공하는데 이는 head와 tail을 가리킨다.
	* 새로운 요소를 삽입하기 위해서는 이 포인터(앵커)를 조작한다
	* 리스트는 임의 접근([])을 제공하지 않는다.(n번째 요소에 접근하기 위해서 노드를 거쳐야 하기 때문)
	* 특정위치에 추가/제거가 자유롭다. (특정위치를 찾는 시간은 제외)
	* 재할당 연산이 없다. 연속적인 메모리가 아니기 때문에(메모리가 제공되는 한) 무한히 추가할 수 있다.
	* 
	* 장점
	* - 임의의 위치에 요소를 추가하는 것이 자유롭다(특정 위치를 찾는 시간은 제외) 따라서 쓰기에 매우 강하다
	* 
	* 단점
	* - 임의접근이 불가능하기 때문에 선형 탐색하여 위치를 찾는다.
	* - 원소간의 연결을 위해 추가적인 메모리를 소모한다.(다음 노드의 포인터 메모리)
	*/

    // std::list<int> : 리스트로 생성할 변수형
    // listint : 생성할 리스트 이름
    // {0,1,2,3,4}; : 리스트에 기본값
    //   std::list<int> listint{ 0,1,2,3,4 };

	//for (int value : listint)
	//{
	//	printf("list value=%d\n", value);
	//}
	////for (int& value : listint)// 원본데이터 수정
	//{
	//	//printf("list value=%d\n", value);
	//}
	////for (const int& value : listint)
	//{
	//	//printf("list value=%d\n", value);
	//}


	//std::list<int>::iterator listiter = listint.begin();
	//printf("listiter=%d\n", *listiter);
	//for (std::list<int>::iterator iter = listint.begin(); iter != listint.end(); ++iter)
	//{
	//	printf("for list value=%d\n", *iter);
	//}

	//listiter = listint.begin();
	//while (listiter != listint.end())
	//{
	//	printf("while list value=%d\n", *listiter);
	//	listiter++;
	//}

    std::list<int> listint{ 0,1,2,3,4 };
	//listint.push_back(100);//리스트에 뒤쪽에 값을 추가 연결한다
	//listint.push_front(200);//리스트에 앞쪽에 값을 추가 연결한다.
	//
	//for (int value : listint)
	//{
	//	printf("list value=%d\n", value);
	//}
	//
	//listint.pop_back(); //리스트에 뒤쪽에 값을 제거한다.
	//listint.pop_front(); //리스트에 앞족에 값을 제거한다.
	//
	//for (int value : listint)
	//{
	//	printf("list value=%d\n", value);
	//}

	//리스트에서 특정원소 찾기
	std::list<int>::iterator it = std::find(listint.begin(), listint.end(), 3);
	if (it != listint.end())
	{
		//찾았다.
		printf("find list value = %d\n", *it);
		//listint.erase(it); //리스트 안에 특정 요소 제거하기
		int value = 2023;
		//listint.insert(it, value);// 특정요소 앞쪽에 새로운 요소 끼워 넣기
		//listint.emplace(it, 2024);// 특정요소 앞쪽에 새로운 요소 끼워 넣기

	}
	else
	{
		//못찾았다.
		printf("find list fali!!\n");
	}

	for (const int& value : listint)
	{
		printf("list value=%d\n", value);
	}

	std::list<stMonster> arrMon;

	for (int i = 1; i < 6; ++i)
	{
		stMonster temp;
		temp.index = i + 10;
		arrMon.push_back(temp);
	}
	
	std::list<stMonster>::iterator moniter;
	moniter = std::find_if(arrMon.begin(), arrMon.end(), [](const stMonster& mon)
		{
			return mon.index == 13;
		});

	if (moniter != arrMon.end())
	{
		printf("moniter index = %d\n", moniter->index);
	}
	else
	{
		printf("moniter find fail!!!\n");
	}

}