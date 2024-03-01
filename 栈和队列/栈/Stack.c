#include "Stack.h"

//栈的初始化
Stack* StackInit()
{
	Stack* st = (Stack*)malloc(sizeof(Stack));
	st->_st = (STDatetype*)malloc(sizeof(STDatetype) * 3);
	st->_capacity = 3;
	st->_top = 0;
	return st;
}

//入栈
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

//出栈
void StackPop(Stack* st)
{
	assert(st);
	assert((st->_top) > 0);
	(st->_top)--;
}

//栈的销毁
void StackDestroy(Stack* st)
{
	assert(st);
	free(st->_st);
	free(st);
}

//检测栈是否为空
int StackEmpty(Stack* st)
{
	assert(st);
	return st->_top == 0 ? 1 : 0;
}

//获取栈的有效个数
int StackSize(Stack* st)
{
	assert(st);
	return st->_top;
}

////获取栈顶元素
STDatetype StackTop(Stack* st)
{
	assert(st);
	assert(st->_top);
	return st->_st[st->_top - 1];
}