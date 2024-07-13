#pragma once
#include<iostream>
using namespace std;
#include<vector>
//��ɢ��
namespace Close_HashTable
{
	enum State {
		EXIST,
		DELETE,
		EMPTY,
	};

	template<class T>
	struct HashData {
		HashData()
			:_data(T()),
			_state(EMPTY) {}

		T _data;
		State _state;
	};

	template<class K, class T, class KeyofT>
	class Hash_Table {
		typedef HashData<T> HashData;
	public:
		bool Insert(const T& data)
		{
			//�������� = �������� / ��Ĵ�С ���� ��ϣ�����ĳ̶�
			//��ӽ���,��������Խ���׳�ͻ,��ͻԽ��,Ч��Խ��
			//��ϣ���������˲�����,���Ŷ�ַ����,һ�㸺��������0.7���ҿ�ʼ����
			//��������ԽС,��ͻ����Խ��,����Ч��Խ��,���Ǹ�������ԽС,�˷ѵĿռ�Խ��
			//���Ը�������һ��ȡһ������ֵ
			KeyofT KofT;
			if (_table.size() == 0 || _num * 10 / _table.size() >= 7)
			{
				size_t newSize = _table.size() == 0 ? 10 : _table.size() * 2;
				//��һ�����ݷ�ʽ
				//vector<HashData> new_ht;
				//new_ht.resize(newSize);
				//for (size_t i = 0; i < _table.size(); ++i)
				//{
				//	if (_table[i]._state == EXIST)
				//	{
				//		size_t index = KofT(_table[i]._data) % new_ht.size();
				//		while (1)
				//		{
				//			if (new_ht[index]._state != EXIST)
				//			{
				//				new_ht[index]._data = _table[i]._data;
				//				new_ht[index]._state = EXIST;
				//				break;
				//			}
				//			else
				//			{
				//				index++;
				//				if (index == new_ht.size())
				//					index = 0;
				//			}
				//		}
				//	}
				//}
				//_table.swap(new_ht);
				//�ڶ������ݷ�ʽ
				Hash_Table<K, T, KeyofT> newHash;
				newHash._table.resize(newSize);
				for (size_t i = 0; i < _table.size(); ++i)
				{
					if (_table[i]._state == EXIST)
					{
						newHash.Insert(_table[i]._data);
					}
				}
				_table.swap(newHash._table);
			}

			//����data��key��hash����ӳ���λ��
			size_t index = data % _table.size();
			while (_table[index]._state == EXIST)
			{
				if (KofT(_table[index]._data) == KofT(data))
					return false;
				else
					index++;
				if (index == _table.size())
					index = 0;
			}
			_table[index]._data = data;
			_table[index]._state = EXIST;
			++_num;
			return true;
		}

		HashData* find(const K& key)
		{
			if (_num == 0)
				return nullptr;
			KeyofT KofT;
			size_t index = key % _table.size();
			while (_table[index]._state != EMPTY)
			{
				if (_table[index]._state == EXIST && KofT(_table[index]._data) == key)
				{
					return &_table[index];
				}
				else
					index++;
				if (index == _table.size())
					index = 0;
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			HashData* rd = find(key);
			if (rd)
			{
				rd->_state = DELETE;
				_num--;
				return true;
			}
			return false;
		}

	private:
		vector<HashData> _table;
		size_t _num = 0;
	};
}

template<class K>
struct Hash {
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};
template<>
struct Hash<string> {
	size_t operator()(const string& st)
	{
		size_t ret = 0;
		for (size_t i = 0; i < st.size(); ++i)
		{
			ret *= 131;
			ret += st[i];
		}
		return ret;
	}
};
//��ɢ��
template<class T>
struct Hash_Node {
	typedef Hash_Node<T> Node;

	Hash_Node(const T& data = T())
		:_data(data),
		_next(nullptr) {}

	T _data;
	Node* _next;
};
//ǰ������
template<class K, class T, class KeyofT, class Hash>
class Hash_Table;
//Ref��Ptr��Ϊ������ or const��������ʽģ��
//template<class K, class T, class Ref, class Ptr, class KeyofT, class Hash>
//struct Hash_Iterator
//{
//	typedef Hash_Node<T> Node;
//	typedef Hash_Iterator<K, T, T&, T*, KeyofT, Hash> iterator;
//	typedef Hash_Iterator<K, T, Ref, Ptr, KeyofT, Hash> Self;

//	typedef Hash_Table<K, T, KeyofT, Hash> Hash_Table;
//	Hash_Iterator(Node* node, Hash_Table* ht)
//		:_it(node),
//		_ht(ht) {}

//	Ref operator*()
//	{
//		return _it->_data;
//	}

//	Ptr operator->()
//	{
//		return &_it->_data;
//	}

//	Self& operator++()
//	{
//		Node* next = _it->_next;
//		KeyofT KofT;
//		if (next)
//			_it = next;
//		else
//		{
//			Hash hash;
//			size_t i = hash(KofT(_it->_data)) % _ht->_table.size() + 1;
//			for (; i < _ht->_table.size(); ++i)
//			{
//				if (_it = _ht->_table[i])
//					break;
//			}
//		}
//		return *this;
//	}

//	bool operator==(const Self& s)
//	{
//		return _it == s._it;
//	}

//	bool operator!=(const Self& s)
//	{
//		return _it != s._it;
//	}

//	Node* _it;
//	Hash_Table* _ht;
//};
template<class K, class T, class KeyofT, class Hash>
class Hash_Table {
	typedef Hash_Node<T> Node;
public:
	//size_t Hash_Func(const size_t key)
	//{
	//	return key % _table.size();
	//}
	//template<class K, class T, class Ref, class Ptr, class KeyofT, class Hash>
	//friend struct Hash_Iterator;
	//�ڲ���
	template<class Ref, class Ptr>
	struct Hash_Iterator
	{
		typedef Hash_Iterator<T&, T*> iterator;
		typedef Hash_Iterator Self;
		typedef Hash_Node<T> Node;
		Hash_Iterator(Node* node, const Hash_Table* ht)
			:_it(node)
			,_ht(ht) {}

