#include"contact.h"
//��ʼ��ͨѶ¼
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
//ͨѶ¼����
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
	printf("���ݳɹ�!\n");
}

//��ϵ������(��������)
int Check_contact(contact* pc)
{
	assert(pc);
	int num = 0;
	char ret[20] = { 0 };
	printf("��������ϵ������->");
	scanf("%s", ret);
	for (num = 0; num < pc->count; num++)
	{
		if (strcmp(pc->date[num].name, ret) == 0)
			return num;
	}
	return -1;
}

//����ͨѶ¼
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

//�����ϵ��
void ADD_contact(contact* pc)
{
	assert(pc);
	if (pc->count == pc->capacity)
		EX_contact(pc);
	printf("����:");
	scanf("%s", pc->date[pc->count].name);
	printf("�Ա�:");
	scanf("%s", pc->date[pc->count].sex);
	printf("����:");
	scanf("%s", pc->date[pc->count].year);
	printf("�绰:");
	scanf("%s", pc->date[pc->count].tele);
	printf("��ַ:");
	scanf("%s", pc->date[pc->count].address);
	(pc->count)++;
}

//ɾ����ϵ��
void Delete_contact(contact* pc)
{
	assert(pc);
	PeoInfor zero = { 0 };
	int ret = Check_contact(pc);
	if (ret == -1)
		printf("\a��Ҫɾ����ϵ�˲�����,������Ч\n");
	else
	{
		printf("ɾ���ɹ�\n");
		while (ret < pc->count - 1)
		{
			pc->date[ret] = pc->date[ret + 1];
			ret++;
		}
		pc->count--;
	}
}

//��ʾͨѶĿ¼
void SHOW_contact(contact* pc)
{
	assert(pc);
	printf("%-13s %-6s %-4s %-12s %-20s\n", "����", "�Ա�", "����", "�绰", "��ַ");
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

//������ϵ��
void Search_contact(contact* pc)
{
	assert(pc);
	int ret = Check_contact(pc);
	if (ret == -1)
		printf("����������ϵ�˲�����,������Ч\n");
	else
	{
		printf("�ҵ�����ϵ��,��Ϣ����\n");
		printf("%-13s %-6s %-4s %-12s %-20s\n", "����", "�Ա�", "����", "�绰", "��ַ");
		printf("%-13s %-6s %-4s %-12s %-20s\n", pc->date[ret].name,
			pc->date[ret].sex,
			pc->date[ret].year,
			pc->date[ret].tele,
			pc->date[ret].address);
	}
}

//�޸���ϵ����Ϣ
void Modify_contact(contact* pc)
{
	assert(pc);
	int ret = 0;
	ret = Check_contact(pc);
	if (ret == -1)
		printf("����������ϵ�˲�����,������Ч\n");
	else
	{
		printf("�������޸���ϵ����Ϣ\n");
		printf("����:");
		scanf("%s", pc->date[ret].name);
		printf("�Ա�:");
		scanf("%s", pc->date[ret].sex);
		printf("����:");
		scanf("%s", pc->date[ret].year);
		printf("�绰:");
		scanf("%s", pc->date[ret].tele);
		printf("��ַ:");
		scanf("%s", pc->date[ret].address);
	}
}

//����������
int q_sort_contact(const void* str1,const void* str2)
{
	return strcmp(((PeoInfor*)str1)->name,((PeoInfor*)str2)->name);
}
//����ͨѶ¼
void SORT_contact(contact* pc)
{
	assert(pc);
	int ret = 0;
	qsort(pc->date, pc->count, sizeof(PeoInfor), q_sort_contact);
	printf("����ɹ�\n");
}

//ͨѶ¼����
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