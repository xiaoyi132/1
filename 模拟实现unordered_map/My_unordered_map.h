#pragma once
#include "HashTable.h"


namespace lixixi {
	template<class K, class T, class Hash = Hash<K>>
	class unordered_map
	{
		struct KeyofT
		{
			const K& operator()(const pair<K, T>& pa)
			{
				return pa.first;
			}
		};
		typedef Hash_Table<K, pair<K, T>, KeyofT, Hash> HashTable;
	public:
		typedef typename HashTable::iterator iterator;
		pair<iterator, bool> Insert(const pair<K, T>& pa)
		{
			return _ht.Insert(pa);
		}

		iterator find(const K& key)
		{
			return _ht.find(key);
		}

		bool Erase(const K& key)
		{
			return _ht.Erase(key);
		}

		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}
	private:
		HashTable _ht;
	};

	void test_unordered_map()
	{
		unordered_map<int, int> mp;
		mp.Insert(make_pair(22,22));
		mp.Insert(make_pair(12,12));
		mp.Insert(make_pair(2, 2));
		mp.Insert(make_pair(3, 3));
		mp.Insert(make_pair(43, 43));
		mp.Insert(make_pair(13, 13));
		mp.Insert(make_pair(53, 53));
		mp.Insert(make_pair(93, 83));
		mp.Insert(make_pair(23, 23));
		mp.Insert(make_pair(45, 45));
		mp.Insert(make_pair(31, 31));
		mp.Insert(make_pair(21, 21));
		mp.Insert(make_pair(98, 98));
		mp.Insert(make_pair(97, 97));
		mp.Erase(97);
		mp.Erase(67);

		for (auto& num : mp)
		{
			cout << num.first << " ";
		}

	}

}
