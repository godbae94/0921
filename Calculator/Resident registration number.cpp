#include <stdio.h>
#include <iostream>



void ScanfinputNum(int& a, int& b)
{
    printf("\n�ֹι�ȣ �տ� �ڸ��� �Է����ּ���:");
    scanf_s("%d", &a);
    printf("\n�ֹι�ȣ �޿� ù° �ڸ��� �Է����ּ���:");
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
        
        printf("�����ϱ� 1��, �����ϱ� 2��");
        scanf_s("%d", &nInput);

        switch (nInput)
        {
        case InputType::end:
            bRun = false;
            break;
                   
        case InputType::start:
            ScanfinputNum(a, b);
            printf("\n19 ����� %f �Դϴ�.\n", );
            break;

        default:
            break;
        }












    }




}