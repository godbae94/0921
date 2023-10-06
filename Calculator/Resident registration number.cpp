#include <stdio.h>
#include <iostream>



void ScanfinputNum(int& a, int& b)
{
    printf("\n주민번호 앞에 자리를 입력해주세요:");
    scanf_s("%d", &a);
    printf("\n주민번호 뒷에 첫째 자리를 입력해주세요:");
    scanf_s("%d", &b);
}

enum InputType
{
    end = 0,
    start
};




int main()
{
    bool bRun = true;

    while (bRun)
    {
        InputType nInput = InputType::end;
        int a = 0, int b = 0;
        
        printf("진행하기 1번, 종료하기 2번");
        scanf_s("%d", &nInput);

        switch (nInput)
        {
        case InputType::end:
            bRun = false;
            break;
                   
        case InputType::start:
            ScanfinputNum(a, b);
            printf("\n19 결과는 %f 입니다.\n", );
            break;

        default:
            break;
        }












    }




}