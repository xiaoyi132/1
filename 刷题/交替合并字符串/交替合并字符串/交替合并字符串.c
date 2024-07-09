#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <malloc.h>
#include<stdlib.h>
////内存使用率6.5
//char* mergeAlternately(char* word1, char* word2)
//{
//	//计算两数组长度,判断后续数组字符添加顺序
//	int length_word1 = (int)strlen(word1);
//	int length_word2 = (int)strlen(word2);
//	//使用calloc为内存空间初始化为0
//	char* p = (char*)calloc((length_word1 + length_word2 + 1),sizeof(char*));	//申请一块长度 等于 两个字符串长度之和的内存空间 (+1为初始化为0作为数组结束防止内存越界)
//	//*(p + length_word1 + length_word2) = '\0';//若使用malloc不可省略
//	//初始化两个0变量,使word1与word2字符数组中内容依次穿插
//	int len_1 = 0;
//	int len_2 = 0;
//	//若字符串长度word1 > word2,则word2进入循环中if判断防止字符数组word2越界
//	if (length_word1 > length_word2)
//	{
//		while (len_1 != length_word1)
//		{
//			*(p + len_1 + len_2) = word1[len_1];
//			len_1++;
//			if (len_2 < length_word2)
//			{
//				*(p + len_1 + len_2) = word2[len_2];
//				len_2++;
//			}
//		}
//	}
//	//同上
//	else if (length_word1 < length_word2)
//	{
//		while (len_2 != length_word2)
//		{
//			if (len_1 < length_word1)
//			{
//				*(p + len_1 + len_2) = word1[len_1];
//				len_1++;
//			}
//			*(p + len_1 + len_2) = word2[len_2];
//			len_2++;
//		}
//	}
//	//两字符串长度相同,无需判断
//	else
//	{
//		while (len_1 != length_word1 && len_2 != length_word2)
//		{
//
//			*(p + len_1 + len_2) = word1[len_1];
//			len_1++;
//			*(p + len_1 + len_2) = word2[len_2];
//			len_2++;
//		}
//	}
//	return p;
//}
//内存使用率0.041(别人的代码)
char* mergeAlternately(char* word1, char* word2) 
{
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    char* a = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
    int i, j, k;
    for (i = 0, j = 0, k = 0; i < len1 || j < len2; i++, j++) 
    {
        if (i < len1)
            a[k++] = word1[i];
        if (j < len2)
            a[k++] = word2[j];
    }
    a[k] = '\0';
    return a;
}
int main()
{
	char word1[100] = { 0 };
	char word2[100] = { 0 };
	scanf("%s%s", word1, word2);
	printf("%s", mergeAlternately(word1, word2));	//返回所得内存空间所存放字符串
	return 0;
}