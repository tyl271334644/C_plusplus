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
		// �����������д��һ��
		// ֻ��һ����������һ�����Һ���
		// ���Һ��� ���� �Һ��ӵ�ֵ > ���ӵ�ֵ
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

	// root �� Ҷ����
}

void CreateHeap(int array[], int size) {
	// �����һ����Ҷ�ӽ�㿪ʼ���µ���
	for (int i = (size - 2) / 2; i >= 0; i--) {
		AdjustDown(array, size, i);
	}
}

// ������
// ʱ�临�Ӷ� O(n * logn)
// �ռ临�Ӷ� O(1)
// ���ȶ�
// ���ݲ����е�
void HeapSort(int array[], int size)
{
	// �����
	CreateHeap(array, size);

	// ѡ��
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