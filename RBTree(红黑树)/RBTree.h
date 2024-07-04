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

	/// 成员变量
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
		//同正常搜索二叉树一样的插入操作
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

		//开始更新颜色,默认插入结点为红色,
		//若父亲颜色为黑则对当前路径的黑节点数无影响,且满足红结点不连续规则退出循环
		while (parent && parent->_color != Black)
		{
			//进入该循环表示一定存在父亲结点上一定还有父亲结点
			Node* grandfather = parent->_parent;
			Node* uncle = nullptr;

			//父亲在爷爷节点的左边
			if (parent == grandfather->_left)
			{
				//叔叔结点在爷爷结点右边
				uncle = grandfather->_right;
				//不改变当前
				//第一种情况,父亲结点为红,爷爷结点为黑,叔叔结点为红
				if (uncle && uncle->_color == Red)
				{
					uncle->_color = parent->_color = Black;
					grandfather->_color = Red;
					//迭代结点
					cur = grandfather;
					parent = cur->_parent;
				}
				else if (uncle == nullptr || uncle->_color == Black)//第二种情况,父亲结点为红,爷爷结点为黑,叔叔结点为黑或空,需根据cur在父亲节点的哪侧判断是否双旋
				{
					//当前节点在父节点的右侧(图像呈折线状)需要左右双旋,(先左旋处理),后续右旋以另一种情况
					if (cur == parent->_right)
					{
						L_Rotate(parent);
						//为了后续代码复用,将cur与parent指针互换
						swap(cur, parent);
					}
					//节点在父节点的左侧,右旋即可
					R_Rotate(grandfather);
					grandfather->_color = Red;
					parent->_color = Black;
					return;
				}
			}
			else//父亲节点在爷爷节点的右边
			{
				uncle = grandfather->_left;
				if (uncle && uncle->_color == Red)
				{
					uncle->_color = parent->_color = Black;
					grandfather->_color = Red;
					//迭代结点
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

	//左单旋情况
	void L_Rotate(Node* parent)
	{
		Node* SubR = parent->_right;
		Node* SubRL = SubR->_left;

		//处理SubR的父母
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

		//parent压至SubR的左子树
		SubR->_left = parent;
		parent->_parent = SubR;

		//处理原先SubR的左子树SubRL
		if (SubRL)
			SubRL->_parent = parent;
		parent->_right = SubRL;//

	}

	//右单旋情况
	void R_Rotate(Node* parent)
	{
		Node* SubL = parent->_left;
		Node* SubLR = SubL->_right;

		//处理SubL的父母
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

		//将parent压至SubL的右侧
		parent->_parent = SubL;
		SubL->_right = parent;

		//处理原先SubL的右子树SubLR
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
	///中序遍历
	void InOrder()
	{
		_InOrder(_root);
	}

private:
	Node* _root;
};