		Ref operator*()
		{
			return _it->_data;
		}

		Ptr operator->()
		{
			return &_it->_data;
		}

		Self& operator++()
		{
			Node* next = _it->_next;
			KeyofT KofT;
			if (next)
				_it = next;
			else
			{
				Hash hash;
				size_t i = hash(KofT(_it->_data)) % _ht->_table.size() + 1;
				for (; i < _ht->_table.size(); ++i)
				{
					if (_it = _ht->_table[i])
						break;
				}
			}
			return *this;
		}

		bool operator==(const Self& s)
		{
			return _it == s._it;
		}

		bool operator!=(const Self& s)
		{
			return _it != s._it;
		}

		Node* _it;
		const Hash_Table* _ht;
	};

	typedef Hash_Iterator<T&, T*> iterator;
	typedef Hash_Iterator<const T&, const T*> const_iterator;

	void clear()
	{
		for (size_t i = 0; i < _table.size(); ++i)
		{
			Node* cur = _table[i];
			if (cur)
			{
				Node* next = cur->_next;
				delete cur;
				cur = next;
			}
			_table[i] = nullptr;
		}
		_num = 0;
		return;
	}
	~Hash_Table()
	{
		clear();
	}

	pair<iterator, bool> Insert(const T& kt)
	{
		Hash hash;
		KeyofT KofT;
		//����
		if (_table.size() == 0 || _table.size() == _num)
		{
			size_t newSize = _table.size() == 0 ? 10 : _table.size() * 2;
			/*Hash_Table new_ht;
			new_ht._table.resize(newSize);*/
			vector<Node*> new_ht;
			new_ht.resize(newSize);
			for (size_t i = 0; i < _table.size(); ++i)
			{
				//��һ��
				Node* cur = _table[i];
				while (cur)
				{
					Node* next = cur->_next;
					size_t index = hash(KofT(cur->_data)) % new_ht.size();
					cur->_next = new_ht[index];
					new_ht[index] = cur;
					cur = next;
				}
				//�ڶ���
				//Node* cur = _table[i];
				//
				//while (cur)
				//{
				//	new_ht.Insert(KofT(cur->_data));
				//	cur = cur->_next;
				//}
			}
			_table.swap(new_ht);
			/*_table.swap(new_ht._table);*/
		}
		size_t index = hash(KofT(kt)) % _table.size();
		Node* cur = _table[index];
		while (cur)
		{
			if (KofT(cur->_data) == KofT(kt))
				return make_pair(iterator(cur, this), false);
			else
			{
				cur = cur->_next;
			}
		}
		Node* new_node = new Node(kt);
		new_node->_next = _table[index];
		_table[index] = new_node;
		_num++;
		return make_pair(iterator(new_node, this), true);
	}

	iterator find(const K& key)
	{
		Hash hash;
		KeyofT KofT;
		size_t index = hash(key) % _table.size();
		Node* cur = _table[index];
		while (cur)
		{
			if (hash(KofT(cur->_data)) != hash(key))
				cur = cur->_next;
			else
				return iterator(cur, this);
		}
		return end();
	}

	bool Erase(const K& key)
	{
		Hash hash;
		KeyofT KofT;
		size_t index = hash(key) % _table.size();
		Node* prev = nullptr;
		Node* cur = _table[index];
		while (cur)
		{
			if (hash(KofT(cur->_data)) != hash(key))
			{
				prev = cur;
				cur = cur->_next;
			}
			else
			{
				if (prev)
				{
					prev->_next = cur->_next;
				}
				else
					_table[index] = cur->_next;
				delete cur;
				--_num;
				return true;
			}
		}
		return false;
	}

	//������ʵ��
	iterator begin()
	{
		for (size_t i = 0; i < _table.size(); ++i)
		{
			Node* cur = _table[i];
			if (cur)
				return iterator(cur, this);
		}
		return end();
	}

	iterator end()
	{
		return iterator(nullptr, this);
	}

private:
	vector<Node*> _table;
	size_t _num = 0;
};


