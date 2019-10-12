#include <iostream>
#include <stdlib.h>


using namespace std;
//ѡ������
void select_sort(int arr[], int len)
{
	int min, temp;
	for (int i = 0; i < len-1; ++i)
	{
		 min = i;  //������СֵΪi
		for (int j = i + 1; j < len; ++j)
		{
			if (arr[j] < arr[min])
				min = j;
		}
		if (min != i)
		{
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}

}

//��������
void insert_sort(int arr[],int len)
{
	int temp,j;
	for (int i = 1; i < len; ++i)
	{
		temp = arr[i];
		//1�õ�Ҫ���������
		for ( j = i - 1; j >= 0 && arr[j]>temp; --j)
		{
			arr[j + 1] = arr[j];
		}
		//2��Ҫ��������֮ǰ����������Ҫ�ƶ��Ĳ��ֺ���һ���°�
		arr[j + 1] = temp;
		//3��ֵ
	}
}

//ϣ������
void shell_sort(int arr[],int len)
{
	int j, temp;
	int step_len = len / 2;
	while (step_len >= 1)
	{
		for (int i = step_len; i < len; ++i) //���������˼��
		{
			temp = arr[i];
			for (j = i - step_len; j >= 0 && arr[j]>temp; j -= step_len)
			{
				arr[j + step_len] = arr[j];
			}
			arr[j + step_len] = temp;
		}
		step_len /= 2;
	}
}

//��������
void Quick_sort(int arr[], int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int begin = left;
	int end = right;
	int key = arr[left];

	while (begin < end)                               /*�����ڵ�����Ѱ��һ��*/
	{
		while (begin < end && key <= arr[end])
			/*��Ѱ�ҽ������������ǣ�1���ҵ�һ��С�ڻ��ߴ���key���������ڻ�С��ȡ����������
			���ǽ���2��û�з�������1�ģ�����i��j�Ĵ�Сû�з�ת*/
		{
			end--;/*��ǰѰ��*/
		}

		arr[begin] = arr[end];
		/*�ҵ�һ������������Ͱ�������ǰ��ı����ߵ�i��ֵ�������һ��ѭ����key��
		a[left]����ô���Ǹ�key��*/

		while (begin< end && key >= arr[begin])
			/*����i�ڵ�������ǰѰ�ң�ͬ�ϣ�����ע����key�Ĵ�С��ϵֹͣѭ���������෴��
			��Ϊ����˼���ǰ����������ӣ������������ߵ�����С��key�Ĺ�ϵ�෴*/
		{
			begin++;
		}

		arr[end] = arr[begin];
	}

	arr[begin] = key;
	Quick_sort(arr, left, begin - 1);
	Quick_sort(arr, begin + 1, right);
	
}

//ð������
void buble_sort(int arr[],int len)
{
	int temp;
	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = 0; j < len - i - 1; ++j)
		{
			if (arr[j]>arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int main()
{
	int arr[] = { 1, 2, 3, 2, 4, 5, 1, 23, 5, 6, 7, 3, 45, 34 };
	int size = sizeof(arr) / sizeof(int);
	//Quick_sort(arr, 0, size - 1);
	buble_sort(arr, size);
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}

	system("pause");
	return 0;
}