#include "Queue.h"

//队列初始化
void QueueInit(Queue* q)
{
	q->_front = q->_rear = NULL;
}

//队尾入队列
void QueuePush(Queue* q,QDatetype x)
{
	assert(q);
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	if (newNode == NULL)
		printf("内存不足\n");
	else
	{
		newNode->_date = x;
		newNode->_next = NULL;
	}
	if (q->_front == NULL)
		q->_front = q->_rear = newNode;
	else
	{
		q->_rear->_next = newNode;
		q->_rear = newNode;
	}
}

//队头出队列
void QueuePop(Queue* q)
{
	assert(q);
	assert(q->_front);
	QNode* front = q->_front;
	q->_front = q->_front->_next;
	free(front);
	if (q->_front == NULL)//若最后一个队列元素未置空,此时队列尾部仍指向已释放空间,需对队列尾部进行置空
		q->_rear = NULL;
}

//获取队列头部元素
QDatetype QueueFront(Queue* q)
{
	assert(q);
	assert(q->_front);
	return q->_front->_date;
}

//获取队列尾部元素
QDatetype QueueRear(Queue* q)
{
	assert(q);
	assert(q->_rear);
	return q->_rear->_date;
}

//获取队列中的有效元素个数
int QueueSize(Queue* q)
{
	assert(q);
	int size = 0;
	QNode* cur = q->_front;
	while (cur)
	{
		++size;
		cur = cur->_next;
	}
	return size;
}

//检测队列是否为空,如果为空返回非零结果,如果非空返回0;
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->_front == NULL ? 1 : 0;
}

//销毁队列
void QueueDestroy(Queue* q)
{
	assert(q);
	while (q->_front)
	{
		QueuePop(q);
	}
}