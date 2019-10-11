#include <iostream>
#include <stdlib.h>
#include <string>
#include <map>

using namespace std;

void TestMultimap()
{
	multimap<string, string> m;
	m.insert(make_pair("����","������"));
	m.insert(make_pair("�ֳ�", "����ͷ"));
	m.insert(make_pair("³��", "������"));
	//keyֵһ�����в���
	m.insert(make_pair("����", "��ţ"));
	cout << m.size() << endl;

	for (auto&e : m)
	{
		cout << e.first << "--->" << e.second << endl;
		
	}
	cout << m.count("����") << endl;
	//c++11�÷�
	map<string, string> m1{ {"����","������"}, {"�ֳ�","����ͷ"}, {"³��","������"} };
	auto it =m1.insert(make_pair("�ֳ�","����ͷ"));
	if (it.second)
		cout << "�ɹ�����" << endl;
	else
		cout << "����ʧ��" << endl;
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
	//����m�д��ڵ���5�ĵ�һ��Ԫ��
	auto it = m.lower_bound(5);
	cout << it->first << "---->" << it->second << endl;
	cout << endl;
	//����m�д���5��Ԫ�ص�һ��Ԫ��
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