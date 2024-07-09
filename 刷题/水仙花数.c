#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
double fun(double,int);
int main()
{
	//for (int i = 0; i <= 100000; i++)
	//{
	//	int ret = i;
	//	int sum = 0;
	//	while (ret)
	//	{
	//		sum += (int)pow(ret % 10,3);
	//		ret /= 10;
	//	}
	//	if (sum == i)
	//		printf("%d ", i);
	//}
	int a = 0;
	int b = 0;
	scanf("%d%d", &a,&b);
	int num = 0;
	while (a||b)
	{
		if ((a & 1) != (b & 1))
			num++;
		b >>= 1;
		a >>= 1;
	}
	printf("%d", num);
	return 0;
}
double fun(double n, int k)
{
	if (k == 0)
		return 1.0;
	else
		return n * fun(n, k - 1);
}