#include <iostream>
#include <stdlib.h>


using namespace std;
//选择排序
void select_sort(int arr[], int len)
{
	int min, temp;
	for (int i = 0; i < len-1; ++i)
	{
		 min = i;  //假设最小值为i
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

//插入排序
void insert_sort(int arr[],int len)
{
	int temp,j;
	for (int i = 1; i < len; ++i)
	{
		temp = arr[i];
		//1得到要插入的数据
		for ( j = i - 1; j >= 0 && arr[j]>temp; --j)
		{
			arr[j + 1] = arr[j];
		}
		//2把要插入数据之前的数组中需要移动的部分后移一个下班
		arr[j + 1] = temp;
		//3赋值
	}
}

//希尔排序
void shell_sort(int arr[],int len)
{
	int j, temp;
	int step_len = len / 2;
	while (step_len >= 1)
	{
		for (int i = step_len; i < len; ++i) //插入排序的思想
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

//快速排序
void Quick_sort(int arr[], int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int begin = left;
	int end = right;
	int key = arr[left];

	while (begin < end)                               /*控制在当组内寻找一遍*/
	{
		while (begin < end && key <= arr[end])
			/*而寻找结束的条件就是，1，找到一个小于或者大于key的数（大于或小于取决于你想升
			序还是降序）2，没有符合条件1的，并且i与j的大小没有反转*/
		{
			end--;/*向前寻找*/
		}

		arr[begin] = arr[end];
		/*找到一个这样的数后就把它赋给前面的被拿走的i的值（如果第一次循环且key是
		a[left]，那么就是给key）*/

		while (begin< end && key >= arr[begin])
			/*这是i在当组内向前寻找，同上，不过注意与key的大小关系停止循环和上面相反，
			因为排序思想是把数往两边扔，所以左右两边的数大小与key的关系相反*/
		{
			begin++;
		}

		arr[end] = arr[begin];
	}

	arr[begin] = key;
	Quick_sort(arr, left, begin - 1);
	Quick_sort(arr, begin + 1, right);
	
}

//冒泡排序
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