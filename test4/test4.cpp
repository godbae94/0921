#include<stdio.h>
#include<iostream>

enum InputType
{
    Quit = 0,
    Start,
    
};

float standardWeight(float height)
{
    return (height - 100) * 0.9;
}

float GetBMI(float weight, float standardWeight)
{
    return (weight - standardWeight) * 100 / standardWeight;
}



int main()
{

    bool bRun = true;

    while (bRun)
    {
        InputType nInput = InputType::Quit;
        int a = 0, b = 0;
        printf("BMI�� ����Ͻðڽ��ϱ�? 0)NO 1)YES : ");
        scanf_s("%d", &nInput);

        
        switch (nInput)
        {
        case InputType::Quit:
            bRun = false;
            break;

        case InputType::Start:
            ScanfinputNum(a, b);
            printf("\nSum ����� %d �Դϴ�.\n", cSum(a, b));
            break;

        default:
            break;
        }
    }

}