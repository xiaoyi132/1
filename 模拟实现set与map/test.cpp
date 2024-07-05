#include "Myset.h"
#include "Mymap.h"

void test_set()
{
	lixixi::set<int> st;
	for (int i = 0; i < 100; i++)
	{
		st.Insert(rand());
	};

	lixixi::set<int>::iterator it = st.begin();

	for (auto num : st)
	{
		cout << num << " ";
	}

	cout << *it;
}

void test_map()
{
	lixixi::map<int, int> mp;
	for (int i = 0; i < 100; i++)
	{
		mp.Insert(make_pair(rand(), rand()));
	};

	lixixi::map<int, int>::iterator it = mp.begin();

	for (auto num : mp)
	{
		cout << num.first << " ";
	}
	cout << it->first;
}
int main()
{
	srand(time(0));
	test_set();
	
	return 0;
}