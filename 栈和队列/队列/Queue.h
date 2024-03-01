#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int QDatetype;

//���нڵ㶨��
typedef struct QListNode {
	struct QListNode* _next;
	QDatetype _date;
}QNode;

//���ж���
typedef struct Queue {
	QNode* _front;//��ͷ
	QNode* _rear;//��β
}Queue;

//���г�ʼ��
void QueueInit(Queue*);

//���ٶ���
void QueueDestroy(Queue*);

//�������Ƿ�Ϊ��,���Ϊ�շ��ط�����,����ǿշ���0;
int QueueEmpty(Queue*);

// ��ȡ�����е���ЧԪ�ظ���
int QueueSize(Queue*);

//��ȡ����β��Ԫ��
QDatetype QueueRear(Queue*);

//��ȡ����ͷ��Ԫ��
QDatetype QueueFront(Queue*);

//��ͷ������
void QueuePop(Queue*);

//��β�����
void QueuePush(Queue* q, QDatetype);