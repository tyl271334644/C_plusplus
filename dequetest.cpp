#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <deque>

using namespace std;

void PrintDeque(const deque<int>& d)
{
	for (const auto &e :d)
	{
		cout << e << " ";
	}
	cout << endl;

}

void TestDeque1()
{
	//构造空的双端队列
	deque<int> d1;
	
	//用10个值为5的元素构造双端队列
	deque<int> d2(10, 5);
	PrintDeque(d2);

	//用数组的区间构造双端队列
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	deque<int> d3(arr, arr + sizeof(arr) / sizeof(arr[0]));
	PrintDeque(d3);

	//用d3拷贝构造d4
	deque<int> d4(d3);
	PrintDeque(d4);
}

void TestDeque2()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	deque<int> d(arr, arr + sizeof(arr) / sizeof(arr[0]));
	//正向迭代器打印deque中的元素
	for (auto it = d.cbegin(); it != d.cend(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	//反向迭代器打印deuqe中的元素
	for (auto it = d.crbegin(); it != d.crend(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void TestDeque3()
{
	//初始化,C++11用法
	deque<int>d1{ 2, 3, 4 };
	d1.push_back(5); //尾插5
	d1.push_front(1); //头插1
	PrintDeque(d1);
	
	cout << d1.size() << endl;
	cout << d1.front() << endl;
	cout << d1.back() << endl;

	// 如果是内置类型元素
	// emplace_back与push_back emplace_front与push_front的效率形同
	// 如果是自定义类型元素
	// emplace_back/emplace_front的效率更高，这两个操作直接在尾部或者头部构造元素
	// push_back/push_front的效率低，该操作时先将元素构造好，然后拷贝到尾部或头部
	d1.emplace_back(6); //尾插6
	d1.emplace_front(0); //头插0
	PrintDeque(d1);

	// 在deque的begin位置插入元素0
	d1.insert(d1.begin(), 0);
	PrintDeque(d1);
	// 删除deque首部与尾部元素
	d1.pop_front();
	d1.pop_back();
	d1.erase(d1.begin());
	PrintDeque(d1);
}

void TestDeque4()
{
	int arr[] = { 2, 5, 6, 3, 67, 2, 5, 7, 2, 3, 4 };
	deque<int> d(arr, arr + sizeof(arr) / sizeof(arr[0]));
	PrintDeque(d);

	sort(d.begin(), d.end());
	PrintDeque(d);

}
int main()
{
	//TestDeque1();
	//TestDeque2();
	//TestDeque3();
	TestDeque4();
	system("pause");
	return 0;
}