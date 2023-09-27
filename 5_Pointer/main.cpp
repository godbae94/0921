#include <stdio.h>

void BuyItem(int* Money, int price)
{
    // int* Money�� �޸� ������ �Ͼ�� �ʴ´�.
    // �޸𸮿� ȿ������ ����, ������ ������ ���ϴ�.
    *Money -= price;
}

enum ePhoneType
{
    iPhone = 0,
    Galaxys23,
    GalaxyFold,
    GalaxyZ
};

struct stPhoneShop
{
    int iPhoneCnt;
    int Galaxys23;
    int GalaxyFold;
    int GalaxyZ;

    void printPhoneCnt()
        {
        printf("iPhone=%d, Galaxys23=%d, GalaxyFold=%d, GalaxyZ=%d\n\n\n\n", iPhoneCnt, Galaxys23, GalaxyFold, GalaxyZ);
        }
    

};

void BuyPhone(ePhoneType phoneType, stPhoneShop* pPS)
{
    switch (phoneType)
    {
    case ePhoneType :: iPhone:
        pPS->iPhoneCnt--;// ����Ʈ�� �����ϴ� ����ü�� ������ "->" Ű����� �����Ѵ�.
        break;
    case ePhoneType :: Galaxys23:
        pPS->Galaxys23--;// ����Ʈ�� �����ϴ� ����ü�� ������ "->" Ű����� �����Ѵ�.
        break;
    case ePhoneType::GalaxyFold:
        pPS->GalaxyFold--;// ����Ʈ�� �����ϴ� ����ü�� ������ "->" Ű����� �����Ѵ�.
        break;
    case ePhoneType::GalaxyZ:
        pPS->GalaxyZ--;// ����Ʈ�� �����ϴ� ����ü�� ������ "->" Ű����� �����Ѵ�.
        break;
    default:
        break;
    }
   
}

//number �޾ ȭ�鿡 ����Ѵ�
void printnumber(const int* number)
{
    //number = nullptr;//�ּҰ� ��������
    //*number = 2;// �����Ұ���
    printf("printf number=%d", *number);
}

void printnumber2(const int& number)
{
    printf("printf number=%d", number);
}

void printPhoneShop(const stPhoneShop* ps)// * = ->
{
        printf("printf iPhoneCnt=%d", ps->iPhoneCnt);
}

void printPhoneShop(const stPhoneShop& ps) // & = .
{
    printf("printf iPhoneCnt=%d", ps.iPhoneCnt);
}






