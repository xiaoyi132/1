#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <malloc.h>
#include<stdlib.h>
////�ڴ�ʹ����6.5
//char* mergeAlternately(char* word1, char* word2)
//{
//	//���������鳤��,�жϺ��������ַ����˳��
//	int length_word1 = (int)strlen(word1);
//	int length_word2 = (int)strlen(word2);
//	//ʹ��callocΪ�ڴ�ռ��ʼ��Ϊ0
//	char* p = (char*)calloc((length_word1 + length_word2 + 1),sizeof(char*));	//����һ�鳤�� ���� �����ַ�������֮�͵��ڴ�ռ� (+1Ϊ��ʼ��Ϊ0��Ϊ���������ֹ�ڴ�Խ��)
//	//*(p + length_word1 + length_word2) = '\0';//��ʹ��malloc����ʡ��
//	//��ʼ������0����,ʹword1��word2�ַ��������������δ���
//	int len_1 = 0;
//	int len_2 = 0;
//	//���ַ�������word1 > word2,��word2����ѭ����if�жϷ�ֹ�ַ�����word2Խ��
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
//	//ͬ��
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
//	//���ַ���������ͬ,�����ж�
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
//�ڴ�ʹ����0.041(���˵Ĵ���)
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
	printf("%s", mergeAlternately(word1, word2));	//���������ڴ�ռ�������ַ���
	return 0;
}