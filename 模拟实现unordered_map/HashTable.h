#pragma once
#include<iostream>
using namespace std;
#include<vector>
//闭散列
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
			//负载因子 = 表中数据 / 表的大小 衡量 哈希表满的程度
			//表接近满,插入数据越容易冲突,冲突越多,效率越低
			//哈希表并不是满了才增容,开放定址法中,一般负载因子在0.7左右开始增容
			//负载因子越小,冲突概率越低,整体效率越高,但是负载因子越小,浪费的空间越大
			//所以负载因子一般取一个折中值
			KeyofT KofT;
			if (_table.size() == 0 || _num * 10 / _table.size() >= 7)
			{
				size_t newSize = _table.size() == 0 ? 10 : _table.size() * 2;
				//第一种增容方式
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
				//第二种增容方式
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

			//计算data的key在hash表中映射的位置
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
//开散列
template<class T>
struct Hash_Node {
	typedef Hash_Node<T> Node;

	Hash_Node(const T& data = T())
		:_data(data),
		_next(nullptr) {}

	T _data;
	Node* _next;
};
//前置声明
template<class K, class T, class KeyofT, class Hash>
class Hash_Table;
//Ref与Ptr作为迭代器 or const迭代器泛式模板
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
	//内部类
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
		//增容
		if (_table.size() == 0 || _table.size() == _num)
		{
			size_t newSize = _table.size() == 0 ? 10 : _table.size() * 2;
			/*Hash_Table new_ht;
			new_ht._table.resize(newSize);*/
			vector<Node*> new_ht;
			new_ht.resize(newSize);
			for (size_t i = 0; i < _table.size(); ++i)
			{
				//第一种
				Node* cur = _table[i];
				while (cur)
				{
					Node* next = cur->_next;
					size_t index = hash(KofT(cur->_data)) % new_ht.size();
					cur->_next = new_ht[index];
					new_ht[index] = cur;
					cur = next;
				}
				//第二种
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

	//迭代器实现
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


