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
		int ret = arr[i]; //记录选中数字
		int j = i - 1;
		while (j >= 0 && ret <= arr[j])	//选中数字与后方数字以此进行比较,若后方数字大于选中数字,则将后方数字往前移动一位
		{
			arr[j + 1] = arr[j];
			j--;	//此时j + 1位数字位为排序后的重复数位(可看作空位:即将选中数字插入的位置),若 j 不等于 -1 ,则此时 j 位数应小于选中数字
		}
		arr[j + 1] = ret;	//将选中数字插入空位
		//观察排序过程
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