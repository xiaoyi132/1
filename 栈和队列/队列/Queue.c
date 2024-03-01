#include "Queue.h"

//���г�ʼ��
void QueueInit(Queue* q)
{
	q->_front = q->_rear = NULL;
}

//��β�����
void QueuePush(Queue* q,QDatetype x)
{
	assert(q);
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	if (newNode == NULL)
		printf("�ڴ治��\n");
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

//��ͷ������
void QueuePop(Queue* q)
{
	assert(q);
	assert(q->_front);
	QNode* front = q->_front;
	q->_front = q->_front->_next;
	free(front);
	if (q->_front == NULL)//�����һ������Ԫ��δ�ÿ�,��ʱ����β����ָ�����ͷſռ�,��Զ���β�������ÿ�
		q->_rear = NULL;
}

//��ȡ����ͷ��Ԫ��
QDatetype QueueFront(Queue* q)
{
	assert(q);
	assert(q->_front);
	return q->_front->_date;
}

//��ȡ����β��Ԫ��
QDatetype QueueRear(Queue* q)
{
	assert(q);
	assert(q->_rear);
	return q->_rear->_date;
}

//��ȡ�����е���ЧԪ�ظ���
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

//�������Ƿ�Ϊ��,���Ϊ�շ��ط�����,����ǿշ���0;
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->_front == NULL ? 1 : 0;
}

//���ٶ���
void QueueDestroy(Queue* q)
{
	assert(q);
	while (q->_front)
	{
		QueuePop(q);
	}
}