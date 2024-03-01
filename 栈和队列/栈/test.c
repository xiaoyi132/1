#include "Stack.h"
void test1()
{
	Stack* st = StackInit();
	StackPush(st, 1);
	StackPush(st, 2);
	StackPush(st, 3);
	StackPush(st, 4);
	StackPush(st, 5);
	printf("%d ", StackSize(st));
	while (!StackEmpty(st))
	{
		printf("%d ", st->_st[st->_top - 1]);
		StackPop(st);
	}
	StackDestroy(st);
	st = NULL;
}
int main()
{
	test1();
	return 0;
}