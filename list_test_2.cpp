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
		monkeys.clear(); //���list����
		for (int i = 1; i <= n; ++i) //�����ӵı�ŷ���list
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
				//ɾ��Ԫ�غ󣬵�����ʧЧ��Ҫ�����õ�����ָ��ɾԪ�صĺ���
				it = monkeys.erase(it);
				if (it == monkeys.end()){
					it = monkeys.begin();
				}
			}
		}
		cout << monkeys.front() << endl;//front���ص�һ��Ԫ�ص�����
	}
	//A a[] = { 1, 2, 3, 4, 53, 2 };
	//A b[] = { 10, 23, 4, 65,23,10,10,10,4,4,7,7,7,87 };
	//list<A>lst1(a, a + sizeof(a) / sizeof(a[0]))
	//	, lst2(b, b + sizeof(b) / sizeof(b[0]));
	//lst1.sort();
	//cout << "1):"; Print(lst1.begin(),lst1.end()); //��С������������

	//lst2.sort();
	//cout << "2):"; Print(lst2.begin(), lst2.end()); //��С������������

	//lst2.remove(4); //ɾ����4��ͬ��Ԫ��
	//cout << "3):"; Print(lst2.begin(), lst2.end());

	//lst2.pop_front(); //ɾ��lst2�ĵ�һ��Ԫ��
	//cout << "4):"; Print(lst2.begin(), lst2.end());

	//lst2.unique(); //ɾ�����к�ǰһ��Ԫ����ȵ�Ԫ��
	//cout << "5):"; Print(lst2.begin(),lst2.end());

	//lst1.merge(lst2); //�ϲ�lst2��lst1�����lst2
	//cout << "6.1):"; Print(lst1.begin(), lst1.end());
	//cout << "6.2):"; Print(lst2.begin(), lst2.end());

	//lst1.reverse(); //��lst1ǰ����
	//cout << "7):"; Print(lst1.begin(), lst1.end());

	//lst2.insert(lst2.begin(), a + 1, a + 4);  //�� lst2 �в��� ����Ԫ��
	//cout << "8)"; Print(lst2.begin(), lst2.end());
	//list <A>::iterator p1, p2, p3;
	//p1 = find(lst1.begin(), lst1.end(), 30);
	//p2 = find(lst2.begin(), lst2.end(), 2);
	//p3 = find(lst2.begin(), lst2.end(), 4);
	//lst1.splice(p1, lst2, p2, p3);  //��[p2, p3)����p1֮ǰ������ lst2 ��ɾ��[p2,p3)
	//cout << "9)"; Print(lst1.begin(), lst1.end());  
	//cout << "10)"; Print(lst2.begin(), lst2.end());  
	system("pause");
	return 0;
}