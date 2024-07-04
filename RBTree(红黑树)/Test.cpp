#include "RBTree.h"
#include<time.h>
int main()
{
	RBTree<int,int> rb;
	srand(time(0));
	for (int i = 0; i < 100; i++)
	{
		rb.Insert(make_pair(rand(), rand()));
	}
	rb.InOrder();
	return 0;
}