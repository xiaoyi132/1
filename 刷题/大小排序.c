#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a = 0, b = 0, c = 0;
	scanf("%d %d %d", &a, &b, &c);
	for (int i = 1; i <= 3; i++)
	{
		for (int n = 1; n <= 3; n++)
		{
			int s = a;
			if (a < b)
			{
				s = a;
				a = b;
				b = s;
			}
			if (b < c)
			{
				s = b;
				b = c;
				c = s;
			}
		}
	}
	printf("%d %d %d", a, b, c);
	return 0;
}