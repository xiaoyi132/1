#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char arr[20] = { "0" };
	system("shutdown /s /t 60");
	printf("电脑将在60s内关机,请输入我是猪取消操作\n");
	do
	{
	scanf("%s", arr);
	if (strcmp(arr, "我是猪")==0)
	{
		system("shutdown /a");
		printf("取消成功");
		break;
	}
	else
		printf("请重新输入\n");
	} while (1);
	return 0;
}