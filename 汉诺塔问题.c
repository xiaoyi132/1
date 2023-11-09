#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//void hannoi(int n, char a, char b, char c)//目的为了将A上所有的圆盘通过B移动至C
//{
//	if (n == 1)
//		printf("%c->%c\n",a,c);
//	else
//	{
//		hannoi(n - 1, a, c, b);//第一步:可先把B看作C,即目的是将n-1个圆盘通过C移动至B,或着将n-1个圆盘看作整体,形成2个圆盘问题
//		printf("%c->%c\n",a,c);//将第n个圆盘(即每次递归后的最底层圆盘)移动至C
//		hannoi(n - 1, b, a, c);//此时看看作A与B位置交换,开始下一次交换
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	hannoi(n, 'A', 'B', 'C');
//	return 0;
//}