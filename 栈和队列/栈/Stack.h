#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//栈的特点:后进先出

typedef int STDatetype;

//栈的定义
typedef struct Stack{
	STDatetype* _st;
	int _top;//栈顶
	int _capacity;//栈的容量
}Stack;

//栈的初始化
Stack* StackInit();

//入栈
void StackPush(Stack*, STDatetype);

//出栈
void StackPop(Stack*);

//栈的销毁
void StackDestroy(Stack*);

//检测栈是否为空
int StackEmpty(Stack*);

//获取栈的有效个数
int StackSize(Stack*);

//获取栈顶元素
STDatetype StackTop(Stack*);