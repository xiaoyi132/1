#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//堆的高度 = Log N ,N为堆的数据个数

typedef int HDatetype;

//数据交换
void Swap(HDatetype*, HDatetype*);


//堆的定义
typedef struct Heap {
	HDatetype* _a;
	int _size;
	int _capacity;
}Heap;


//堆的初始化
void HeapInit(Heap*, HDatetype*, int);

//堆的向下移动算法(默认当前节点的子树已为堆)
void HeapDown(Heap*, int, int);

//堆的排序
void HeapSort(Heap*);	//降序用小堆,升序用大堆