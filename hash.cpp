#include <iostream>

using namespace std;


// ��ϣ��ÿ���ռ�������
// EMPTY��λ�ÿգ� EXIST��λ���Ѿ���Ԫ�أ� DELETEԪ���Ѿ�ɾ��
enum State
{ 
	EMPTY
	, EXIST
	, DELETE 
};






// ��ϣ�������ô�������������ģ��key����ҪΪ���βſ��Դ����˴��ṩ��keyת��Ϊ���εķ���
// �������ݲ���Ҫת��
/*template<class T>
class DefHashF
{
public:
	size_t operator()(const T& val)
	{
		return val;
	}
};
// keyΪ�ַ������ͣ���Ҫ����ת��Ϊ����
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

//����̽��ʵ��
// Ϊ��ʵ�ּ򵥣��˹�ϣ�������ǽ��Ƚ�ֱ����Ԫ�ذ���һ��
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
		// ����ϣ��ײ�ռ��Ƿ����
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
			// תһȦҲû���ҵ���ע�⣺��̬��ϣ������������Բ��ÿ��ǣ���ϣ����Ԫ�ظ�������
			һ������������ϣ��ͻ���ʻ�������Ҫ���������͹�ϣ��ͻ����˹�ϣ����Ԫ���ǲ��������
			if(hashAddr == startAddr)
			return false;
			*/
		}

		// ����Ԫ��
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