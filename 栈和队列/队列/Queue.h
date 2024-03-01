#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int QDatetype;

//队列节点定义
typedef struct QListNode {
	struct QListNode* _next;
	QDatetype _date;
}QNode;

//队列定义
typedef struct Queue {
	QNode* _front;//队头
	QNode* _rear;//队尾
}Queue;

//队列初始化
void QueueInit(Queue*);

//销毁队列
void QueueDestroy(Queue*);

//检测队列是否为空,如果为空返回非零结果,如果非空返回0;
int QueueEmpty(Queue*);

// 获取队列中的有效元素个数
int QueueSize(Queue*);

//获取队列尾部元素
QDatetype QueueRear(Queue*);

//获取队列头部元素
QDatetype QueueFront(Queue*);

//队头出队列
void QueuePop(Queue*);

//队尾入队列
void QueuePush(Queue* q, QDatetype);