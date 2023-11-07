#define _CRT_SECURE_NO_WARNINGS
//判断完全数
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//    int n = 0;
//    int x1 = 0, x2 = 0;
//    int sum = 1;
//    scanf("%d", &n);
//    for (int i = 2; i <= sqrt(n); i++)
//    {
//        if (n % i == 0)
//        {
//            x1 = i;
//            x2 = n / i;
//        }
//        sum = sum + x1 + x2;
//        x1 = 0;
//        x2 = 0;
//    }
//    if (sum == n)
//        printf("Yes");
//    else
//        printf("No");
//    return 0;
//}

//查找班级里不及格的人员
#include<stdio.h>
int main()
{
    int flag = 1;
    int arr[10] = { 0 };
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        switch (arr[i] / 10)
        {
        case 10:
        case 9:
        case 8:
        case 7:
        case 6:
            break;
        default:
        {
            printf("%d ", arr[i]);
            flag = 0;
        }
        }
    }
    if (flag == 1)
        printf("ALL Pass!");
    return 0;
}