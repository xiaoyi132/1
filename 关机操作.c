#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char arr[20] = { "0" };
	system("shutdown /s /t 60");
	printf("���Խ���60s�ڹػ�,������������ȡ������\n");
	do
	{
	scanf("%s", arr);
	if (strcmp(arr, "������")==0)
	{
		system("shutdown /a");
		printf("ȡ���ɹ�");
		break;
	}
	else
		printf("����������\n");
	} while (1);
	return 0;
}