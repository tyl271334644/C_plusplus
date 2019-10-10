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
	//����յ�˫�˶���
	deque<int> d1;
	
	//��10��ֵΪ5��Ԫ�ع���˫�˶���
	deque<int> d2(10, 5);
	PrintDeque(d2);

	//����������乹��˫�˶���
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	deque<int> d3(arr, arr + sizeof(arr) / sizeof(arr[0]));
	PrintDeque(d3);

	//��d3��������d4
	deque<int> d4(d3);
	PrintDeque(d4);
}

void TestDeque2()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	deque<int> d(arr, arr + sizeof(arr) / sizeof(arr[0]));
	//�����������ӡdeque�е�Ԫ��
	for (auto it = d.cbegin(); it != d.cend(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	//�����������ӡdeuqe�е�Ԫ��
	for (auto it = d.crbegin(); it != d.crend(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void TestDeque3()
{
	//��ʼ��,C++11�÷�
	deque<int>d1{ 2, 3, 4 };
	d1.push_back(5); //β��5
	d1.push_front(1); //ͷ��1
	PrintDeque(d1);
	
	cout << d1.size() << endl;
	cout << d1.front() << endl;
	cout << d1.back() << endl;

	// �������������Ԫ��
	// emplace_back��push_back emplace_front��push_front��Ч����ͬ
	// ������Զ�������Ԫ��
	// emplace_back/emplace_front��Ч�ʸ��ߣ�����������ֱ����β������ͷ������Ԫ��
	// push_back/push_front��Ч�ʵͣ��ò���ʱ�Ƚ�Ԫ�ع���ã�Ȼ�󿽱���β����ͷ��
	d1.emplace_back(6); //β��6
	d1.emplace_front(0); //ͷ��0
	PrintDeque(d1);

	// ��deque��beginλ�ò���Ԫ��0
	d1.insert(d1.begin(), 0);
	PrintDeque(d1);
	// ɾ��deque�ײ���β��Ԫ��
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