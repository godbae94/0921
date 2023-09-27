#include <stdio.h>

void BuyItem(int* Money, int price)
{
    // int* Money는 메모리 복제가 일어나지 않는다.
    // 메모리에 효율적인 관리, 데이터 참조가 편리하다.
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
        pPS->iPhoneCnt--;// 포인트로 참조하는 구조체에 변수는 "->" 키워드로 참조한다.
        break;
    case ePhoneType :: Galaxys23:
        pPS->Galaxys23--;// 포인트로 참조하는 구조체에 변수는 "->" 키워드로 참조한다.
        break;
    case ePhoneType::GalaxyFold:
        pPS->GalaxyFold--;// 포인트로 참조하는 구조체에 변수는 "->" 키워드로 참조한다.
        break;
    case ePhoneType::GalaxyZ:
        pPS->GalaxyZ--;// 포인트로 참조하는 구조체에 변수는 "->" 키워드로 참조한다.
        break;
    default:
        break;
    }
   
}

//number 받어서 화면에 출력한다
void printnumber(const int* number)
{
    //number = nullptr;//주소값 수정가능
    //*number = 2;// 수정불가능
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
    //포인터를 사용하는이유
    // 메모리에 효율적인 관리, 데이터 참조가 편리하다.
    //int* pA : 포인터 변수의 선언(pA에 들어가있는 주소에 int형의 크기 만큼 참조하겠다.)
    //nullptr : 포인터 변수의 초기화 값(주소값이 비어있음)
    //이전에는 NULL을 사용했는데 NULL = 0을 의미 그래서 0이랑 의마가 동일해서 문제 발생
    //주소값이 비어있음이라는 명확한 의미를 가진 nullptr 사용
    //포인터에 크기(x32에는 4byte, x64에서는 8byte)
    int* pA = nullptr;
    pA = &a;//a 주소값을 pA에 넣는다.
    // * : 레퍼런트 참조한다.(주소가 가르키고 있는 값을 참조한다.)
    b = *pA; //b에 pA가 가르키고 있는 주소에 값을 넣는다.
    *pA = 10; //pA가 가르키고 있는 주소에 값을 10으로 변경한다.


    //-------------------------------------------------

    //int num1 = 0;
    //int num2 = 0;
    //int* pNum = nullptr;
    //pNum = &num1;         //pNum에 num1에 주소값을 넣는다. (pNum은 num1을 가르키고 있는상태)
    //printf("pNum=%d\n", *pNum); // num1의값인 0이 나온다
    //*pNum = 20;           //pNum이 가르키고 있는 num1에 20을 넣는다.
    //printf("pNum=%d\n", *pNum);
    //pNum = &num2;         //pNum에 num2에 주소 값을 넣는다.(pNum은 num2을 가르키고 있는 상태)
    //printf("pNum=%d\n", *pNum);
    //*pNum = 30;           //pNum이 가르키고 있는 num2에 30을 넣는다.
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
    //배열과 포인터

    //int arrint[10] = { 0, 10, 20, 30, 40, 50, 60, 70, 80 ,90 };
    //int* pint = nullptr; // pint에 들어가있는 주소에 int형의 크기만큼 참조하겠다.
    //pint = arrint;
    //printf("pint=%d\n\n", *pint);
    //pint += 1;//다음 배열 포인터에 주소를 가리킨다.
    //printf("pint=%d\n\n", *pint);
    //pint += 3;
    //printf("pint=%d\n\n", *pint);

    //short arrS[10] = { 0, 10, 20, 30, 40, 50, 60, 70, 80 ,90 };
    //pint = (int*)arrS; //(int*)를 사용해서 int*로 강제로 형변환(cast)한다.
    //pint += 1; //pint가 int*이므로 int(4바이트)만큼 다음 주소 값을 참조한다.
    //short* pS = (short*)pint;//int(4바이트)만큼 이동한 주소값은 short(2바이트)2번 이동한 값
    //printf("pS=%d\n\n", *pS);


    //int i, j, temp, index; //정의
    //
    //    int arr[10] = { 10, 2, 78, 53, 6, 33, 27, 99, 7, 31 }; // 나열할  숫자
    //
    //           
    //for (int i = 0; i < 10; i++) //0번쨰부터 9번째까지 진행
    //{
    //    
    //    for (int j =i + 1; j < 10; j++) //1번쨰부터 9번쨰 까지 진행
    //    {
    //        if (arr[i] > arr[j]) //왼쪽값이 더 크면
    //        {
    //            temp = arr[i];  // 왼쪽값을 저장
    //            arr[i] = arr[j]; // 오른쪽 값을 왼쪽 값으로
    //            arr[j] = temp;   // 보관된 왼쪽값을 오른쪽 값으로
    //        } // 자리 교환
    //    }

    //}
    //for (i = 0; i < 10; i++) printf("%d\n", arr[i]);
    //return 0;
        
    // const 상수화, 값을 수정못하게 하려고 사용한다.
    //실수를 줄일수 있어서 디버깅 횟수를 줄일수 있다.(디버깅 : 버그를 찾거나 수정하는 모든 행위)
    const int cint = 100;//상수

    int value = 0;
    int value2 = 0;
    int* pvalue = &value;
     //const int* pvlaue = &value;      //포인터가 가르키는 내용 수정불가, 포인터값 수정 가능, 참조가능
     //int const* pvlaue = &value;      //포인터가 가르키는 내용 수정불가, 포인터값 수정 가능, 참조가능
     //int* const  pvlaue = &value;     //포인터가 가르키는 내용 수정가능, 포인터값 수정 불가, 참조가능
     //const int* const pvlaue = &value;//포인터가 가르키는 내용 수정불가, 포인터값 수정 불가, 참조가능
     //int const* const pvlaue = &value;//포인터가 가르키는 내용 수정불가, 포인터값 수정 불가, 참조가능

    *pvalue = 2;
    pvalue = &value2;
    printf("pvalue=%d\n", *pvalue);
                                                                                         

    printnumber(&value);

    printnumber2(value);



 }