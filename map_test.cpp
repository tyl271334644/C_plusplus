#include <iostream>
#include <stdlib.h>
#include <string>
#include <map>

using namespace std;

void TestMap()
{
	map<string, string> m{ { "apple", "苹果" }, { "banana", "香蕉" },
							{ "orange", "橘子" }, { "peach", "桃子" },
								{ "waterme", "水蜜桃" }
						  };
	//输入key值打印
	cout << m["apple"] << endl;

	//反向迭代器
	for (map<string,string>::reverse_iterator it = m.rbegin(); it != m.rend(); ++it)
	{
		cout << (*it).first << "---> " << it->second << endl;
	}
	cout << endl;

	//返回最后一元素下一位置的反向迭代器
	map<string, string>::const_reverse_iterator it =m.rbegin() ;
	cout << (*it).first << "---> " << it->second << endl;
	cout << endl;
	for (auto &e : m)
	{
		cout << e.first<<"-->" << e.second<< endl;
	}
	cout << endl;
	cout << m.size() << endl;
}

//当key值不存在时operator[]用默认value与key构造键值对
//然后插入，返回该默认value，at()函数直接抛异常。
void TestMap2()
{
	map<string, string>m;
	//operator[]的原理是：
	//用<key, T()>构造一个键值对，然后调用insert()函数将该键值对插入到map中
	//如果key已经存在，插入失败，insert函数返回该key所在位置的迭代器
	//如果key不存在，插入成功，insert函数返回新插入元素所在位置的迭代器
    //operator[]函数最后将insert返回值键值对中的value返回
	//将“apple”插入map
	m["apple"] = "苹果";
	cout << m["apple"] << endl;
	cout << m.size() << endl;

	//banana不在map，抛出异常
	//m.at("banana");
}

//map中的元素修改
void TestMap3()
{
	map<string, string> m;
	//插入元素，用pair直接来构造键值对
	m.insert(pair<string,string>("peach","桃子"));
	//插入元素，用make_pair直接来构造键值对
	m.insert(make_pair("banana", "香蕉"));
	//用operator[]插入元素
	m["apple"] = "苹果";
	m.insert(m.find("banana"), make_pair("waterme", "水蜜桃"));
	cout << m.size() << endl;
	cout << endl;
	
	for (auto& e : m)
	{
		cout << e.first << "--->" << e.second << endl;
	}
	auto ret = m.insert(make_pair("peach", "桃子"));
	if (ret.second)
		cout << "peach不在map中，已插入" << endl;
	else
		cout << "键值peach的元素已存在 " << ret.first->first << "-->" 
		<< ret.first->second  << " 插入失败 " << endl;
	cout << endl;
	//删除key为“apple”的元素
	m.erase("apple");
	for (auto& e : m)
	{
		cout << e.first << "-->" << e.second << endl;
	}
	//count返回key为x的键值在map中的个数
	if (m.count("apple"))
		cout << "apple还存在" << endl;
	else
		cout << "apple不存在" << endl;
}
int main()
{
	TestMap();
	TestMap2();
	TestMap3();
	system("pause");
	return 0;
}