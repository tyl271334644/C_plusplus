#include <iostream>
#include <stdlib.h>
#include <string>
#include <map>

using namespace std;

void TestMap()
{
	map<string, string> m{ { "apple", "ƻ��" }, { "banana", "�㽶" },
							{ "orange", "����" }, { "peach", "����" },
								{ "waterme", "ˮ����" }
						  };
	//����keyֵ��ӡ
	cout << m["apple"] << endl;

	//���������
	for (map<string,string>::reverse_iterator it = m.rbegin(); it != m.rend(); ++it)
	{
		cout << (*it).first << "---> " << it->second << endl;
	}
	cout << endl;

	//�������һԪ����һλ�õķ��������
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

//��keyֵ������ʱoperator[]��Ĭ��value��key�����ֵ��
//Ȼ����룬���ظ�Ĭ��value��at()����ֱ�����쳣��
void TestMap2()
{
	map<string, string>m;
	//operator[]��ԭ���ǣ�
	//��<key, T()>����һ����ֵ�ԣ�Ȼ�����insert()�������ü�ֵ�Բ��뵽map��
	//���key�Ѿ����ڣ�����ʧ�ܣ�insert�������ظ�key����λ�õĵ�����
	//���key�����ڣ�����ɹ���insert���������²���Ԫ������λ�õĵ�����
    //operator[]�������insert����ֵ��ֵ���е�value����
	//����apple������map
	m["apple"] = "ƻ��";
	cout << m["apple"] << endl;
	cout << m.size() << endl;

	//banana����map���׳��쳣
	//m.at("banana");
}

//map�е�Ԫ���޸�
void TestMap3()
{
	map<string, string> m;
	//����Ԫ�أ���pairֱ���������ֵ��
	m.insert(pair<string,string>("peach","����"));
	//����Ԫ�أ���make_pairֱ���������ֵ��
	m.insert(make_pair("banana", "�㽶"));
	//��operator[]����Ԫ��
	m["apple"] = "ƻ��";
	m.insert(m.find("banana"), make_pair("waterme", "ˮ����"));
	cout << m.size() << endl;
	cout << endl;
	
	for (auto& e : m)
	{
		cout << e.first << "--->" << e.second << endl;
	}
	auto ret = m.insert(make_pair("peach", "����"));
	if (ret.second)
		cout << "peach����map�У��Ѳ���" << endl;
	else
		cout << "��ֵpeach��Ԫ���Ѵ��� " << ret.first->first << "-->" 
		<< ret.first->second  << " ����ʧ�� " << endl;
	cout << endl;
	//ɾ��keyΪ��apple����Ԫ��
	m.erase("apple");
	for (auto& e : m)
	{
		cout << e.first << "-->" << e.second << endl;
	}
	//count����keyΪx�ļ�ֵ��map�еĸ���
	if (m.count("apple"))
		cout << "apple������" << endl;
	else
		cout << "apple������" << endl;
}
int main()
{
	TestMap();
	TestMap2();
	TestMap3();
	system("pause");
	return 0;
}