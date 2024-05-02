#include "Heap.h"

//���ݽ���
void Swap(HDatetype* p1,HDatetype* p2)
{
	HDatetype tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//�ѵĳ�ʼ��(С��)		ʱ�临�Ӷ�0(N)
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
	for (int end = (php->_size - 1 - 1) / 2; end >= 0; --end)	//(size - 1)��ʾ�����һ��Ԫ���±�,��(size - 1)�����ټ� 1 �� 2 ��ʾ�����ǰ�ڵ�ĸ��ڵ� 
	{
		HeapDown(php, php->_size, end);
	}
}

//�ѵ������ƶ��㷨(Ĭ�ϵ�ǰ�ڵ��������Ϊ��)
void HeapDown(Heap* php, int node_num, int root)	//ʱ�临�Ӷ�:O(logN)
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

//�ѵ���ɾ
void HeapPush(Heap* php, HDatetype x)
{

}

void HeapPop(Heap* php)
{

}

void HeapSort(Heap* php)	//(���Ѻ�ʹ��)	������С��,�����ô��
{
	for (int cur = php->_size - 1;cur > 0;--cur)
	{
		Swap(&php->_a[0], &php->_a[cur]);
		HeapDown(php, cur, 0);
		//������ӡ����
		for (int i = 0; i < php->_size; i++)
			printf("%d ", php->_a[i]);
		printf("\n");
	}
}