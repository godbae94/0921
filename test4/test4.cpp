#include<stdio.h>
#include<iostream>


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
        printf("BMI를 계산하시겠습니까? 0)NO 1)YES : ");
        int input = 0;
        scanf_s("%d", &input);

        
        switch (input)
        {
        case 0:
            bRun = false;
            break;

        case 1:
        {
            int weight = 0, height = 0, BMI = 0;
            printf("몸무게를 입력해주세요 : ");
            scanf_s("%d", &weight);
            printf("키를 입력해주세요 : ");
            scanf_s("%d", &height);
            BMI = GetBMI(weight, standardWeight(height));

            if (10 <= BMI)
            {
                printf("정상\n");
            }
            else if (10 < BMI && BMI <= 20)
            {
                printf("과체중\n");
            }
            else if (20 < BMI)
            {
                printf("과체중\n");
            }
        }
            break;

        default:
            break;
        }
    }

}