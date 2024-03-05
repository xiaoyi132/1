#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//�ѵĸ߶� = Log N ,NΪ�ѵ����ݸ���

typedef int HDatetype;

//���ݽ���
void Swap(HDatetype*, HDatetype*);


//�ѵĶ���
typedef struct Heap {
	HDatetype* _a;
	int _size;
	int _capacity;
}Heap;


//�ѵĳ�ʼ��
void HeapInit(Heap*, HDatetype*, int);

//�ѵ������ƶ��㷨(Ĭ�ϵ�ǰ�ڵ��������Ϊ��)
void HeapDown(Heap*, int, int);

//�ѵ�����
void HeapSort(Heap*);	//������С��,�����ô��