/////map��ģ��ʵ��
namespace bit
{
	template<class k,classv>
	class map
	{
		typedef pai<k, v> ValueType;
		//���ڲ���������ǣ���value�е�key��ȡ����

		struct KeyOfValue
		{
			constk& operator()(const ValueType& v)
			{
				return v.first;
			}
		};

		typedef RBTree<k, ValueType, KeyOfValue> RBTree;
	public:
		typedef typename RBTree::Iterator Iterator;
	public:
		map()
		{}

		////Iterator
		Iterator Begin()
		{
			return _t.Begin();
		}

		Iterator End()
		{
			return _t.End();
		}

		////Capacity
		size_t Size()const
		{
			return _t.Size();
		}

		bool Empty()const
		{
			return _t.Empty();
		}

		//Acess
		v& operator[](const k& key)
		{
			return (*(_t.Insert(ValueType(key, v()))).first).second;
		}
		
		const v& operator[](const k& key)const
		{
			return (*(_t.Insert(ValueType(key, v()))).first).second;
		}

		//modify
		pair<Iterator, bool>Insert(const ValueType& data)
		{
			return _t.Insert(data);
		}

		void Clear()
		{
			_t.Clear();
		}

		Iterator Find(const k& key)
		{
			return _t.Find(key);
		}
	private:
		RBTree _t;
	};
}

//set��ģ��ʵ��

namespace bit
{
	template<class k>
	class set
	{
		typedef k ValueType;

		//���ڲ���������ǣ���value�е�key��ȡ����
		struct KeyOfValue
		{
			const k& operator()(const ValueType& key)
			{
				return key;
			}
		};

		//���������������
		typedef RBTree<k, ValueType, KeyOfValue> RBTree;

	public:
		typedef typename RBTree::Iterator Iterator;

	public:
		set()
		{
			//Iterator
			Iterator Begin()
			{
				return _t.Begin();
			}

			Iterator End()
			{
				return _t.End();
			}

			// Capacity
			size_t Size()const
			{
				return _t.Size();
			}
			bool Empty()const
			{
				return _t.Empty();
			}

			// modify
			pair<Iterator, bool> Insert(const ValueType& data)
			{
				return _t.Insert(data);
			}

			void Clear()
			{
				_t.Clear();
			}

			Iterator Find(const K& key)
			{
				return _t.Find(key);
			}
		}
	private:
		RBTree _t;
	};
}