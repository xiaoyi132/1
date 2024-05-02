#include<iostream>
using namespace std;


template<class K,class V>
struct AVLTreeNode {
	AVLTreeNode* parent;
	AVLTreeNode* left;
	AVLTreeNode* right;

	int bf; //平衡因子

	pair<K, V> kv;



	AVLTreeNode(pair<K,V>& _kv = pair<K,V>())
		:parent(nullptr),
		left(nullptr),
		right(nullptr),
		kv(_kv),
		bf(0) {};
};

template<class K,class V>
class AVLTree {
	typedef AVLTreeNode<K,V> Node;
public:

	AVLTree()
		:_root(nullptr)
	{}

////////////////////////////////////
	bool Insert(pair<K,V> kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		Node* _parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->kv.first > kv.first)
			{
				_parent = cur;
				cur = cur->left;
			}
			else if (cur->kv.first < kv.first)
			{
				_parent = cur;
				cur = cur->right;
			}
			else
				return false;
		}

		cur = new Node(kv);
		if (_parent->kv.first > kv.first)
		{
			_parent->left = cur;
			cur->parent = _parent;
		}
		else
		{
			_parent->right = cur;
			cur->parent = _parent;
		}

		while (_parent)
		{
			if (cur == _parent->left)
				--_parent->bf;
			else
				++_parent->bf;

			if (_parent->bf == 0)
			{
				break;
			}
			else if (_parent->bf == 1 || _parent->bf == -1)
			{
				cur = _parent;
				_parent = _parent->parent;
			}
			else
			{
				//平衡二叉树平衡因子高度差超过一,需要旋转处理
				if (_parent->bf == 2)
				{
					if (cur->bf == 1)//左单旋
						L_Rotate(_parent);
					else if (cur->bf == -1)//右左双旋
						RL_Rotate(_parent);
				}
				else
				{
					if (cur->bf == -1)//;右单旋
						R_Rotate(_parent);
					else if (cur->bf == 1)//左右双旋
						LR_Rotate(_parent);
				}
				break;
			}

		}

		return true;
	}

	//左单旋情况
	void L_Rotate(Node* parent)
	{
		Node* SubR = parent->right;
		Node* SubRL = SubR->left;
		
		//处理SubR的父母
		Node* ppNode = parent->parent;
		if (parent == _root)
			_root = SubR;
		else
		{
			if (ppNode->right == parent)
				ppNode->right = SubR;
			else
				ppNode->left = SubR;
		}
		SubR->parent = ppNode;

		//将平衡因子为2的父母即parent压至SubR的左子树
		SubR->left = parent;
		parent->parent = SubR;

		//处理原先SubR的左子树SubRL
		if (SubRL)
			SubRL->parent = parent;
		parent->right = SubRL;//

		//更新左旋后parent与SubR的平衡因子
		parent->bf = SubR->bf = 0;
			
	}

	//右单旋情况
	void R_Rotate(Node* parent)
	{
		Node* SubL = parent->left;
		Node* SubLR = SubL->right;

		//处理SubL的父母
		Node* ppNode = parent->parent;
		if (parent == _root)
			_root = SubL;
		else
		{
			if (ppNode->left == parent)
				ppNode->left = SubL;
			else
				ppNode->right = SubL;
		}
		SubL->parent = ppNode;

		//将平衡因子为-2的父母即parent压至SubL的右侧
		parent->parent = SubL;
		SubL->right = parent;

		//处理原先SubL的右子树SubLR
		if(SubLR)
			SubLR->parent = parent;
		parent->left = SubLR;

		//更新右旋后的平衡因子
		parent->bf = SubL->bf = 0;
	}

	//右左双旋 (2 -- -1)
	void RL_Rotate(Node* parent)
	{
		Node* SubR = parent->right;
		Node* SubRL = SubR->left;
		int SubRL_bf = SubRL->bf;	//记录是左插还是右插,以便更新双旋后平衡因子

		R_Rotate(SubR);
		L_Rotate(parent);

		if (SubRL_bf == -1)
		{
			SubRL->bf = parent->bf = 0;
			SubR->bf = 1;
		}
		else if (SubRL_bf == 1)
		{
			SubRL->bf = SubR->bf = 0;
			parent->bf = -1;
		}
		else
		{
			SubRL->bf = parent->bf = SubR->bf = 0;
		}
	}

	//左右双旋(-2 -- 1)
	void LR_Rotate(Node* parent)
	{
		Node* SubL = parent->left;
		Node* SubLR = SubL->right;
		int SubLR_bf = SubLR->bf;

		L_Rotate(SubL);
		R_Rotate(parent);

		if (SubLR_bf == -1)
		{
			SubLR->bf = parent->bf = SubL->bf = 0;
			parent->bf = -1;

		}
		else if (SubLR_bf == 1)
		{
			SubLR->bf = parent->bf = 0;
			SubL->bf = 1;
		}
		else
		{
			parent->bf = SubL->bf = SubLR->bf = 0;
		}
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->left);
		cout << root->kv.first;
		_InOrder(root->right);

	}
	///中序遍历
	void InOrder()
	{
		_InOrder(_root);
	}

public:
	Node* _root;
};