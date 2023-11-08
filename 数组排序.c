#include<stdio.h>
void fun(int arr[])
{
	for (int i = 0; i <= 9; i++)
	{
		for (int n = 0; n < 9; n++)
		{
			if (arr[n] > arr[n + 1])
			{
				int x = arr[n];
				arr[n] = arr[n + 1];
				arr[n + 1] = x;
			}
		}
	}
	for (int n = 0; n <= 9; n++)
		printf("%d", arr[n]);
}