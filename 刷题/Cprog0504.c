#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char x = 0;
	scanf("%c", &x);
	char arr[100] = {0};
	scanf("%s", arr);
	int i = 0;
	int num = 0;
	while (arr[i] != '\0')
	{
		if (arr[i] == x)
		{
			num = i;
		}
		i++;
	}
	if (num == 0)
		printf("Not Found");
	else
		printf("%d", num);
	return 0;
}
