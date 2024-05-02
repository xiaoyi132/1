#pragma once
#include<iostream>
using namespace std;
template<class K>
struct BST_Node {

	BST_Node(K num)
		:_key(num),
		_left(nullptr),
		_right(nullptr)
		{}

	K _key;
	BST_Node<K>* _left;
	BST_Node<K>* _right;
};

template <class K>
class BSTree {
	typedef BST_Node<K> Node;
public:
	BSTree()
		: _root(nullptr)
	{}

	bool Insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}

		Node* prev = _root;
		Node* cur = _root;

		while(cur)
		{
			prev = cur;
			if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(key);
		if (prev->_key < key)
		{
			prev->_right = cur;
		}
		else if (prev->_key > key)
		{
			prev->_left = cur;
		}

		return true;
	}

//////中序遍历
	void InOrder()
	{
		_InOrder(_root);
	}
//////删除
	bool Erase(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		//寻找所删除的目标节点
		//需要随时对所删节点的父节点进行记录,方便后续节点链接
		while (cur)
		{
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				//找到节点,开始删除
				//(1)左为空	(2)右为空 (3)左右都不为空
				if (nullptr != parent && cur->_left == nullptr)
				{
					if (cur == parent->_left)
						parent->_left = cur->_right;
					else
						parent->_right = cur->_right;
				}
				else if (nullptr != parent && cur->_right == nullptr)
				{
					if (parent != nullptr && cur == parent->_left)
						parent->_left = cur->_left;
					else
						parent->_right = cur->_left;
				}
				else if(nullptr != cur->_right && cur->_left != nullptr)//左右都不为空,寻找左子树的最大节点 或 右子树的最小节点将所删节点替代
				{
					//右子树的最小节点,从下一深度的左子树方向开始寻找
					Node* RightMin = cur->_right;//代表寻找的最值节点,将所删节点更改为RightMin
					parent = cur;//若未进循环,cur即RightMin的父节点
					while (RightMin->_left)
					{
						parent = RightMin;//开始迭代,父节点更新
						RightMin = RightMin->_left;
					}
					cur->_key = RightMin->_key;//用最值节点替代所删除的节点
					///////令RightMin所指向结点的父节点(需判断子节点方向)指向RightMin的右子树(是否为空皆可满足条件),随后将RightMin所指向节点删除
					cur = RightMin;
					RightMin = nullptr;
					///////需要和前二种情况一致,判断所删节点在其父子树的哪侧
					if (parent != nullptr && cur == parent->_left)
						parent->_left = cur->_right;
					else
						parent->_right = cur->_right;
				}
				if (nullptr == parent)
				{
					if (nullptr != cur->_left)
						_root = cur->_left;
					else if (nullptr != cur->_right)
						_root = cur->_right;
					else
						_root = nullptr;
				}
				delete cur;
				return true;
			}
		}
		return false;
	}

private:

	void _InOrder(Node*& _root)
	{
		if (_root == nullptr)
			return;
		_InOrder(_root->_left);
		cout << _root->_key << " ";
		_InOrder(_root->_right);
	}

	Node* _root = nullptr;
};
