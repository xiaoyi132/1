#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<assert.h>

//��������

// ��Ա��Ϣ
typedef struct PeoInfor {
	char name[13];
	char sex[6];
	char year[4];
	char tele[12];
	char address[20];
}PeoInfor;

//ͨѶ¼:
typedef struct contact {
	int count;
	PeoInfor* date;
	int capacity;
}contact;

//��ϵ������(��������)
int Check_contact(contact*);

//��ӡ�˵�
void menu();

//��ʼ��ͨѶ¼
void Int_contact(contact*);

//ͨѶ¼����
void EX_contact(contact*);

//����ͨѶ¼
void Load_contact(contact*);

//�����ϵ��
void ADD_contact(contact*);

//��ʾͨѶĿ¼
void SHOW_contact(contact*);

//ɾ����ϵ��
void Delete_contact(contact*);

//������ϵ��
void Search_contact(contact*);

//�޸���ϵ����Ϣ
void Modify_contact(contact*);

//����ͨѶ¼
void SORT_contact(contact*);

//ͨѶ¼����
void SAVE_contact(contact*);