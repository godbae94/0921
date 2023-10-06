#include<stdio.h>
#include<vector>
#include<list>

struct stMonster
{
	int index = 0;// ���� Ÿ��
};

bool isfindmonindex(const stMonster& mon)
{
	return mon.index == 3;//���� mon.index�� 3�̸� true��ȯ, �ƴϸ� false��ȯ
}

class CShop
{
public:
	int isOpen = false;
};

int main()
{
	//stl
	//�������� ���� �������� �迭
	//�迭 �����ϸ鼭 ó������ ������ ���������ʰ� �ʿ��Ҷ� ���� �ø��� ���ϼ� �ִ� �迭


	/*
	* ����(vector) - ����(stack) ����
	* �������� �޸𸮸� Ȯ���Ѵ�
	* �ڽ��� ��Ҹ� ������ ���� �迭(dynamic array)�� �����Ѵ�
	* ���� ���� �����ڸ� ����([]) �ϱ� ������ ��� ���� �����ϵ� ����ð�(������ �ð�)�� �ҿ�ȴ�.
	* ���� �迭�̱� ������ �迭�� �߰��� ���� �߰� �ϰų� �����ϸ� ���� ���� �̵��ؾ��ϱ� ������ ���� �ð��� �ɸ���.
	* �߰��� �߰��ϴ� ���� ������尡 ũ�� ������ ���� �޺κп� �߰��Ѵ� (push_back)
	* �����迭 �̱� ������ ũ���� Ȯ��� ��Ұ� ���������� ���Ҵ� ����� ũ��.
	* 
	* ����
	* -���� ������ ����ð�(������ �ð�)�� ���� �ϹǷ�, �б� �ӵ��� �ſ� ������.
	* 
	* ����
	* -�߰��� ���� �߰�/���� �ϴ� ����� ũ��.
	* -���Ҵ� ����� ũ��
	*/
	//std::vector<int> : int���� vector �迭
	//vecint : vector �迭�� �̸�
	//{0, 1, 2, 3, 4} : vecint�� �ʱⰪ �ֱ�
	//std::vector<int> vecint{ 0, 1, 2, 3, 4 };
	//int vectorSize = vecint.size();// ������ ��� ���� ��ȯ
	//int vec0 = vecint[0];//[] ��Ȯ�� ��ġ�� �־ ���� ����
	//int* pData = vecint.data();//���� �迭�� ���� ������ �޸� ������ �ּ�(������)�� ��ȯ
	//int vCap = vecint.capacity();//������ ũ�� ���鿡���� ���� ���� ũ�⸦ ��ȯ
	//printf("vecint capacity=%d\n", vCap);


	//for (int i = 0; i < vecint.size(); i++)
	//{
	//	printf("vecint[%d]=%d\n", i, vecint[i]);
	//}

	//for (int value : vecint)// ������ ������� ���� �����ϸ� ���������ʹ� �����ȵ�
	//{
	//	value = 0;
	//	printf("vecint=%d\n", value);
	//}
	//for (int& value : vecint)
	//{
	//	
	//	printf("a vecint=%d\n", value);
	//}

	//for (int& value : vecint)// ���۷��� ���� ������� ���� �����ϸ� ���� ������ ����
	//{
	//	value = 1;
	//	printf("ref vecint=%d\n", value);
	//}
	//for (int& value : vecint)
	//{

	//	printf("a vecint=%d\n", value);
	//}

	//for (const int& value : vecint)//���۷��� ������ const������ �����ϸ� �� ���� �Ұ���
	//{
	//	//value = 0;
	//	printf("vecint=%d\n", value);
	//}

	//std::vector<int> vecint{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//std::vector<int>::iterator veciter = vecint.begin();
	////veciter++;// ������ ���� �迭�� ��ġ�� ����Ű�ڴ�.
	//veciter +=2;// ���������� 2�� �̵��� �迭�� ��ġ�� ����Ű�ڴ�.
	//veciter--;// �������� ���� �迭�� ��ġ�� ����Ű�ڴ�.....
	////vecint.end();// �迭 �����ٴ� �ǹ�(������ �迭�� ����Ű�� ���� �ƴϴ�.)
	//printf("veciter=%d", *veciter);

	//vecint.push_back(100);// �迭�� �������� 100 ��Ҹ� �߰��ϰڴ�.
	//
	//for (std::vector<int>::iterator iter = vecint.begin(); iter != vecint.end();++iter)
	//{
	//	printf("iter=%d\n", *iter);
	//}

	//vecint.pop_back();// ������ �迭�� ��Ҹ� �����ϰڴ�.

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
	//		veciter = vecint.erase(veciter);//vecint�� ����Ű�� �ִ� �迭�� ��Ҹ� �����ϰڴ�.
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
	* ����Ʈ(list)
	* ����Ʈ�� ��ҵ��� ����� ���Ḯ��Ʈ�� ���·� �����Ѵ�.(doubly linked list)
	* ����Ʈ��ü�� ��Ŀ�� �Ҹ��� ������ 2���� �����ϴµ� �̴� head�� tail�� ����Ų��.
	* ���ο� ��Ҹ� �����ϱ� ���ؼ��� �� ������(��Ŀ)�� �����Ѵ�
	* ����Ʈ�� ���� ����([])�� �������� �ʴ´�.(n��° ��ҿ� �����ϱ� ���ؼ� ��带 ���ľ� �ϱ� ����)
	* Ư����ġ�� �߰�/���Ű� �����Ӵ�. (Ư����ġ�� ã�� �ð��� ����)
	* ���Ҵ� ������ ����. �������� �޸𸮰� �ƴϱ� ������(�޸𸮰� �����Ǵ� ��) ������ �߰��� �� �ִ�.
	* 
	* ����
	* - ������ ��ġ�� ��Ҹ� �߰��ϴ� ���� �����Ӵ�(Ư�� ��ġ�� ã�� �ð��� ����) ���� ���⿡ �ſ� ���ϴ�
	* 
	* ����
	* - ���������� �Ұ����ϱ� ������ ���� Ž���Ͽ� ��ġ�� ã�´�.
	* - ���Ұ��� ������ ���� �߰����� �޸𸮸� �Ҹ��Ѵ�.(���� ����� ������ �޸�)
	*/

    // std::list<int> : ����Ʈ�� ������ ������
    // listint : ������ ����Ʈ �̸�
    // {0,1,2,3,4}; : ����Ʈ�� �⺻��
    //   std::list<int> listint{ 0,1,2,3,4 };

	//for (int value : listint)
	//{
	//	printf("list value=%d\n", value);
	//}
	////for (int& value : listint)// ���������� ����
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
	//listint.push_back(100);//����Ʈ�� ���ʿ� ���� �߰� �����Ѵ�
	//listint.push_front(200);//����Ʈ�� ���ʿ� ���� �߰� �����Ѵ�.
	//
	//for (int value : listint)
	//{
	//	printf("list value=%d\n", value);
	//}
	//
	//listint.pop_back(); //����Ʈ�� ���ʿ� ���� �����Ѵ�.
	//listint.pop_front(); //����Ʈ�� ������ ���� �����Ѵ�.
	//
	//for (int value : listint)
	//{
	//	printf("list value=%d\n", value);
	//}

	//����Ʈ���� Ư������ ã��
	std::list<int>::iterator it = std::find(listint.begin(), listint.end(), 3);
	if (it != listint.end())
	{
		//ã�Ҵ�.
		printf("find list value = %d\n", *it);
		//listint.erase(it); //����Ʈ �ȿ� Ư�� ��� �����ϱ�
		int value = 2023;
		//listint.insert(it, value);// Ư����� ���ʿ� ���ο� ��� ���� �ֱ�
		//listint.emplace(it, 2024);// Ư����� ���ʿ� ���ο� ��� ���� �ֱ�

	}
	else
	{
		//��ã�Ҵ�.
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