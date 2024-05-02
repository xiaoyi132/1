#include <iostream>
using namespace std;
#include<assert.h>

namespace lixixi {

	template <class T>
	class vector {
	public:
		typedef T value_type;
		typedef value_type* iterator;
		typedef const value_type* const_iterator;

//迭代器
		iterator begin()
		{
			return _start;
		}

		const_iterator cbegin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator cend()
		{
			return _finish;
		}

//构造
		vector() :
			_start(nullptr),
			_finish(nullptr),
			_endofstorage(nullptr){}

//析构
		~vector()
		{
			delete[] _start;
			_start = nullptr;
			_finish = nullptr;
			_endofstorage = nullptr;
		}

//拷贝构造
		vector(const vector<T>& vv)
			:_start(nullptr),
			_finish(nullptr),
			_endofstorage(nullptr)
		{
			reserve(vv.capacity());
			size_t sz = vv.size();
			while(_finish != _start + sz)
			{
				_start[_finish - _start] = vv._start[_finish - _start];
				++_finish;
			}
		}

//扩容
		void reserve(const size_t& newcapacity)
		{
			assert(newcapacity > capacity());
			iterator tmp = new T[newcapacity];
			size_t Old_sz = size();
			if (_start != nullptr)
			{
				for (size_t i = 0; i < Old_sz; ++i)
				{
					tmp[i] = _start[i];
				}
				delete[] (_start);
			}
			_start = tmp;
			_finish = _start + Old_sz;
			_endofstorage = _start + newcapacity;
		}
//获取数组大小
		size_t size()
		{
			return _finish - _start;
		}

		size_t size() const
		{
			return _finish - _start;
		}

//获取数组容量
		size_t capacity()
		{
			return _endofstorage - _start;
		}

		size_t capacity() const
		{
			return _endofstorage - _start;
		}

//插入
		void insert(iterator pos,const value_type& mem)
		{
			assert(pos <= _finish);
			if (_finish == _endofstorage)
			{
				size_t len = pos - _start;
				size_t newcapacity = _endofstorage == nullptr ? 2 : capacity() * 2;
				reserve(newcapacity);
				pos = _start + len;
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = mem;
			++_finish;
		}

//删除
		iterator erase(iterator pos)
		{
			assert(pos < _finish);
			iterator end = pos;
			while (end < _finish - 1)
			{
				*end = *(end + 1);
				++end;
			}
			--_finish;
			return _finish;
		}

//尾插
		void push_back(value_type mem)
		{
			insert(end(), mem);
		}

//尾删
		void pop_back()
		{
			erase(end() - 1);
		}

		void swap(vector<T>& v1,vector<T>& v2)
		{
			::swap(v1._start, v2._start);
			::swap(v1._finish, v2._finish);
			::swap(v1._endofstorage, v2._endofstorage);
		}


//操作符重载
		value_type& operator[](size_t n)
		{
			return *(_start + n);
		}

		const value_type& operator[](size_t n) const
		{
			return *(_start + n);
		}

		vector<T>& operator=(vector<T> v)
		{
			swap(*this, v);
			return *this;
		}

//内部成员
	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
}


int main()
{
	lixixi::vector<string> arr;
	arr.push_back("111111111");
	arr.push_back("222222222");
	arr.push_back("333333333");
	arr.push_back("444444444");
	arr.push_back("abcdefghi");
	arr.push_back("jklmnopqr");

	for (auto s : arr)
	{
		cout << s << " ";
	}
	cout << endl;
	

}