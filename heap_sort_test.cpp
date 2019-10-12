#include <stdio.h>
#include <stdlib.h>

void PrintArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}

	printf("\n");
}

void AdjustDown(int array[], int size, int root) {
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	while (left < size) {
		// 找两个孩子中大的一个
		// 只有一种情况，大的一个是右孩子
		// 有右孩子 并且 右孩子的值 > 左孩子的值
		int max = left;
		if (right < size && array[right] > array[left]) {
			max = right;
		}

		if (array[root] >= array[max]) {
			break;
		}

		int t = array[root]; array[root] = array[max]; array[max] = t;

		root = max;
		left = 2 * root + 1;
		right = 2 * root + 2;
	}

	// root 是 叶子了
}

void CreateHeap(int array[], int size) {
	// 从最后一个非叶子结点开始向下调整
	for (int i = (size - 2) / 2; i >= 0; i--) {
		AdjustDown(array, size, i);
	}
}

// 堆排序
// 时间复杂度 O(n * logn)
// 空间复杂度 O(1)
// 不稳定
// 数据不敏感的
void HeapSort(int array[], int size)
{
	// 建大堆
	CreateHeap(array, size);

	// 选择
	for (int i = 1; i < size; i++) {
		int t = array[0];
		array[0] = array[size - i];
		array[size - i] = t;

		AdjustDown(array, size - i, 0);	// O(logn)
	}
}


void Test_heap_sort()
{
	int arr[] = { 3, 9, 1, 4, 2, 8, 2, 7, 5, 3, 6, 11, 9, 4, 2, 5, 0, 6 };
	int size = sizeof(arr) / sizeof(int);
	HeapSort(arr, size);
	PrintArray(arr,size);
}

int main()
{   
	Test_heap_sort();
	system("pause");
	return 0;
}