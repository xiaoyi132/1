#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a[10] = { 0 };
	int b[10] = { 0 };
	for (int i = 0; i < 10; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < 10; i++)
		scanf("%d", &b[i]);
	printf("����ǰ\n");
	printf("����a:");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n����b:");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", b[i]);
	}
	for (int i = 0; i < 10; i++)
	{
		a[i] ^= b[i];
		b[i] ^= a[i];
		a[i] ^= b[i];
	}
	printf("\n������\n");
	printf("����a:");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n����b:");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", b[i]);
	}
	return 0;
}