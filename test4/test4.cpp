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
        printf("BMI�� ����Ͻðڽ��ϱ�? 0)NO 1)YES : ");
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
            printf("�����Ը� �Է����ּ��� : ");
            scanf_s("%d", &weight);
            printf("Ű�� �Է����ּ��� : ");
            scanf_s("%d", &height);
            BMI = GetBMI(weight, standardWeight(height));

            if (10 <= BMI)
            {
                printf("����\n");
            }
            else if (10 < BMI && BMI <= 20)
            {
                printf("��ü��\n");
            }
            else if (20 < BMI)
            {
                printf("��ü��\n");
            }
        }
            break;

        default:
            break;
        }
    }

}