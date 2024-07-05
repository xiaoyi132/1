#pragma once
#include"RBTree.h"
namespace lixixi {



	template<class K,class V>
	class map {
		template<class K, class V>
		struct KeyofValue {
			const K& operator() (const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
		typedef RBTree<K, pair<K, V>, KeyofValue<K,V>> RBTree;
	public:
		typedef typename RBTree::iterator iterator;
		void Insert(pair<K,V> kv)
		{
			_root.Insert(kv);
		}

		iterator begin()
		{
			return _root.begin();
		}

		iterator end()
		{
			return _root.end();
		}

		void InOrder()
		{
			_root.InOrder();
		}

	private:
		RBTree _root;
	};

}