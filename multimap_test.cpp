#include <iostream>
#include <stdlib.h>
#include <string>
#include <map>

using namespace std;

void TestMultimap()
{
	multimap<string, string> m;
	m.insert(make_pair("李逵","黑旋风"));
	m.insert(make_pair("林冲", "豹子头"));
	m.insert(make_pair("鲁达", "花和尚"));
	//key值一样进行插入
	m.insert(make_pair("李逵", "铁牛"));
	cout << m.size() << endl;

	for (auto&e : m)
	{
		cout << e.first << "--->" << e.second << endl;
		
	}
	cout << m.count("李逵") << endl;
	//c++11用法
	map<string, string> m1{ {"李逵","黑旋风"}, {"林冲","豹子头"}, {"鲁达","花和尚"} };
	auto it =m1.insert(make_pair("林冲","豹子头"));
	if (it.second)
		cout << "成功插入" << endl;
	else
		cout << "插入失败" << endl;
	cout << endl;
}

void TestMultimap1()
{
	multimap<int, int> m;
	for (int i = 0; i < 10; ++i)
	{
		m.insert(make_pair(i, i));
	}
	for (auto &e :m)
	{
		cout << e.first << "--->" << e.second << endl;
	}
	cout << endl;
	//返回m中大于等于5的第一个元素
	auto it = m.lower_bound(5);
	cout << it->first << "---->" << it->second << endl;
	cout << endl;
	//返回m中大于5的元素第一个元素
	it = m.upper_bound(5);
	cout << it->first << "---->" << it->second << endl;
}
int main()
{
	TestMultimap();
	TestMultimap1();
	system("pause");
	return 0;
}