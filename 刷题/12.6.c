#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdio.h>
//��ӡXͼ��
    int main() 
    {
        int a;
        while (scanf("%d", &a) != EOF) { // ע�� while ������ case
            // 64 λ������� printf("%lld") to 
            for (int i = 1; i <= a; i++)
            {
                for (int j = 1; j <= a; j++)
                {
                    if (i == j)
                        printf("*");
                    else if (i + j == a + 1)
                        printf("*");
                    else
                        printf(" ");
                }
                printf("\n");
            }
        }
        return 0;
    }
