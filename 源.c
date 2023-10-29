#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int main()
//{
//putchar(73);
//putchar(32);
//putchar(99);
//putchar(97);
//putchar(110);
//putchar(32);
//putchar(100);
//putchar(111);
//putchar(32);
//putchar(105);
//putchar(116);
//putchar(33);
//	return 0;
//}

 
//#include<stdio.h>
//int main()
//{
//	int arr[] = { 73,32,99,97,110,32,100,111,32,105,116,33 };
//	int sz = sizeof(arr) / sizeof(arr[0]);	//计算数组的元素个数
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%c", arr[i]);
//	}
//	char arr1[] = "abbskcaj";
//	printf("%d", strlen(arr1));
//	return 0;
//}


//出生生日的输入输出
//#include<stdio.h>
//int main()
//{
//	int year, month, day;
//	scanf("%4d%2d%2d", &year, &month, &day);	//scanf("xx%")中xx限制输入位数
//	printf("%d\n%02d\n%02d\n", year, month, day);
//	return 0;
//}

//printf函数的返回值
//#include<stdio.h>
//int main()
//{
//	//int a = printf("Hello world!");
//	//printf("\n%d\n", a);
//	printf("printf(\"Hello World!\\n\");\n");
//	printf("cout<<\"Hello World!\"<<endi;");
//	return 0;
//}
// 
//比较4个数的最大值
//#include<stdio.h>
//int main()
//{
//	int arr[4] = { 0 };
//	for (int i = 0; i < 4; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int i = 0;
//	int a = 0;
//	while (i < 3)
//	{
//		a = arr[i] < arr[i + 1] ? arr[i + 1] : arr[i];
//		i++;
//	}
//	printf("%d", a);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int max = 0;
//	scanf("%d", &max);
//	int i = 0;
//	while (i < 3)
//	{
//		int n = 0;
//		scanf("%d",&n);
//		if (n > max)
//		{
//			max = n;
//		}
//		i++;
//	}
//	printf("%d", max);
//	return 0;
//}


#include<stdio.h>
int main()
{
	int kilo, h;
	scanf("%d %d", &kilo, &h);
	double l = h * 0.01;
	double BMI = (kilo / (l * l));
	printf("%.2lf", BMI);
	return 0;
}

