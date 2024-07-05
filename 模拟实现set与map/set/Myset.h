#pragma once
#include "RBTree.h"
using namespace std;

namespace lixixi {

	template<class K>
	class set {
		//·Âº¯Êý
		template<class K>
		struct KofV {
			const K& operator() (const K& node_data)
			{
				return node_data;
			}
		};

		typedef RBTree<K, K, KofV<K>> RBTree;
	public:
		typedef typename RBTree::iterator iterator;
		void Insert(K key)
		{
			_root.Insert(key);
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