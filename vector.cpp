#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;
//template <class T>
//void PrintVector(const vector<T> &v)
//{
//	vector<T>::const_iterator i;
//	for (i = v.begin(); i != v.end(); ++i)
//	{
//		cout << *i << "";
//	}
//	cout << endl;
//}
int main()
{
	vector<vector<int> >v(3);
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			v[i].push_back(j);
		}
	}
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[i].size(); ++j)
		{
			cout << v[i][j] << " ";
		}
		cout <<endl;
	}
/////////////////////////////////////////////////////////////
	/*int a[5] = { 1, 2, 3, 4, 5 };
	vector<int> v(a, a + 5);
	cout << "1) " << v.end() - v.begin() << endl;
	cout << "2)";PrintVector(v);
	v.insert(v.begin() + 2, 13);
	cout << "3)"; PrintVector(v);
	v.erase(v.begin() + 2);
	cout << "4)"; PrintVector(v);
	

	vector<int> v2(4, 100);
	v2.insert(v2.begin(), v.begin() + 1, v.begin() + 3);
	cout << "5)v2:"; PrintVector(v2);
	v.erase(v.begin() + 1, v.begin() + 3);
	cout << "6)"; PrintVector(v);
*/
/////////////////////////////////////////////////////
	/*vector<int> v(100);
	for (int n = 0; n < 100; ++n)
	{
		v.push_back(n);
	}
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i];
	}
	vector<int>::iterator i;
	for (i = v.begin(); i != v.end(); ++i)
	{
		cout << *i;
	}
	for (i = v.begin(); i < v.end(); ++i)
	{
		cout << *i;
	}
	i = v.begin();
	while (i <v.end())
	{
		cout << *i;
		i += 2;
	}*/

///////////////////////////////////////////////////////////
	/*vector<int> v;
	for (int n = 0; n < 5; ++n)
	{
		v.push_back(n);
	}
	vector<int>::iterator i;
	for (i = v.begin(); i != v.end(); ++i)
	{
		cout << *i << " ";
		*i *= 2;
	}
	cout << endl;
	for (vector<int>::reverse_iterator j = v.rbegin(); j != v.rend(); ++j)
	{
		cout << *j << " ";
	}*/
	
	system("pause");
	return 0;
}