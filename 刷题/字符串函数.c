#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
//字符串函数模拟实现
//strlen 字符长度计算
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

//strcpy 字符串复制
char* my_strcpy(char* str, const char* ret)
{
	assert(str && ret);
	char* arr = str;
	while (*arr++ = *ret++);
	return str;
}

//strcmp 字符串比较
int my_strcmp(const char* str, const char* ret)
{
	assert(str && ret);
	return *str - *ret;
}

//strcat 字符串追加
char* my_strcat(char* str, const char* ret)
{
	assert(str && ret);
	char* p = str;
	while (*p)
	{
		p++;
	}
	while ((*p++ = *ret++) != '\0');	//赋值返回值是已赋值的值(强调是已经赋值后才开始进行while条件判定)
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