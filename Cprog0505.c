#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#define NUM 3
int main()
{
	int arr[NUM][NUM] = { 0 };
	int n = 0;
	scanf_s("%d", &n);
	int i, j;
	for (i = 0; i < NUM; i++)
	{
		for (j = 0; j < NUM; j++)
			scanf("%d", &arr[i][j]);
	}
	for (i = 0; i < NUM; i++)
	{
		int m = n;
		for (j = 0;m > 0;m--)
		{
			int ret = arr[i][j];
			arr[i][j] = arr[i][j + 2];
			arr[i][j + 2] = arr[i][j + 1];
			arr[i][j + 1] = ret;
		}
	}
	for (i = 0; i < NUM; i++)
	{
		for (j = 0; j < NUM; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
		
	
	return 0;
}
