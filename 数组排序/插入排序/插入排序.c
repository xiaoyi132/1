#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
int main()
{
	int arr[10] = { 3,1,5,4,8,6,7,10,2 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 1; i < sz; i++)
	{
		int ret = arr[i]; //��¼ѡ������
		int j = i - 1;
		while (j >= 0 && ret <= arr[j])	//ѡ��������������Դ˽��бȽ�,�������ִ���ѡ������,�򽫺�������ǰ�ƶ�һλ
		{
			arr[j + 1] = arr[j];
			j--;	//��ʱj + 1λ����λΪ�������ظ���λ(�ɿ�����λ:����ѡ�����ֲ����λ��),�� j ������ -1 ,���ʱ j λ��ӦС��ѡ������
		}
		arr[j + 1] = ret;	//��ѡ�����ֲ����λ
		//�۲��������
		for (int i = 0; i < sz; i++)
		{
			printf("%d ", arr[i]);
		}
		Sleep(1000);
		system("cls");
	}	
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}