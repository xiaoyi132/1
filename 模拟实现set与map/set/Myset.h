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
		void Insert(const K& key)
		{
			_tree.Insert(key);
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

		void InOrder()
		{
			_tree.InOrder();
		}

	private:
		RBTree _tree;
	};

}