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

// ��ϣͰ��Ԫ�����������������ģ�����ȸ�����ϣͰ�Ľṹ
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

	// ��ϣͰ�е�Ԫ�ز����ظ�
	PNode* Insert(const V& data)
	{
		// ȷ���Ƿ���Ҫ���ݡ�����
		// _CheckCapacity();

		// 1. ����Ԫ�����ڵ�Ͱ��
		size_t bucketNo = HashFunc(data);

		// 2. ����Ԫ���Ƿ���Ͱ��
		PNode pCur = _ht[bucketNo];
		while (pCur)
		{
			if (pCur->_data == data)
				return pCur;

			pCur = pCur->_pNext;
		}

		// 3. ������Ԫ��
		pCur = new Node(data);

		// ����ͷ�巨���룬Ч�ʸ�
		pCur->_pNext = _ht[bucketNo];
		_ht[bucketNo] = pCur;
		_size++;

		return pCur;
	}

	// ɾ����ϣͰ��Ϊdata��Ԫ��(data�����ظ�)������ɾ��Ԫ�ص���һ���ڵ�
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
				// ͷɾ
				if (pCur == _ht[bucketNo])
				{
					_ht[bucketNo] = pCur->_pNext;
				}
				���ؿƼ�
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

	// ����data�Ƿ��ڹ�ϣͰ��
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
	//����
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
					// ���ýڵ��ԭ��ϣ���в����
					_ht[bucketIdx] = pCur->_pNext;

					// ���ýڵ���뵽�¹�ϣ����
					// ����ýڵ����¹�ϣ���е�Ͱ��
					size_t bucketNo = newHt.HashFunc(pCur->_data);

					// �ҽڵ�����Ͱ�е�λ��
					PNode pPos = newHt._ht[bucketNo];
					while (pPos)
					{
						if (pPos->_data == pCur->_data)
							break;

						pPos = pPos->_pNext;
					}

					// ���ڵ���뵽�¹�ϣ����
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

					// ��ȡԭ��ϣ��bucketIdxͰ����һ���ڵ�
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
	size_t _size; // ��ϣ������ЧԪ�صĸ���
};



