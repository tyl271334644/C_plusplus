#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;


int main()
{

////////////////////////////////////////////////////////
	//int a[] = { 1, 2, 3, 4 };
	//vector<int>v(a, a + sizeof(a) / sizeof(int));
	////ʹ��find����3����λ�õ�iterator
	//vector<int>::iterator pos = find(v.begin(),v.end(),3);
	////ɾ��posλ�ô������ݣ�����pos������ʧЧ
	//v.erase(pos);
	//
	//
	//// ��posλ�ò������ݣ�����pos������ʧЧ��
	//// insert�ᵼ�µ�����ʧЧ������Ϊinsert��
	//// �ܻᵼ�����ݣ����ݺ�pos��ָ��ԭ���Ŀռ䣬��ԭ���Ŀռ��Ѿ��ͷ���
	//pos = find(v.begin(), v.end(), 3);
	//v.insert(pos, 4);
	//cout << *pos << endl;

//////////////////////////////////////////////////////
	//int a[] = {1,2,3,4};
	//vector<int> v(a, a + sizeof(a) / sizeof(int));
	////ͨ��[]��ȡ��0��λ�ã�����ֵΪ10
	//v[0] = 10;
	//cout << v[0] << endl;
	////ͨ��[i]�ķ�ʽ����vector ����Ϊ10 2 3 4
	//for (size_t i = 0; i < v.size(); ++i)
	//{
	//	cout << v[i] <<" ";
	//}
	//cout << endl;
	////����v2���� ����Ϊ5 6 7 8
	//int b[] = { 5, 6, 7, 8 };
	//vector<int> v2(b, b + sizeof(b) / sizeof(int));

	////v2��v��Ԫ�ؽ��н���
	//v2.swap(v);
	//cout << "v_swap data:";  //����Ϊ 5 6 7 8
	//for (size_t i = 0; i < v.size(); ++i)
	//{
	//	cout << v[i] <<" ";
	//}
	//cout << endl;

	//cout << "v2_swap data:"; //����Ϊ 10 2 3 4
	//for (size_t i = 0; i < v2.size(); ++i)
	//{
	//	cout << v2[i] << " ";
	//}
	//cout << endl;

	////c++11֧�ֵ���ʽ����v��Ԫ��
	//cout << "C++11:";
	//for (auto x : v)
	//{
	//	cout << x << " ";
	//}
	//cout << endl;
///////////////////////////////////////////////////////
	//int a[] = {1,2,3,4,5,6};
	//vector<int> v(a, a + sizeof(a) / sizeof(int));
	////ʹ��find��[begin,end)������Ѱ��3��λ��
	//vector<int>::iterator i = find(v.begin(),v.end(),3);
	////��3λ��֮ǰ��������30
	//v.insert(i, 30);

	//vector<int>::iterator it = v.begin();
	//while (it != v.end())
	//{
	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;
	////Ѱ��4��λ�ò�ɾ��
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