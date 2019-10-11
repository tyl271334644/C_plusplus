#include <iostream>
#include <stdlib.h>
#include <string>
#include <set>

using namespace std;

void TestSet()
{
	int arr[] = { 1, 2, 3, 4, 5, 3, 5, 2, 6, 4, 6, 7, 3, 1, 0, 9, 8, 9 };
	set<int> s(arr, arr + sizeof(arr) / sizeof(arr[0]));

	int arr1[] = { -1,-2,-3,-4,-5,-6 };
	set<int> s1(arr1, arr1 + sizeof(arr1) / sizeof(arr[0]));

	for (auto&e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	for (auto&e : s1)
	{
		cout << e << " ";
	}
	cout << endl;

	for (auto it = s.rbegin(); it != s.rend(); ++it)
	{
		cout << *it << " ";
	}
	
	cout << endl;
	//由于set中元素不能重复，因此3出现的次数只有一次
	cout << s.count(3) << endl;
	s.insert(10);
	s.insert(11);
	s.erase(1);
	s.erase(2);
	s.erase(4);
	s.insert(12);
	s.insert(13);
	s.insert(14);
	for (auto&e : s)
	{
		cout << e << " ";
	}
	cout << endl;
	//set元素交换
	swap(s, s1);
	for (auto&e : s)
	{
		cout << e << " ";
	}
}

void TestMultiSet()
{
	int arr[] = { 2, 4, 5, 6, 7, 2, 4, 3, 1, 2, 35, 6 ,5,5,5};
	multiset<int>s(arr, arr + sizeof(arr) / sizeof(arr[0]));
	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;
	s.erase(5);
	for (auto& e : s)
	{
		cout << e << " ";
	}
}
int main()
{
	TestMultiSet();
	system("pause");
	return 0;
}