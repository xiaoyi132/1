#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int main()
//{
//    int array[20] = { 0 };
//    int* ptr = array;
//    for (int i = 0; i < 20; i++)
//    {
//        (*ptr)++;
//        ptr++;
//    }
//    printf("%s", array);
//}



//#include<stdio.h>
//int main()
//{
//    int n = 0, sum = 0;
//    int x = 1;
//    scanf("%d", &n);
//    for (int i = 1; i <= n; i++)
//    {   
//            x = x * i;
//            sum = sum + x;   
//    }
//    printf("%d", sum);
//    return 0;
//}


//#include<stdio.h>
//int main()
//{
//    int n = 0;
//    unsigned long long x = 1;
//    scanf("%d", &n);
//    for (int i = 1; n >= i; n--)
//    {
//        x = x * n;
//    }
//    printf("The factorial is %lld", x);
//    return 0;
//}

//
//#include<stdio.h>
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int flag = 1;
//    for (int i = 2; i < n; i++)
//    {
//        if (n % i == 0)
//        {
//            flag = 0;
//        }
//        else
//            flag = 1;
//    }
//    if (flag == 1)
//        printf("%d is a prime number", n);
//    else
//        printf("%d is not a prime number", n);
//return 0;
//}\



//#include<stdio.h>
//int main()
//{
//    int i = 1;
//    int n = 0;
//    int sum = 0;
//    scanf("%d", &n);
//    while (i <= n)
//    {
//        sum = sum + i;
//        i++;
//    }
//    printf("sum=%d", sum);
//    return 0;
//}

//
//#include<stdio.h>
//int step(int x, int y)
//{
//	if (y == 0)
//		return x;
//	else
//		return step(y, x % y);
//}
//int main()
//{
//	int m = 0, n = 0;
//	scanf("%d %d", &m, &n);
//	int divisor = step(m, n);
//	printf("The greatest common divisor is %d", divisor);
//	return 0;
//}



//#include<stdio.h>
//int main()
//{
//    int n = 0;    
//    scanf("%d", &n);
//    int x = 0;
//    while (1)
//    {
//        n = n / 10;
//        if (n == 0)
//        {
//            x++;
//            break;
//        }
//        else
//            x++;
//    }
//    printf("The number of digits is %d", x);
//    return 0;
//}

//#include<stdio.h>
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int flag = 1;
//    for (int i = 2; i <= n - 1; i++)
//    {
//        if (n % i == 0)
//        {
//            flag = 0;
//            break;
//        }
//        else
//        {
//            flag = 1;
//        }
//    }
//    if (flag == 1)
//        printf("%d is a prime number", n);
//    else
//        printf("%d is not a prime number", n);
//        return 0;
//}


//#include<stdio.h>
//int main()
//{
//    int m, n;
//    scanf("%d %d", &m, &n);
//    int i = 0;
//    for (int x = m > n ? m : n, y = m > n ? n : m; x >= y; y++)
//    {
//        if (y % 3 != 0)
//            continue;
//        else
//            i++;
//    }
//    printf("The total number is %d", i);
//    return 0;
//}\

//****
#include<stdio.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    int arr[30] = { 0 };
    for (int i = 0; i < n; i++)
         scanf("%d", &arr[i]);//**
    int max = 0;
    max = arr[0];
    for (int i = 0; i + 1 < n; i++)
    {
        if (arr[i] == 0)
            break;
        max = max > arr[i + 1] ? max : arr[i + 1];
    }
    printf("The max score is %d", max);
    return 0;
}