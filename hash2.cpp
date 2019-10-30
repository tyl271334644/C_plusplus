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

// 哈希桶中元素是用链表串接起来的，因此先给出哈希桶的结构
template<class V>
struct HashBucketNode
{
	HashBucketNode(const V& data)
	: _pNext(nullptr)
	, _data(data)
	{}

	HashBucketNode<V>* _pNext;
	V _data;
};

template<class V, class HF = DefHashF<T> >
class HashBucket
{
	typedef HashBucketNode<V> Node;
	typedef Node* PNode;

public:
		HashBucket(size_t capacity = 3)
		: _size(0)
		{
			_ht.resize(GetNextPrime(capacity), nullptr);
		}

	// 哈希桶中的元素不能重复
	PNode* Insert(const V& data)
	{
		// 确认是否需要扩容。。。
		// _CheckCapacity();

		// 1. 计算元素所在的桶号
		size_t bucketNo = HashFunc(data);

		// 2. 检测该元素是否在桶中
		PNode pCur = _ht[bucketNo];
		while (pCur)
		{
			if (pCur->_data == data)
				return pCur;

			pCur = pCur->_pNext;
		}

		// 3. 插入新元素
		pCur = new Node(data);

		// 采用头插法插入，效率高
		pCur->_pNext = _ht[bucketNo];
		_ht[bucketNo] = pCur;
		_size++;

		return pCur;
	}

	// 删除哈希桶中为data的元素(data不会重复)，返回删除元素的下一个节点
	PNode* Erase(const V& data)
	{
		size_t bucketNo = HashFunc(data);
		PNode pCur = _ht[bucketNo];
		PNode pPrev = nullptr;
		pNode pRet = nullptr;

		while (pCur)
		{
			if (pCur->_data == data)
			{
				// 头删
				if (pCur == _ht[bucketNo])
				{
					_ht[bucketNo] = pCur->_pNext;
				}
				比特科技
				else
				{
					pPrev->_pNext = pCur->_pNext;
				}

				pRet = pCur->_pNext;
				delete pCur;
				_size--;
				return pRet;
			}
		}

		return nullptr;
	}

	// 查找data是否在哈希桶中
	PNode* Find(const V& data)
	{
		size_t bucketNo = HashFunc(data);
		PNode pCur = _ht[bucketNo];

		while (pCur)
		{
			if (pCur->_data == data)
				return pCur;

			pCur = pCur->_pNext;
		}

		return nullptr;
	}

	size_t Size()const
	{
		return _size;
	}

	bool Empty()const
	{
		return 0 == _size;
	}

	void Clear()
	{
		for (size_t bucketNo = 0; bucketNo < _ht.capacity(); ++bucketNo)
		{
			PNode pCur = _ht[bucketNo];
			while (pCur)
			{
				_ht[bucketNo] = pCur->_pNext;
				delete pCur;
				pCur = _ht[bucketNo];
			}
		}

		_size = 0;
	}

	bool BucketCount()const
	{
		return _ht.capacity();
	}

	void Swap(HashBucket<V, HF>& ht)
	{
		swap(_ht, ht._ht);
		swap(_size, ht._size);
	}
	//增容
	/*void _CheckCapacity()
	{
		size_t bucketCount = BucketCount();
		if (_size == bucketCount)
		{
			HashBucket<V, HF> newHt(bucketCount);

			for (size_t bucketIdx = 0; bucketIdx < bucketCount; ++bucketIdx)
			{
				PNode pCur = _ht[bucketIdx];
				while (pCur)
				{
					// 将该节点从原哈希表中拆出来
					_ht[bucketIdx] = pCur->_pNext;

					// 将该节点插入到新哈希表中
					// 计算该节点在新哈希表中的桶号
					size_t bucketNo = newHt.HashFunc(pCur->_data);

					// 找节点在新桶中的位置
					PNode pPos = newHt._ht[bucketNo];
					while (pPos)
					{
						if (pPos->_data == pCur->_data)
							break;

						pPos = pPos->_pNext;
					}

					// 将节点插入到新哈希表中
					if (nullptr == pPos)
					{
						pCur->_pNext = newHt._ht[bucketNo];
						newHt._ht[bucketNo] = pCur;
					}
					else
					{
						pCur->_pNext = pPos->next;
						pPos->_pNext = pCur;
					}

					// 获取原哈希表bucketIdx桶中下一个节点
					pCur = _ht[bucketIdx];
				}
			}

			newHt._size = _size;
			this->Swap(newHt);
		}
	}
	*/

	~HashBucket()
	{
		Clear();
	}

private:
	size_t HashFunc(const V& data)
	{
		return HF()(data) % _ht.BucketCount();
	}

private:
	vector<PNode*> _ht;
	size_t _size; // 哈希表中有效元素的个数
};



