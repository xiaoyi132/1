#include "Stack.h"

//ջ�ĳ�ʼ��
Stack* StackInit()
{
	Stack* st = (Stack*)malloc(sizeof(Stack));
	st->_st = (STDatetype*)malloc(sizeof(STDatetype) * 3);
	st->_capacity = 3;
	st->_top = 0;
	return st;
}

//��ջ
void StackPush(Stack* st, STDatetype x)
{
	assert(st);
	if (st->_top == st->_capacity)
	{
		st->_st = realloc(st->_st, sizeof(STDatetype) * st->_capacity * 2);
		st->_capacity *= 2;
	}
	st->_st[st->_top] = x;
	st->_top++;
}

//��ջ
void StackPop(Stack* st)
{
	assert(st);
	assert((st->_top) > 0);
	(st->_top)--;
}

//ջ������
void StackDestroy(Stack* st)
{
	assert(st);
	free(st->_st);
	free(st);
}

//���ջ�Ƿ�Ϊ��
int StackEmpty(Stack* st)
{
	assert(st);
	return st->_top == 0 ? 1 : 0;
}

//��ȡջ����Ч����
int StackSize(Stack* st)
{
	assert(st);
	return st->_top;
}

////��ȡջ��Ԫ��
STDatetype StackTop(Stack* st)
{
	assert(st);
	assert(st->_top);
	return st->_st[st->_top - 1];
}