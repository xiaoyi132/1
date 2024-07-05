#pragma once
#include<iostream>
using namespace std;

enum color {
	Red,
	Black
};

template<class K,class V>
struct RBTreeNode {
	RBTreeNode(pair<K,V> kv = pair())
		:Data(kv),
		_parent(nullptr),
		_left(nullptr),
		_right(nullptr),
		_color(Red){}

	/// ��Ա����
	pair<K,V> Data;
	RBTreeNode* _parent;
	RBTreeNode* _left;
	RBTreeNode* _right;
	color _color;
};

template<class K,class V>
class RBTree {
	typedef RBTreeNode<K,V> Node;
public:

	RBTree()
		:_root(nullptr){}

	void Insert(const pair<K,V>& kv)
	{
		//ͬ��������������һ���Ĳ������
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_color = Black;
			return;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->Data.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->Data.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
				return;
		}
		cur = new Node(kv);
		if (parent->Data.first > kv.first)
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_right = cur;
			cur->_parent = parent;
		}

		//��ʼ������ɫ,Ĭ�ϲ�����Ϊ��ɫ,
		//��������ɫΪ����Ե�ǰ·���ĺڽڵ�����Ӱ��,��������㲻���������˳�ѭ��
		while (parent && parent->_color != Black)
		{
			//�����ѭ����ʾһ�����ڸ��׽����һ�����и��׽��
			Node* grandfather = parent->_parent;
			Node* uncle = nullptr;

			//������үү�ڵ�����
			if (parent == grandfather->_left)
			{
				//��������үү����ұ�
				uncle = grandfather->_right;
				//���ı䵱ǰ
				//��һ�����,���׽��Ϊ��,үү���Ϊ��,������Ϊ��
				if (uncle && uncle->_color == Red)
				{
					uncle->_color = parent->_color = Black;
					grandfather->_color = Red;
					//�������
					cur = grandfather;
					parent = cur->_parent;
				}
				else if (uncle == nullptr || uncle->_color == Black)//�ڶ������,���׽��Ϊ��,үү���Ϊ��,������Ϊ�ڻ��,�����cur�ڸ��׽ڵ���Ĳ��ж��Ƿ�˫��
				{
					//��ǰ�ڵ��ڸ��ڵ���Ҳ�(ͼ�������״)��Ҫ����˫��,(����������),������������һ�����
					if (cur == parent->_right)
					{
						L_Rotate(parent);
						//Ϊ�˺������븴��,��cur��parentָ�뻥��
						swap(cur, parent);
					}
					//�ڵ��ڸ��ڵ�����,��������
					R_Rotate(grandfather);
					grandfather->_color = Red;
					parent->_color = Black;
					return;
				}
			}
			else//���׽ڵ���үү�ڵ���ұ�
			{
				uncle = grandfather->_left;
				if (uncle && uncle->_color == Red)
				{
					uncle->_color = parent->_color = Black;
					grandfather->_color = Red;
					//�������
					cur = grandfather;
					parent = cur->_parent;
				}
				else if (uncle == nullptr || uncle->_color == Black)
				{
					if (cur == parent->_left)
					{
						R_Rotate(parent);
						swap(cur,parent);
					}
					L_Rotate(grandfather);
					parent->_color = Black;
					grandfather->_color = Red;
					return;
				}
			}
			_root->_color = Black;
		}
	}

	//�������
	void L_Rotate(Node* parent)
	{
		Node* SubR = parent->_right;
		Node* SubRL = SubR->_left;

		//����SubR�ĸ�ĸ
		Node* ppNode = parent->_parent;
		if (parent == _root)
			_root = SubR;
		else
		{
			if (ppNode->_right == parent)
				ppNode->_right = SubR;
			else
				ppNode->_left = SubR;
		}
		SubR->_parent = ppNode;

		//parentѹ��SubR��������
		SubR->_left = parent;
		parent->_parent = SubR;

		//����ԭ��SubR��������SubRL
		if (SubRL)
			SubRL->_parent = parent;
		parent->_right = SubRL;//

	}

	//�ҵ������
	void R_Rotate(Node* parent)
	{
		Node* SubL = parent->_left;
		Node* SubLR = SubL->_right;

		//����SubL�ĸ�ĸ
		Node* ppNode = parent->_parent;
		if (parent == _root)
			_root = SubL;
		else
		{
			if (ppNode->_left == parent)
				ppNode->_left = SubL;
			else
				ppNode->_right = SubL;
		}
		SubL->_parent = ppNode;

		//��parentѹ��SubL���Ҳ�
		parent->_parent = SubL;
		SubL->_right = parent;

		//����ԭ��SubL��������SubLR
		if (SubLR)
			SubLR->_parent = parent;
		parent->_left = SubLR;

	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->Data.first << " ";
		_InOrder(root->_right);

	}
	///�������
	void InOrder()
	{
		_InOrder(_root);
	}

private:
	Node* _root;
};
