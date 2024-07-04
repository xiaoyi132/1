#include<iostream>
using namespace std;


template<class K,class V>
struct AVLTreeNode {
	AVLTreeNode* parent;
	AVLTreeNode* left;
	AVLTreeNode* right;

	int bf; //ƽ������

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
				//ƽ�������ƽ�����Ӹ߶Ȳ��һ,��Ҫ��ת����
				if (_parent->bf == 2)
				{
					if (cur->bf == 1)//����
						L_Rotate(_parent);
					else if (cur->bf == -1)//����˫��
						RL_Rotate(_parent);
				}
				else
				{
					if (cur->bf == -1)//;�ҵ���
						R_Rotate(_parent);
					else if (cur->bf == 1)//����˫��
						LR_Rotate(_parent);
				}
				break;
			}

		}

		return true;
	}

	//�������
	void L_Rotate(Node* parent)
	{
		Node* SubR = parent->right;
		Node* SubRL = SubR->left;
		
		//����SubR�ĸ�ĸ
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

		//��ƽ������Ϊ2�ĸ�ĸ��parentѹ��SubR��������
		SubR->left = parent;
		parent->parent = SubR;

		//����ԭ��SubR��������SubRL
		if (SubRL)
			SubRL->parent = parent;
		parent->right = SubRL;//

		//����������parent��SubR��ƽ������
		parent->bf = SubR->bf = 0;
			
	}

	//�ҵ������
	void R_Rotate(Node* parent)
	{
		Node* SubL = parent->left;
		Node* SubLR = SubL->right;

		//����SubL�ĸ�ĸ
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

		//��ƽ������Ϊ-2�ĸ�ĸ��parentѹ��SubL���Ҳ�
		parent->parent = SubL;
		SubL->right = parent;

		//����ԭ��SubL��������SubLR
		if(SubLR)
			SubLR->parent = parent;
		parent->left = SubLR;

		//�����������ƽ������
		parent->bf = SubL->bf = 0;
	}

	//����˫�� (2 -- -1)
	void RL_Rotate(Node* parent)
	{
		Node* SubR = parent->right;
		Node* SubRL = SubR->left;
		int SubRL_bf = SubRL->bf;	//��¼����廹���Ҳ�,�Ա����˫����ƽ������

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

	//����˫��(-2 -- 1)
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
	///�������
	void InOrder()
	{
		_InOrder(_root);
	}

public:
	Node* _root;
};