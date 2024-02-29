#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//ջ���ص�:����ȳ�

typedef int STDatetype;

//ջ�Ķ���
typedef struct Stack{
	STDatetype* _st;
	int _top;//ջ��
	int _capacity;//ջ������
}Stack;

//ջ�ĳ�ʼ��
Stack* StackInit();

//��ջ
void StackPush(Stack*, STDatetype);

//��ջ
void StackPop(Stack*);

//ջ������
void StackDestroy(Stack*);

//���ջ�Ƿ�Ϊ��
int StackEmpty(Stack*);

//��ȡջ����Ч����
int StackSize(Stack*);

//��ȡջ��Ԫ��
STDatetype StackTop(Stack*);