#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int arr[5][5] = { 0 };
	int sum = 0;
	for (int i = 4; i >= 0; i--)
	{
		for (int j = 0; j < 5; j++)
		{
			scanf("%d", &arr[i][j]);
			if (i == j)
				sum += arr[i][j];
		}
	}
	printf("%d", sum);
	return 0;
}
