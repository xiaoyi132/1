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

//////�������
	void InOrder()
	{
		_InOrder(_root);
	}
//////ɾ��
	bool Erase(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		//Ѱ����ɾ����Ŀ��ڵ�
		//��Ҫ��ʱ����ɾ�ڵ�ĸ��ڵ���м�¼,��������ڵ�����
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
				//�ҵ��ڵ�,��ʼɾ��
				//(1)��Ϊ��	(2)��Ϊ�� (3)���Ҷ���Ϊ��
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
				else if(nullptr != cur->_right && cur->_left != nullptr)//���Ҷ���Ϊ��,Ѱ�������������ڵ� �� ����������С�ڵ㽫��ɾ�ڵ����
				{
					//����������С�ڵ�,����һ��ȵ�����������ʼѰ��
					Node* RightMin = cur->_right;//����Ѱ�ҵ���ֵ�ڵ�,����ɾ�ڵ����ΪRightMin
					parent = cur;//��δ��ѭ��,cur��RightMin�ĸ��ڵ�
					while (RightMin->_left)
					{
						parent = RightMin;//��ʼ����,���ڵ����
						RightMin = RightMin->_left;
					}
					cur->_key = RightMin->_key;//����ֵ�ڵ������ɾ���Ľڵ�
					///////��RightMin��ָ����ĸ��ڵ�(���ж��ӽڵ㷽��)ָ��RightMin��������(�Ƿ�Ϊ�սԿ���������),���RightMin��ָ��ڵ�ɾ��
					cur = RightMin;
					RightMin = nullptr;
					///////��Ҫ��ǰ�������һ��,�ж���ɾ�ڵ����丸�������Ĳ�
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
