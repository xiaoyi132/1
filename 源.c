#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int main()
//{
//    float score = 0.0f;
//    scanf("%f", &score);
//    int c = score / 10;
//    switch (c)
//    {
//    case 10:
//    case 9:
//        printf("Excellent");
//        break;
//    case 8:
//        printf("Good");
//        break;
//    case 7:
//        printf("Medium");
//        break;
//    case 6:
//        printf("Pass");
//        break;
//    default:
//        printf("No Pass");
//    }
//        return 0;
//}
    

//#include<stdio.h>
//int main()
//{
//    int year = 0, month = 0;
//    scanf("%d %d", &year, &month);
//
//
//    switch (month)
//    {
//    case 1:
//        printf("Days of the month is 31");
//        break;
//    case 2:
//        if (year % 4 == 0)
//        {
//            if ((year % 100) == 0 && (year % 400 == 0))
//                printf("Days of the month is 29");
//            else if ((year % 400 != 0) && (year % 100 == 0))
//                printf("Days of the month is 28");
//            else
//                printf("Days of the month is 29");
//        }
//        else
//            printf("Days of the month is 28");
//        break;
//    case 3:
//        printf("Days of the month is 31");
//        break;
//    case 4:
//        printf("Days of the month is 30");
//        break;
//    case 5:
//        printf("Days of the month is 31");
//        break;
//    case 6:
//        printf("Days of the month is 30");
//        break;
//    case 7:
//        printf("Days of the month is 31");
//        break;
//    case 8:
//        printf("Days of the month is 31");
//        break;
//    case 9:
//        printf("Days of the month is 30");
//        break;
//    case 10:
//        printf("Days of the month is 31");
//        break;
//    case 11:
//        printf("Days of the month is 30");
//        break;
//    case 12:
//        printf("Days of the month is 31");
//        break;
//    }
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//	double e, t;
//	int i, j, n;
//	scanf("%d", &n);
//	e = 1;
//	t = 1;
//	for (i = 1; i <= n; i++)
//	{
//		for (t = 1, j = 1; j <= i; j++)
//		{
//			t = t * j;
//		}
//		e = e + 1.0 / t;
//	}
//	printf("%.8f", e);
//	return 0;
//}


//
//#include<stdio.h>
//int main()
//{
//    int m, n;
//    int num = 0;
//    int i = 1;
//    scanf("%d %d", &m, &n);
//    if (m == 2)
//        num += 1;
//    while (m <= n)
//    {
//        for (i = 2; i <= n - 1; i++)
//        {
//            if (m % i == 0)
//            {
//                m++;
//                break;
//            }
//            else
//            {
//                num++;
//                m++;
//                break;
//            }
//        }
//    }
//    printf("%d", num);
//    return 0;
//}


//#include<stdio.h>
//int main()
//{
//    int n = 0;
//    int m = 0;
//    int num = 0;
//    scanf("%d %d", &m, &n);
//    int flag = 1;
//    for(;m<=n;m++)
//    { 
//    for (int i = 2; i <= m - 1; i++)
//    {
//        if (m % i == 0)
//        {
//            flag = 0;
//            break;
//        }
//        else
//            flag = 1;
//    }
//    if (flag == 1)
//        num++;
//    else
//        continue;
//    }
//    printf("%d", num);
//    return 0;
//}

#include <stdio.h>
void step(int x)
{
    int flag = 1;
    for (int i = 2; i <= x - 1; i++)
    {
        if (x % i == 0)
        {
            flag = 0;
            break;
        }
        else
        {
            flag = 1;
            continue;
        }
    }
    if (flag == 0)
        printf("不是素数");
    else
    {
        printf("是素数");
    }
}


int main()
{
    int n = 0;
    scanf("%d", &n);
    step(n);
    return 0;
}