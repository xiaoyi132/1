#include "AVLTree.h"

int main()
{
	AVLTree<int, char> av;
	av.Insert(make_pair(1, 'a'));
	av.Insert(make_pair(6, 'b'));
	av.Insert(make_pair(4, 't'));
	av.Insert(make_pair(9, 'f'));
	av.Insert(make_pair(10, 'e'));
	av.Insert(make_pair(5, 'c'));
	av.InOrder();
	return 0;
}