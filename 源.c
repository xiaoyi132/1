#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//寻找数组的数位
//int _binary_num(int arr[],int k,int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)
//	{
//		int mid = left + (right - left) / 2;
//		if (arr[mid] == k)
//			return mid;
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//			right = mid - 1;
//	}
//	return -1;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int k = 0;
//	scanf("%d", &k);
//	int ret = _binary_num(arr, k, sz);
//	if (ret == -1)
//		printf("找不到");
//	else
//		printf("找到了,是数组的第%d位数", ret);
//	return 0;
//}




//斐波那契数列 1
//#include<stdio.h>
//int main()
//{
//    int n1 = 1;
//    int n2 = 1;
//    int n = 0;
//    int s = 0;
//    scanf("%d", &n);
//    for (int i = 1; i <= n - 2; i++)
//    {
//        s = n1 + n2;
//        n1 = n2;
//        n2 = s;
//    }
//    printf("%d", s);
//    return 0;
//}

//求数列2/1	,  3/2	,5/3....的前n项和
//#include<stdio.h>
//int main()
//{
//	int arr[3] = { 1,1,2 };
//	int s = 1;
//	int n = 0;
//	double sum = 2.0;
//	scanf("%d", &n);
//	for (int i = 1; i <= n - 1; i++)
//	{ 
//		s = arr[2];
//		arr[2] = arr[1] + arr[2];
//		arr[0] = arr[1];
//		arr[1] = s;
//		int down = arr[1];
//		int up = arr[2];
//		double x = (double)up / down;
//		sum = sum + x;
//	}
//	printf("%lf", sum);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//    int sum = 0;
//    int n = 0;
//    scanf("%d", &n);
//    for (int i = 1; i <= n; i++)
//    {
//        if ((i % 3 == 0) && (i % 7 != 0))
//            sum = sum + i;
//    }
//    printf("%d", sum);
//    return 0;
//}

//#include<stdio.h>
//#include<math.h>
//Fact(int n)
//{
//    int s = 1;
//    for (int x = 1; x <= n; x++)
//    {
//        s = 1;
//        for (int i = 1; i <= x; i++)
//        {
//            s = s * i;
//        }
//    }
//    return s;
//}
//int main()
//{
//    int n = 0, s = 0;
//    scanf("%d", &n);
//    for (int i = 1; i <= n; i++)
//    {
//        s = s + Fact(i) * pow(-1,i+1);
//    }
//    printf("%d", s);
//    return 0;
//}


#include<stdio.h>
int main()
{
    int num = 0;
    double sum = 0;
    int arr[5] = { 0 };
    int sz = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < sz; i++)
        scanf("%d", &arr[i]);
    for (int i = 0; i < sz; i++)
        sum = sum + arr[i];
    double Average = sum / sz;
    for (int i = 0; i < sz; i++)
    {
        if (arr[i] > Average)//超过平均分
            num++;
    }
    printf("%.1lf\n%d", Average, num);
    return 0;
}