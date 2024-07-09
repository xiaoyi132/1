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
	printf("交换前a的值为%d,b的值为%d\n", a, b);
	exchange(&a, &b);
	printf("交换后a的值为%d,b的值为%d\n",a ,b );
	return 0;
}