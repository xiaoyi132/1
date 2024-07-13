#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
//�ַ�������ģ��ʵ��
//strlen �ַ����ȼ���
unsigned int my_strlen(const char* arr)
{
	assert(arr);
	unsigned int num = 0;
	while (*arr++)
	{
		num++;
	};
	return num;
}

//strcpy �ַ�������
char* my_strcpy(char* str, const char* ret)
{
	assert(str && ret);
	char* arr = str;
	while (*arr++ = *ret++);
	return str;
}

//strcmp �ַ����Ƚ�
int my_strcmp(const char* str, const char* ret)
{
	assert(str && ret);
	return *str - *ret;
}

//strcat �ַ���׷��
char* my_strcat(char* str, const char* ret)
{
	assert(str && ret);
	char* p = str;
	while (*p)
	{
		p++;
	}
	while ((*p++ = *ret++) != '\0');	//��ֵ����ֵ���Ѹ�ֵ��ֵ(ǿ�����Ѿ���ֵ��ſ�ʼ����while�����ж�)
	return str;
}

int main()
{
	char arr1[] = "cde";
	char arr2[20] = { 0 };
	char arr3[] = "bcd";
	printf("%u\n",my_strlen(arr1));
	printf("%s\n", my_strcpy(arr2, arr1));
	printf("%d\n", my_strcmp(arr3, arr1));
	printf("%s\n", my_strcat(arr2, arr3));
	return 0;
}