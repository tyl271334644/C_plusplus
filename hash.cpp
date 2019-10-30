#include <iostream>

using namespace std;


// 哈希表每个空间给个标记
// EMPTY此位置空， EXIST此位置已经有元素， DELETE元素已经删除
enum State
{ 
	EMPTY
	, EXIST
	, DELETE 
};






// 哈希函数采用处理余数法，被模的key必须要为整形才可以处理，此处提供将key转化为整形的方法
// 整形数据不需要转化
/*template<class T>
class DefHashF
{
public:
	size_t operator()(const T& val)
	{
		return val;
	}
};
// key为字符串类型，需要将其转化为整形
class Str2Int
{
public:
	size_t operator()(const string& str)
	{
		return BKDRHash(str.c_str());
	}

	size_t BKDRHash(const char * str)
	{
		unsigned int seed = 131; // 31 131 1313 13131 131313
		unsigned int hash = 0;
		while (*str)
		{
			hash = hash * seed + (*str++);
		}

		return (hash & 0x7FFFFFFF);
	}
};*/

//线性探测实现
// 为了实现简单，此哈希表中我们将比较直接与元素绑定在一起
template<class K, class V>
class HashTable
{
	struct Elem
	{
		pair<K, V> _val;
		State _state;
	};

public:
	HashTable(size_t capacity = 3)
		: _ht(capacity)
		, _size(0)
	{
		for (size_t i = 0; i < capacity; ++i)
			_ht[i]._state = EMPTY;
	}

	bool Insert(const pair<K, V>& val)
	{
		// 检测哈希表底层空间是否充足
		// _CheckCapacity();

		size_t hashAddr = HashFunc(key);
		// size_t startAddr = hashAddr;
		while (_ht[hashAddr]._state != EMPTY)
		{
			if (_ht[hashAddr]._state == EXIST && _ht[hashAddr]._val.first == key)
				return false;

			hashAddr++;

			// hashAddr %= _ht.capacity();

			if (hashAddr == _ht.capacity())
				hashAddr = 0;
			/*
			// 转一圈也没有找到，注意：动态哈希表，该种情况可以不用考虑，哈希表中元素个数到达
			一定的数量，哈希冲突概率会增大，需要扩容来降低哈希冲突，因此哈希表中元素是不会存满的
			if(hashAddr == startAddr)
			return false;
			*/
		}

		// 插入元素
		_ht[hashAddr]._state = EXIST;
		_ht[hashAddr]._val = val;
		_size++;
		return true;
	}

	int Find(const K& key)
	{
		size_t hashAddr = HashFunc(key);
		while (_ht[hashAddr]._state != EMPTY)
		{
			if (_ht[hashAddr]._state == EXIST && _ht[hashAddr]._val.first == key)
				return hashAddr;

			hashAddr++;
		}

		return hashAddr;
	}

	bool Erase(const K& key)
	{
		int index = Find(key);
		if (-1 != index)
		{
			_ht[index]._state = DELETE;
			_size++;
			return true;
		}

		return false;
	}

	size_t Size()const
	{
		return _size;
	}

	bool Empty() const
	{
		return 0 == _size;
	}

	void Swap(HashTable<K, V, HF>& ht)
	{
		swap(_ht, ht._ht);
		swap(_size, ht._size);
	}
private:
	size_t HashFunc(const K& key)
	{
		return key % _ht.capacity();
	}

/*private:
	size_t HashFunc(const K& key)
	{
		return HF()(key) % _ht.capacity();
	}
	*/
private:
	vector<Elem> _ht;
	size_t _size;
};