#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void exchange(int* x, int* y)
{
	int z = *x;
	*x = *y;
	*y = z;
}
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	printf("����ǰa��ֵΪ%d,b��ֵΪ%d\n", a, b);
	exchange(&a, &b);
	printf("������a��ֵΪ%d,b��ֵΪ%d\n",a ,b );
	return 0;
}