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
		printf("��ѡ�����->");
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
			printf("ͨѶ¼�˳��ɹ�");
			break;
		default:
			printf("������Ч,\a����������!\n");
		}
	} while (input);
	return 0;
}