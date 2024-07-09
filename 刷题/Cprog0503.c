#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	int arr[m][n] = { 0 };
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	int flag = 0;
	for (int i = 1; i < m; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i][j] != 0)
				flag = 1;
		}
	}
	if (flag == 0)
		printf("Yes");
	else
		printf("No");
	return 0;
}
