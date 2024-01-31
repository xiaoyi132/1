#include "contact.h"

void menu()
{
	printf("****************     CONTACT    ***************\n");
	printf("*************1. ADD         2.DEL *************\n");
	printf("*************3.	Search      4.SHOW ************\n");
	printf("*************5.	Modify	    6.SORT ************\n");
	printf("*************0.	EXIT               ************\n");
	printf("***********************************************\n");
}

int main()
{
	contact pc;
	menu();
	int input = 0;
	Int_contact(&pc);
	Load_contact(&pc);
	do {
		printf("请选择操作->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			ADD_contact(&pc);
			break;
		case 2:
			Delete_contact(&pc);
			break;
		case 3:
			Search_contact(&pc);
			break;
		case 4:
			SHOW_contact(&pc);
			break;
		case 5:
			Modify_contact(&pc);
			break;
		case 6:
			SORT_contact(&pc);
			break;
		case 0:
			SAVE_contact(&pc);
			printf("通讯录退出成功");
			break;
		default:
			printf("输入无效,\a请重新输入!\n");
		}
	} while (input);
	return 0;
}