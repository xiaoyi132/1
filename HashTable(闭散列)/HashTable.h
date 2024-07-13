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
			//�������� = �������� / ��Ĵ�С ���� ��ϣ�����ĳ̶�
			//��ӽ���,��������Խ���׳�ͻ,��ͻԽ��,Ч��Խ��
			//��ϣ���������˲�����,���Ŷ�ַ����,һ�㸺��������0.7���ҿ�ʼ����
			//��������ԽС,��ͻ����Խ��,����Ч��Խ��,���Ǹ�������ԽС,�˷ѵĿռ�Խ��
			//���Ը�������һ��ȡһ������ֵ
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

			//����data��key��hash����ӳ���λ��
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