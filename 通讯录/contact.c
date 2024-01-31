#include"contact.h"
//初始化通讯录
void Int_contact(contact* pc)
{
	assert(pc);
	pc->count = 0;
	pc->date = (PeoInfor*)calloc(3, sizeof(PeoInfor));
	if (pc->date == NULL)
	{
		perror("Int_contact");
		return;
	}
	pc->capacity = 3;
}
//通讯录扩容
void EX_contact(contact* pc)
{
	assert(pc);
	pc->capacity += 3;
	PeoInfor* ptr = (PeoInfor*)realloc(pc->date, sizeof(PeoInfor) * (pc->capacity));
	if (ptr == NULL)
	{
		perror("EX_contact");
		return;
	}
	printf("扩容成功!\n");
}

//联系人搜索(姓名查找)
int Check_contact(contact* pc)
{
	assert(pc);
	int num = 0;
	char ret[20] = { 0 };
	printf("请输入联系人名字->");
	scanf("%s", ret);
	for (num = 0; num < pc->count; num++)
	{
		if (strcmp(pc->date[num].name, ret) == 0)
			return num;
	}
	return -1;
}

//加载通讯录
void Load_contact(contact* pc)
{
	assert(pc);
	FILE* ftr = fopen("contact.txt", "rb");
	if (ftr == NULL)
	{
		perror("Load_contact");
		return;
	}
	PeoInfor ret = { 0 };
	while (1 == fread(&ret, sizeof(PeoInfor), 1, ftr))
	{
		if (pc->count == pc->capacity)
			EX_contact(pc);
		pc->date[pc->count] = ret;
		++(pc->count);
	}
	fclose(ftr);
}

//添加联系人
void ADD_contact(contact* pc)
{
	assert(pc);
	if (pc->count == pc->capacity)
		EX_contact(pc);
	printf("名字:");
	scanf("%s", pc->date[pc->count].name);
	printf("性别:");
	scanf("%s", pc->date[pc->count].sex);
	printf("年龄:");
	scanf("%s", pc->date[pc->count].year);
	printf("电话:");
	scanf("%s", pc->date[pc->count].tele);
	printf("地址:");
	scanf("%s", pc->date[pc->count].address);
	(pc->count)++;
}

//删除联系人
void Delete_contact(contact* pc)
{
	assert(pc);
	PeoInfor zero = { 0 };
	int ret = Check_contact(pc);
	if (ret == -1)
		printf("\a您要删除联系人不存在,操作无效\n");
	else
	{
		printf("删除成功\n");
		while (ret < pc->count - 1)
		{
			pc->date[ret] = pc->date[ret + 1];
			ret++;
		}
		pc->count--;
	}
}

//显示通讯目录
void SHOW_contact(contact* pc)
{
	assert(pc);
	printf("%-13s %-6s %-4s %-12s %-20s\n", "名字", "性别", "年龄", "电话", "地址");
	int num = 0;
	while (num != pc->count)
	{
		printf("%-13s %-6s %-4s %-12s %-20s\n", pc->date[num].name,
											  pc->date[num].sex,
											  pc->date[num].year,
											  pc->date[num].tele,
											  pc->date[num].address);
		num++;
	}
}

//查找联系人
void Search_contact(contact* pc)
{
	assert(pc);
	int ret = Check_contact(pc);
	if (ret == -1)
		printf("您所查找联系人不存在,操作无效\n");
	else
	{
		printf("找到该联系人,信息如下\n");
		printf("%-13s %-6s %-4s %-12s %-20s\n", "名字", "性别", "年龄", "电话", "地址");
		printf("%-13s %-6s %-4s %-12s %-20s\n", pc->date[ret].name,
			pc->date[ret].sex,
			pc->date[ret].year,
			pc->date[ret].tele,
			pc->date[ret].address);
	}
}

//修改联系人信息
void Modify_contact(contact* pc)
{
	assert(pc);
	int ret = 0;
	ret = Check_contact(pc);
	if (ret == -1)
		printf("您所查找联系人不存在,操作无效\n");
	else
	{
		printf("请重新修改联系人信息\n");
		printf("名字:");
		scanf("%s", pc->date[ret].name);
		printf("性别:");
		scanf("%s", pc->date[ret].sex);
		printf("年龄:");
		scanf("%s", pc->date[ret].year);
		printf("电话:");
		scanf("%s", pc->date[ret].tele);
		printf("地址:");
		scanf("%s", pc->date[ret].address);
	}
}

//排序辅助函数
int q_sort_contact(const void* str1,const void* str2)
{
	return strcmp(((PeoInfor*)str1)->name,((PeoInfor*)str2)->name);
}
//排序通讯录
void SORT_contact(contact* pc)
{
	assert(pc);
	int ret = 0;
	qsort(pc->date, pc->count, sizeof(PeoInfor), q_sort_contact);
	printf("排序成功\n");
}

//通讯录保存
void SAVE_contact(contact* pc)
{
	assert(pc);
	FILE* ftr = fopen("contact.txt", "wb");
	if (ftr == NULL)
	{
		perror("SAVE_contact");
		return;
	}
	for (int i = 0; i < pc->count; i++) 
	{
		fwrite(pc->date + i, sizeof(PeoInfor), 1, ftr);
	}
	fclose(ftr);
}