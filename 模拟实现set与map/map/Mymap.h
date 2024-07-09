#pragma once
#include"RBTree.h"
namespace lixixi {
	template<class K,class T>
	class map {
		template<class K, class T>
		struct KeyofValue {
			const K& operator() (const pair<K, T>& kv)
			{
				return kv.first;
			}
		};
		typedef RBTree<K, pair<K, T>, KeyofValue<K,T>> RBTree;
	public:
		typedef typename RBTree::iterator iterator;
		void Insert(const pair<K,T>& kv)
		{
			_tree.Insert(kv);
		}

		iterator begin()
		{
			return _tree.begin();
		}

		iterator end()
		{
			return _tree.end();
		}

		iterator find(const K& key)
		{
			return _tree.find(key);
		}

		///[]
		T& operator[](const K& key)
		{
			pair<iterator, bool> retp = _tree.Insert(make_pair(key, T()));
			return retp.first->second;
		}

		void InOrder()
		{
			_tree.InOrder();
		}

	private:
		RBTree _tree;
	};

}