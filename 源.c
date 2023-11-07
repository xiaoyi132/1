#define _CRT_SECURE_NO_WARNINGS

//#include<stdio.h>
//	int main()
//	{
//		int v, t;
//		for (int i = 0; i < 2; i++)
//		{
//			scanf("%d %d", &v, &t);
//			printf("%d\n", v * 2 * t);
//		}
//		return 0;
//	}
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
//	int s = step(m, n);
//	printf("%d", (m * n) / s);
//	return 0;
//}
//int Max(int x, int arr[])
//{
//    for (int i = 1; i < n; i++)
//    {
//        x = arr[i];
//        if (x > arr[i])
//            continue;
//        else
//            x = arr[i];
//    }
//    return x;
//}

//#include<stdio.h>
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int arr[100] = { 0 };
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    int x1 = arr[0];
//    for (int i = 1; i < n; i++)
//    {
//        if (x1 > arr[i])
//            continue;
//        else
//            x1 = arr[i];
//    }
//    int x2 = arr[0];
//    for (int i = 1; i < n; i++)
//    {
//        if (x2 < arr[i])
//            continue;
//        else
//            x2 = arr[i];
//    }
//    int max = x1, min = x2;
//    int sum = 0;
//    for (int i = 0; i < n; i++)
//    {
//        sum = sum + arr[i];
//    }
//    double average = (double)(sum - max - min) / (n - 2);
//    printf("%.1lf", average);
//    return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a[10] = {0};
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//	for (int i = 9; i >= 0; i--)
//	{
//		printf("%d", a[i]);
//	}
//	return 0;
//}


//int getMax(int x, int y)
//{
//    if (x > y)
//        return x;
//    else
//        return y;
//}
//int main()
//{
//    int a[10], max, i;
//    for (i = 0; i < 10; i++)
//        scanf("%d", &a[i]);
//    max = a[0];
//    for (i = 1; i < 10; i++)
//        max = getMax(max, a[i]);
//    printf("The max integer is %d\n", max);
//    return 0;
//}

//unsigned int num(unsigned int n)
//{
//	if (n < 10)
//		return n;
//	else
//		return num(n % 10);		
//}
//
//#include<stdio.h>
//int main()
//{
//	unsigned int x = 0;
//	scanf("%u", &x);
//	for (;x > 0;x = x/10)
//	{
//		unsigned int y = num(x);
//		printf("%u ", y);
//	}
//
//	return 0;
//}
