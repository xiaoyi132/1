#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int num = 0;
	int i = 0, j = 0;
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 13; j++)
		{
			if (i + j >= 6 && i + j <= 6 + 2 * i)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
		for (i = 0; i < 6; i++)
		{
			printf(" ");
			for (j = 0; j < 11; j++)
			{
				if (i + j <= 10 && i + j >= 2 * i)
					printf("*");
				else
					printf(" ");
			}
			printf("\n");
		}
	return 0;
}