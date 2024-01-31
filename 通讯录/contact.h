#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<assert.h>

//类型声明

// 成员信息
typedef struct PeoInfor {
	char name[13];
	char sex[6];
	char year[4];
	char tele[12];
	char address[20];
}PeoInfor;

//通讯录:
typedef struct contact {
	int count;
	PeoInfor* date;
	int capacity;
}contact;

//联系人搜索(姓名查找)
int Check_contact(contact*);

//打印菜单
void menu();

//初始化通讯录
void Int_contact(contact*);

//通讯录扩容
void EX_contact(contact*);

//加载通讯录
void Load_contact(contact*);

//添加联系人
void ADD_contact(contact*);

//显示通讯目录
void SHOW_contact(contact*);

//删除联系人
void Delete_contact(contact*);

//查找联系人
void Search_contact(contact*);

//修改联系人信息
void Modify_contact(contact*);

//排序通讯录
void SORT_contact(contact*);

//通讯录保存
void SAVE_contact(contact*);