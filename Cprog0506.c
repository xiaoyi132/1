#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void fun(char*,int);
int main()
{
	int key = 0;
	scanf_s("%d", &key);
	getchar();
	char arr[100] = { 0 };
	scanf("%[^\n]",arr);
	fun(arr,key);
	printf("%s", arr);
	return 0;
}
void fun(char* arr,int key)
{
	int i = 0;
	while (arr[i] != '\0')
	{
		if ((arr[i] >= 'A' && arr[i] <= 'Z') || (arr[i] >= 'a' && arr[i] <= 'z'))
		{
			if (arr[i] + key > 'Z' && arr[i] + key > 'z')
				arr[i] = arr[i] + key - 26;
			else if(arr[i] + key > 'Z' && arr[i] < 'Z')
				arr[i] = arr[i] + key - 26;
			else
			arr[i] = arr[i] + key;
		}
		i++;
	}
}