#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
unsigned int drink(int money)
{
	unsigned int num = 0;
	int num_empty = 0;
	for (; money > 0; money--)
	{
		++num;
		++num_empty;
		if (num_empty == 2)
		{
			num_empty = 0;
			++num;
		}
	}
	return num;
}
int main()
{
	int money = 0;
	scanf("%d", &money);
	printf("%u", drink(money));
	return 0;
}