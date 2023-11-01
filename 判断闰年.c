#include<stdio.h>
int main()
{
    int year = 0;
    scanf_s("%d", &year);
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (!(year % 400 == 0))
                printf("Not leap year");
            else
                printf("Leap year");
        }
        else
            printf("leap year");
    }
    else
        printf("Not leap year");
    return 0;
}
