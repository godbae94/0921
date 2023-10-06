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
        printf("BMI를 계산하시겠습니까? 0)NO 1)YES : ");
        scanf_s("%d", &nInput);

        
        switch (nInput)
        {
        case InputType::Quit:
            bRun = false;
            break;

        case InputType::Start:
            ScanfinputNum(a, b);
            printf("\nSum 결과는 %d 입니다.\n", cSum(a, b));
            break;

        default:
            break;
        }
    }

}