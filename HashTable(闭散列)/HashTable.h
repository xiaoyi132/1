#pragma once
#include<iostream>
using namespace std;
#include<vector>
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

	template<class K, class T, class KeyofValue>
	class Hash {
		typedef HashData<T> HashData;
	public:
		bool Insert(const T& data)
		{
			//负载因子 = 表中数据 / 表的大小 衡量 哈希表满的程度
			//表接近满,插入数据越容易冲突,冲突越多,效率越低
			//哈希表并不是满了才增容,开放定址法中,一般负载因子在0.7左右开始增容
			//负载因子越小,冲突概率越低,整体效率越高,但是负载因子越小,浪费的空间越大
			//所以负载因子一般取一个折中值
			KeyofValue Kofv;
			if (_table.size() == 0 || _num * 10 / _table.size() == 7)
			{
				size_t newSize = _table.size() == 0 ? 10 : _table.size() * 2;
				Hash<K, T, KeyofValue> newHash;
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
				if (Kofv(_table[index]._data) == Kofv(data))
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
			KeyofValue Kofv;
			size_t index = key % _table.size();
			while (_table[index].state != EMPTY)
			{
				if (Kofv(_table[index]._data) == key)
				{
					if (_table[index]._state == DELETE)
						return nullptr;
					else
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
				return true;
			}
			return false;
		}

	private:
		vector<HashData> _table;
		size_t _num = 0;
	};
}