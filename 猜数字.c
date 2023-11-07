#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//设置菜单
void menu()
	{
	printf("**********猜数字***********\n");
	printf("***************************\n");
	printf("********1.开始游戏*********\n");
	printf("********0.结束游戏*********\n");
	printf("***************************\n");
	printf("***************************\n");
	printf("***************************\n");
	}


//生成随机数字函数
void game()
{
	
	int ret = (rand() % 100);//生成数字范围为1 ~ 100;
	int num = 0;
	do
	{
		scanf("%d", &num);
		if (num > ret)
		{
			printf("输大了\n");
		}
		else if (num == ret)
		{
			printf("输入正确\n");
		}
		else
		{
			printf("输小了\n");
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
		printf("请选择-->>");
		scanf("%d", &n);
		if (n = 1)
		{
			printf("请输入第一个数字:");
			game();
		}
		else if (n = 0)
		{
			printf("结束游戏");
			break;
		}
		else
			printf("选择错误,请重新选择!!!");
	} while (1);
	return 0;
}
