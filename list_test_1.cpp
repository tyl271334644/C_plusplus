#include <iostream>
#include <stdlib.h>
#include <list>
#include <vector>
using namespace std;

//��ӡ����
void PrintList(list<int>&v)
{
	for (auto&e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

//////////////////////////////////////////////////////
// push_back/pop_back/push_front/pop_front

//void TestList1()
//{
//	int a[] = { 1, 2, 3 };
//	list<int> v(a, a + sizeof(a) / sizeof(a[0]));
//
//	//��list��β������4��ͷ������0
//	v.push_back(4);
//	v.push_front(0);
//	PrintList(v);
//
//	v.pop_back();
//	v.pop_front();
//	PrintList(v);
//}
//////////////////////////////////////////////////////
// emplace_back / emplace_front / emplace
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << "Date(int,int,int):" << this << endl;
//	}
//	Date(const Date&d)
//		:_year(d._year)
//		, _month(d._month)
//		, _day(d._day)
//	{
//		cout << "Date(const Date&):" << this << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//// push_backβ�壺�ȹ����Ԫ�أ�Ȼ��Ԫ�ؿ������ڵ��У�����ʱ�ȵ����캯�����ٵ��������캯��
//// emplace_backβ�壺�ȹ���ڵ㣬Ȼ����ù��캯���ڽڵ���ֱ�ӹ������
//// emplace_back��push_back����Ч������һ�ο������캯���ĵ���
//
//void TestList2()
//{
//	list<Date> l;
//	Date d(2018, 10, 20);
//	l.push_back(d);
//	l.emplace_back(2018, 10, 21);
//	l.emplace_front(2018, 10, 19);
//}

// insert /erase
//void TestList3()
//{
//	int a[] = { 1, 2, 3 };
//	list<int> v1(a, a + sizeof(a) / sizeof(a[0]));
//	//��ȡ�����еڶ����ڵ�
//	auto pos = ++v1.begin();
//	cout << *pos << endl;
//
//	//��posǰ����ֵΪ4��Ԫ��
//	v1.insert(pos, 4);
//	PrintList(v1);
//
//	//��posǰ����5��ֵΪ5��Ԫ��
//	v1.insert(pos, 5, 5);
//	PrintList(v1);
//
//	//��posǰ����[v.begin(),v.end())�����е�Ԫ��
//	vector<int> v2{ 7, 8, 9 };
//	v1.insert(pos, v2.begin(), v2.end());
//	PrintList(v1);
//
//	//ɾ��posλ���ϵ�Ԫ��
//	v1.erase(pos);
//	PrintList(v1);
//
//	//ɾ��list��[begin,end)�����е�Ԫ�أ���ɾ������Ԫ��
//	v1.erase(v1.begin(), v1.end());
//	PrintList(v1);
//}
// resize/swap/clear
void TestList4()
{
	int a[] = { 1, 2, 3 };
	list<int> v1(a, a + sizeof(a) / sizeof(a[0]));
	PrintList(v1);

	//��v�е�Ԫ�ظ������ӵ�10���������Ԫ����Ĭ��ֵ���
	//list�з��õ����������ͣ�Ĭ��ֵΪ0�����list�з����Զ�������Ԫ�أ�����ȱʡ���캯��

	v1.resize(10);
	PrintList(v1);

	//��v�е�Ԫ�����ӵ�20���������Ԫ����4�����
	v1.resize(20, 4);
	PrintList(v1);

	//��V�е�Ԫ�ؼ��ٵ�5��
	v1.resize(5);
	PrintList(v1);

	//��Vector�е�Ԫ��������list
	vector<int> v2{ 4, 5, 6 };
	list<int> l(v2.begin(), v2.end());
	cout << "�����l��";
	PrintList(l);

	//����v1��l�е�Ԫ��
	v1.swap(l);
	cout << "v1��";
	PrintList(v1);
	cout << "l��";
	PrintList(l);

	//��l�е�Ԫ�����
	cout << "��պ�";
	l.clear();
	cout << l.size() << endl;
}
int main()
{
	TestList4();
	//TestList3();
	//TestList2();
	//TestList1();
	///////////////////////////////////////////////////////////////////////
	//int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	//list<int> v(a, a + sizeof(a) / sizeof(a[0]));

	//for (auto&e : v)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;

	////��list�еĵ�һ���ڵ������һ���ڵ��е�ֵ��Ϊ10
	//v.front() = 10;
	//v.back() = 10;
	//
	//for (auto&e : v)
	//{
	//	cout << e << " ";
	//}

	//const list<int> v2(a, a + sizeof(a) / sizeof(a[0]));
	//const int& ca = v2.front();
	//cout << endl;
	//cout << ca << " ";
	////////////////////////////////////////////////////////////////
	//int a[] = {1,2,3,4,5,6,7,8,9,0};
	//list<int> v(a, a + sizeof(a) / sizeof(a[0]));
	////��ӡlist����Ч�ڵ�ĸ���
	//cout << v.size() << endl;
	//
	////���list�Ƿ�Ϊ��
	//if (v.empty()){
	//	cout << "�յ�list" << endl;
	//}
	//else
	//{
	//	for (const auto&e : v)
	//	{
	//		cout << e << " ";
	//		
	//	}
	//	cout << endl;
	//}
	///////////////////////////////////////////////////////////////////////////
	//int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	//list<int> v(a, a + sizeof(a) / sizeof(a[0]));
	////ʹ�������������ӡlist�е�Ԫ��
	//for (list<int>::iterator it = v.begin(); it != v.end(); ++it)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;
 //   //ʹ�÷����������ӡlist�е�Ԫ��
	//for (list<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;

	//for (auto cit : v)
	//{
	//	cout << cit << " ";
	//}
	/////////////////////////////////////////////////////////////////////////////////////////
	//list<int> l1;  //����յ�l1
	//list<int> l2 (4, 100); //l2�з���4��ֵΪ100��Ԫ��
	//list<int> l3(l2.begin(), l2.end()); //��l2��begin(),end()����ҿ����乹��l3
	//list<int> l4(l3); //��l3��������l4

	////��������Ϊ���������乹��l5
	//int arr[] = {32,543,23,53};
	//list<int> l5(arr, arr + sizeof(arr) / sizeof(int));
	//cout << "l4: data";
	////C++11��ӡ��ʽ
	//for (auto &x : l4)
	//{
	//	cout << x << " ";
	//}
	//cout << endl;
	//cout << "l5:data:";
	////�õ�������ʽ��ӡl5�е�Ԫ��
	//for (list<int>::iterator it = l5.begin(); it != l5.end(); ++it)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;

	//cout << endl;
	system("pause");
	return 0;
}