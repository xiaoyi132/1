#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//void hannoi(int n, char a, char b, char c)//Ŀ��Ϊ�˽�A�����е�Բ��ͨ��B�ƶ���C
//{
//	if (n == 1)
//		printf("%c->%c\n",a,c);
//	else
//	{
//		hannoi(n - 1, a, c, b);//��һ��:���Ȱ�B����C,��Ŀ���ǽ�n-1��Բ��ͨ��C�ƶ���B,���Ž�n-1��Բ�̿�������,�γ�2��Բ������
//		printf("%c->%c\n",a,c);//����n��Բ��(��ÿ�εݹ�����ײ�Բ��)�ƶ���C
//		hannoi(n - 1, b, a, c);//��ʱ������A��Bλ�ý���,��ʼ��һ�ν���
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	hannoi(n, 'A', 'B', 'C');
//	return 0;
//}