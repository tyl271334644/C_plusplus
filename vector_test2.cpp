#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;


int main()
{

////////////////////////////////////////////////////////
	//int a[] = { 1, 2, 3, 4 };
	//vector<int>v(a, a + sizeof(a) / sizeof(int));
	////使用find查找3所在位置的iterator
	//vector<int>::iterator pos = find(v.begin(),v.end(),3);
	////删除pos位置处的数据，导致pos迭代器失效
	//v.erase(pos);
	//
	//
	//// 在pos位置插入数据，导致pos迭代器失效。
	//// insert会导致迭代器失效，是因为insert可
	//// 能会导致增容，增容后pos还指向原来的空间，而原来的空间已经释放了
	//pos = find(v.begin(), v.end(), 3);
	//v.insert(pos, 4);
	//cout << *pos << endl;

//////////////////////////////////////////////////////
	//int a[] = {1,2,3,4};
	//vector<int> v(a, a + sizeof(a) / sizeof(int));
	////通过[]读取第0个位置，并赋值为10
	//v[0] = 10;
	//cout << v[0] << endl;
	////通过[i]的方式遍历vector 内容为10 2 3 4
	//for (size_t i = 0; i < v.size(); ++i)
	//{
	//	cout << v[i] <<" ";
	//}
	//cout << endl;
	////创建v2容器 内容为5 6 7 8
	//int b[] = { 5, 6, 7, 8 };
	//vector<int> v2(b, b + sizeof(b) / sizeof(int));

	////v2与v中元素进行交换
	//v2.swap(v);
	//cout << "v_swap data:";  //内容为 5 6 7 8
	//for (size_t i = 0; i < v.size(); ++i)
	//{
	//	cout << v[i] <<" ";
	//}
	//cout << endl;

	//cout << "v2_swap data:"; //内容为 10 2 3 4
	//for (size_t i = 0; i < v2.size(); ++i)
	//{
	//	cout << v2[i] << " ";
	//}
	//cout << endl;

	////c++11支持的新式遍历v中元素
	//cout << "C++11:";
	//for (auto x : v)
	//{
	//	cout << x << " ";
	//}
	//cout << endl;
///////////////////////////////////////////////////////
	//int a[] = {1,2,3,4,5,6};
	//vector<int> v(a, a + sizeof(a) / sizeof(int));
	////使用find在[begin,end)区域内寻找3的位置
	//vector<int>::iterator i = find(v.begin(),v.end(),3);
	////在3位置之前插入数字30
	//v.insert(i, 30);

	//vector<int>::iterator it = v.begin();
	//while (it != v.end())
	//{
	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;
	////寻找4的位置并删除
	//i = find(v.begin(), v.end(), 4);
	//v.erase(i);

	//it = v.begin();
	//while (it != v.end())
	//{
	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;
///////////////////////////////////////////////////////////////
	/*int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	vector<int>::iterator i = v.begin();
	while (i != v.end())
	{
		cout << *i << " ";
		++i;
	}
	cout << endl;

	v.pop_back();
	v.pop_back();
	v.push_back(6);
	i = v.begin();
	while (i != v.end())
	{
		cout << *i << " ";
		++i;
	}
	cout << endl;*/
	system("pause");
	return 0;
}