#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//���ò˵�
void menu()
	{
	printf("**********������***********\n");
	printf("***************************\n");
	printf("********1.��ʼ��Ϸ*********\n");
	printf("********0.������Ϸ*********\n");
	printf("***************************\n");
	printf("***************************\n");
	printf("***************************\n");
	}


//����������ֺ���
game()
{
	
	int ret = (rand() % 100);//�������ַ�ΧΪ1 ~ 100;
	int num = 0;
	do
	{
		scanf("%d", &num);
		if (num > ret)
		{
			printf("�����\n");
		}
		else if (num == ret)
		{
			printf("������ȷ\n");
		}
		else
		{
			printf("��С��\n");
		}
	} while (1);
}

int main()
{
	srand((double)time(NULL));
	do
	{
		int n = 0;
		menu();
		printf("��ѡ��-->>");
		scanf("%d", &n);
		if (n = 1)
		{
			printf("�������һ������:");
			game();
		}
		else if (n = 0)
		{
			printf("������Ϸ");
			break;
		}
		else
			printf("ѡ�����,������ѡ��!!!");
	} while (1);
	return 0;
}