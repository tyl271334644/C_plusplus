#include <iostream>
#include <stdlib.h>
#include <list>
#include <vector>
using namespace std;

//打印函数
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
//	//在list的尾部插入4，头部插入0
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
//// push_back尾插：先构造好元素，然后将元素拷贝到节点中，插入时先调构造函数，再调拷贝构造函数
//// emplace_back尾插：先构造节点，然后调用构造函数在节点中直接构造对象
//// emplace_back比push_back更高效，少了一次拷贝构造函数的调用
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
//	//获取链表中第二个节点
//	auto pos = ++v1.begin();
//	cout << *pos << endl;
//
//	//在pos前插入值为4的元素
//	v1.insert(pos, 4);
//	PrintList(v1);
//
//	//在pos前插入5个值为5的元素
//	v1.insert(pos, 5, 5);
//	PrintList(v1);
//
//	//在pos前插入[v.begin(),v.end())区间中的元素
//	vector<int> v2{ 7, 8, 9 };
//	v1.insert(pos, v2.begin(), v2.end());
//	PrintList(v1);
//
//	//删除pos位置上的元素
//	v1.erase(pos);
//	PrintList(v1);
//
//	//删除list中[begin,end)区间中的元素，即删除所有元素
//	v1.erase(v1.begin(), v1.end());
//	PrintList(v1);
//}
// resize/swap/clear
void TestList4()
{
	int a[] = { 1, 2, 3 };
	list<int> v1(a, a + sizeof(a) / sizeof(a[0]));
	PrintList(v1);

	//将v中的元素个数增加到10个，多出的元素用默认值填充
	//list中放置的是内置类型，默认值为0，如果list中放置自定义类型元素，调用缺省构造函数

	v1.resize(10);
	PrintList(v1);

	//将v中的元素增加到20个，多出的元素用4来填充
	v1.resize(20, 4);
	PrintList(v1);

	//将V中的元素减少到5个
	v1.resize(5);
	PrintList(v1);

	//用Vector中的元素来构造list
	vector<int> v2{ 4, 5, 6 };
	list<int> l(v2.begin(), v2.end());
	cout << "构造后l：";
	PrintList(l);

	//交换v1和l中的元素
	v1.swap(l);
	cout << "v1：";
	PrintList(v1);
	cout << "l：";
	PrintList(l);

	//将l中的元素清空
	cout << "清空后：";
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

	////将list中的第一个节点与最后一个节点中的值改为10
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
	////打印list中有效节点的个数
	//cout << v.size() << endl;
	//
	////检测list是否为空
	//if (v.empty()){
	//	cout << "空的list" << endl;
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
	////使用正向迭代器打印list中的元素
	//for (list<int>::iterator it = v.begin(); it != v.end(); ++it)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;
 //   //使用反向迭代器打印list中的元素
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
	//list<int> l1;  //构造空的l1
	//list<int> l2 (4, 100); //l2中放入4个值为100的元素
	//list<int> l3(l2.begin(), l2.end()); //用l2的begin(),end()左闭右开区间构造l3
	//list<int> l4(l3); //用l3拷贝构造l4

	////以数组作为迭代器区间构造l5
	//int arr[] = {32,543,23,53};
	//list<int> l5(arr, arr + sizeof(arr) / sizeof(int));
	//cout << "l4: data";
	////C++11打印方式
	//for (auto &x : l4)
	//{
	//	cout << x << " ";
	//}
	//cout << endl;
	//cout << "l5:data:";
	////用迭代器方式打印l5中的元素
	//for (list<int>::iterator it = l5.begin(); it != l5.end(); ++it)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;

	//cout << endl;
	system("pause");
	return 0;
}