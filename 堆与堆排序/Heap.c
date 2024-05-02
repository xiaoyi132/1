#include "Heap.h"

//数据交换
void Swap(HDatetype* p1,HDatetype* p2)
{
	HDatetype tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//堆的初始化(小堆)		时间复杂度0(N)
void HeapInit(Heap* php, HDatetype* arr,int n)
{
	HDatetype* tmp = (HDatetype*)malloc(n * sizeof(HDatetype));
	if (tmp == NULL)
	{
		perror("HeapInit:");
		return;
	}
	memcpy(tmp, arr, sizeof(HDatetype) * n);
	php->_a = tmp;
	php->_capacity = php->_size = n;
	for (int end = (php->_size - 1 - 1) / 2; end >= 0; --end)	//(size - 1)表示堆最后一个元素下标,对(size - 1)后续再减 1 除 2 表示求出当前节点的父节点 
	{
		HeapDown(php, php->_size, end);
	}
}

//堆的向下移动算法(默认当前节点的子树已为堆)
void HeapDown(Heap* php, int node_num, int root)	//时间复杂度:O(logN)
{
	assert(php);
	int parent = root;
	int child = parent * 2 + 1;
	while (child < node_num)
	{
		if (child + 1 < node_num && php->_a[child] > php->_a[child + 1])
			child += 1;
		if (php->_a[parent] <= php->_a[child])
		{
			break;
		}
		else
		{
			Swap(&php->_a[parent], &php->_a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
	}
}

//堆的增删
void HeapPush(Heap* php, HDatetype x)
{

}

void HeapPop(Heap* php)
{

}

void HeapSort(Heap* php)	//(建堆后使用)	降序用小堆,升序用大堆
{
	for (int cur = php->_size - 1;cur > 0;--cur)
	{
		Swap(&php->_a[0], &php->_a[cur]);
		HeapDown(php, cur, 0);
		//排序后打印数组
		for (int i = 0; i < php->_size; i++)
			printf("%d ", php->_a[i]);
		printf("\n");
	}
}