int main()
{
    int a = 0;//4byte
    int b = 0;
    //�����͸� ����ϴ�����
    // �޸𸮿� ȿ������ ����, ������ ������ ���ϴ�.
    //int* pA : ������ ������ ����(pA�� ���ִ� �ּҿ� int���� ũ�� ��ŭ �����ϰڴ�.)
    //nullptr : ������ ������ �ʱ�ȭ ��(�ּҰ��� �������)
    //�������� NULL�� ����ߴµ� NULL = 0�� �ǹ� �׷��� 0�̶� �Ǹ��� �����ؼ� ���� �߻�
    //�ּҰ��� ��������̶�� ��Ȯ�� �ǹ̸� ���� nullptr ���
    //�����Ϳ� ũ��(x32���� 4byte, x64������ 8byte)
    int* pA = nullptr;
    pA = &a;//a �ּҰ��� pA�� �ִ´�.
    // * : ���۷�Ʈ �����Ѵ�.(�ּҰ� ����Ű�� �ִ� ���� �����Ѵ�.)
    b = *pA; //b�� pA�� ����Ű�� �ִ� �ּҿ� ���� �ִ´�.
    *pA = 10; //pA�� ����Ű�� �ִ� �ּҿ� ���� 10���� �����Ѵ�.


    //-------------------------------------------------

    //int num1 = 0;
    //int num2 = 0;
    //int* pNum = nullptr;
    //pNum = &num1;         //pNum�� num1�� �ּҰ��� �ִ´�. (pNum�� num1�� ����Ű�� �ִ»���)
    //printf("pNum=%d\n", *pNum); // num1�ǰ��� 0�� ���´�
    //*pNum = 20;           //pNum�� ����Ű�� �ִ� num1�� 20�� �ִ´�.
    //printf("pNum=%d\n", *pNum);
    //pNum = &num2;         //pNum�� num2�� �ּ� ���� �ִ´�.(pNum�� num2�� ����Ű�� �ִ� ����)
    //printf("pNum=%d\n", *pNum);
    //*pNum = 30;           //pNum�� ����Ű�� �ִ� num2�� 30�� �ִ´�.
    //printf("pNum=%d\n", *pNum);

    //printf("num1=%d num2=%d\n\n\n", num1, num2);

    //-------------------------------------------------------

    int Money = 10000 ;

    BuyItem(&Money, 3000);
    //printf("MyMoney=%d\n\n\n\n", Money);

    stPhoneShop stPS;
    stPS.iPhoneCnt = 100;
    stPS.Galaxys23 = 100;
    stPS.GalaxyFold = 100;
    stPS.GalaxyZ = 100;

    BuyPhone(ePhoneType::Galaxys23, &stPS);
    stPS.printPhoneCnt();

    //---------------------------------------------------------------------------------------------------------//
    //�迭�� ������

    //int arrint[10] = { 0, 10, 20, 30, 40, 50, 60, 70, 80 ,90 };
    //int* pint = nullptr; // pint�� ���ִ� �ּҿ� int���� ũ�⸸ŭ �����ϰڴ�.
    //pint = arrint;
    //printf("pint=%d\n\n", *pint);
    //pint += 1;//���� �迭 �����Ϳ� �ּҸ� ����Ų��.
    //printf("pint=%d\n\n", *pint);
    //pint += 3;
    //printf("pint=%d\n\n", *pint);

    //short arrS[10] = { 0, 10, 20, 30, 40, 50, 60, 70, 80 ,90 };
    //pint = (int*)arrS; //(int*)�� ����ؼ� int*�� ������ ����ȯ(cast)�Ѵ�.
    //pint += 1; //pint�� int*�̹Ƿ� int(4����Ʈ)��ŭ ���� �ּ� ���� �����Ѵ�.
    //short* pS = (short*)pint;//int(4����Ʈ)��ŭ �̵��� �ּҰ��� short(2����Ʈ)2�� �̵��� ��
    //printf("pS=%d\n\n", *pS);


    //int i, j, temp, index; //����
    //
    //    int arr[10] = { 10, 2, 78, 53, 6, 33, 27, 99, 7, 31 }; // ������  ����
    //
    //           
    //for (int i = 0; i < 10; i++) //0�������� 9��°���� ����
    //{
    //    
    //    for (int j =i + 1; j < 10; j++) //1�������� 9���� ���� ����
    //    {
    //        if (arr[i] > arr[j]) //���ʰ��� �� ũ��
    //        {
    //            temp = arr[i];  // ���ʰ��� ����
    //            arr[i] = arr[j]; // ������ ���� ���� ������
    //            arr[j] = temp;   // ������ ���ʰ��� ������ ������
    //        } // �ڸ� ��ȯ
    //    }

    //}
    //for (i = 0; i < 10; i++) printf("%d\n", arr[i]);
    //return 0;
        
    // const ���ȭ, ���� �������ϰ� �Ϸ��� ����Ѵ�.
    //�Ǽ��� ���ϼ� �־ ����� Ƚ���� ���ϼ� �ִ�.(����� : ���׸� ã�ų� �����ϴ� ��� ����)
    const int cint = 100;//���

    int value = 0;
    int value2 = 0;
    int* pvalue = &value;
     //const int* pvlaue = &value;      //�����Ͱ� ����Ű�� ���� �����Ұ�, �����Ͱ� ���� ����, ��������
     //int const* pvlaue = &value;      //�����Ͱ� ����Ű�� ���� �����Ұ�, �����Ͱ� ���� ����, ��������
     //int* const  pvlaue = &value;     //�����Ͱ� ����Ű�� ���� ��������, �����Ͱ� ���� �Ұ�, ��������
     //const int* const pvlaue = &value;//�����Ͱ� ����Ű�� ���� �����Ұ�, �����Ͱ� ���� �Ұ�, ��������
     //int const* const pvlaue = &value;//�����Ͱ� ����Ű�� ���� �����Ұ�, �����Ͱ� ���� �Ұ�, ��������

    *pvalue = 2;
    pvalue = &value2;
    printf("pvalue=%d\n", *pvalue);
                                                                                         

    printnumber(&value);

    printnumber2(value);



 }