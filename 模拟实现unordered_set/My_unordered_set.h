#pragma once
#include"HashTable.h"
namespace lixixi {
	template<class K,class Hash = Hash<K>>
	class unordered_set{
		struct KeyofT {
			const K& operator(const K& key)()
			{
				return key;
			}
		};
		typedef Hash_Table<K, K, KeyofT, Hash> Hash_Table;
	public:
		typedef typename Hash_Table::iterator iterator;
		pair<iterator, bool> Insert(const K& key)
		{
			return _ht.Insert(key);
		}

		iterator find(const K& key)
		{
			return _ht.find(key);
		}

		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

		bool Erase(const K& key)
		{
			return _ht.Erase(key);
		}

	private:
		Hash_Table _ht;
	};


}
