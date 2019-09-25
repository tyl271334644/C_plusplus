#include <iostream>
#include <stdlib.h>
#include <list>
#include <algorithm>

using namespace std;

//class A{
//private: int n;
//
//public:
//	A(int _n){
//		n = _n;
//	}
//	friend bool operator < (const A &a1, const A &a2);
//	friend bool operator ==(const A &a1, const A &a2);
//	friend ostream& operator << (ostream& o, const A &a2);
//};
//bool operator <(const A &a1, const A &a2)
//{
//	return a1.n < a2.n;
//}
//
//bool operator ==(const A &a1, const A &a2)
//{
//	return a1.n == a2.n;
//}
//ostream& operator <<(ostream &o, const A &a)
//{
//	o << a.n;
//	return o;
//}
//
//template <class T>
//void Print(T first, T last)
//{
//	for (; first != last; ++first)
//	{
//		cout << *first << " ";
//	}
//	cout << endl;
//}
int main()
{
	list<int>monkeys;
	int n, m;
	while (true)
	{
		cin >> n >> m;
		if (n == 0 && m == 0)
		{
			break;
		}
		monkeys.clear(); //清空list容器
		for (int i = 1; i <= n; ++i) //将猴子的编号放入list
		{
			monkeys.push_back(i);
		}
		list<int>::iterator it = monkeys.begin();
		while (monkeys.size() > 1)
		{
			for (int i = 1; i < m; ++i)
			{
				++it;
				if (it == monkeys.end())
				{
					it = monkeys.begin();
				}
				//删除元素后，迭代器失效，要重新让迭代器指向被删元素的后面
				it = monkeys.erase(it);
				if (it == monkeys.end()){
					it = monkeys.begin();
				}
			}
		}
		cout << monkeys.front() << endl;//front返回第一个元素的引用
	}
	//A a[] = { 1, 2, 3, 4, 53, 2 };
	//A b[] = { 10, 23, 4, 65,23,10,10,10,4,4,7,7,7,87 };
	//list<A>lst1(a, a + sizeof(a) / sizeof(a[0]))
	//	, lst2(b, b + sizeof(b) / sizeof(b[0]));
	//lst1.sort();
	//cout << "1):"; Print(lst1.begin(),lst1.end()); //从小到大排序后输出

	//lst2.sort();
	//cout << "2):"; Print(lst2.begin(), lst2.end()); //从小到大排序后输出

	//lst2.remove(4); //删除和4相同的元素
	//cout << "3):"; Print(lst2.begin(), lst2.end());

	//lst2.pop_front(); //删除lst2的第一个元素
	//cout << "4):"; Print(lst2.begin(), lst2.end());

	//lst2.unique(); //删除所有和前一个元素相等的元素
	//cout << "5):"; Print(lst2.begin(),lst2.end());

	//lst1.merge(lst2); //合并lst2到lst1并清空lst2
	//cout << "6.1):"; Print(lst1.begin(), lst1.end());
	//cout << "6.2):"; Print(lst2.begin(), lst2.end());

	//lst1.reverse(); //将lst1前后倒置
	//cout << "7):"; Print(lst1.begin(), lst1.end());

	//lst2.insert(lst2.begin(), a + 1, a + 4);  //在 lst2 中插入 三个元素
	//cout << "8)"; Print(lst2.begin(), lst2.end());
	//list <A>::iterator p1, p2, p3;
	//p1 = find(lst1.begin(), lst1.end(), 30);
	//p2 = find(lst2.begin(), lst2.end(), 2);
	//p3 = find(lst2.begin(), lst2.end(), 4);
	//lst1.splice(p1, lst2, p2, p3);  //将[p2, p3)插入p1之前，并从 lst2 中删除[p2,p3)
	//cout << "9)"; Print(lst1.begin(), lst1.end());  
	//cout << "10)"; Print(lst2.begin(), lst2.end());  
	system("pause");
	return 0;
}