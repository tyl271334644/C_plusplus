#include <stdio.h>
#include <stdlib.h>

#define max 5 //��ʾ˳�������Ŀռ��С
//���
/*int enQueue(int* a, int rear, int data)
{
	a[rear] = data;
	rear++;
	return rear;
}

//����
void deQueue(int* a, int front, int rear)
{
	while (front != rear)
	{
		printf("%d ", a[front]);
		front++;
	}
}
int main()
{
	int a[100];
	int front, rear;
	front = 0;
	rear = 0;
	rear = enQueue(a, rear, 1);
	rear = enQueue(a, rear, 2);
	rear = enQueue(a, rear, 3);
	rear = enQueue(a, rear, 4);

	deQueue(a, front, rear);
	system("pause");
	return 0;
}*/
//�������⣺������Ԫ�س��Ӻ�front��rearλ���غ�־��a[4]λ��
//��������a[0]������˳����������ݲ��Ͻ��ӹ����У���˳����е�λ�ò��Ϻ���
//˳�����֮ǰ������洢�ռ佫�޷��ٱ�ʹ�ã���ɿռ��˷�
//���˳�������Ŀռ䲻������ֱ����ɳ����������

//��˳������ɻ�״����֮ǰ�Ĵ����Ͻ����޸�

//���
int enQueue(int *a, int front,int rear, int data)
{
	//����ж���䣬���rear����max����ֱ�ӽ����a[0]���¿�ʼ�洢
	//���rear+1��front�غϣ����ʶ��������
	if ((rear + 1) % max == front)
	{
		printf("�ռ�����");
		return rear;
	}
	a[rear%max] = data;
	rear++;
	return rear;
}

//����
int deQueue(int* a, int front, int rear)
{
	if (front == rear%max)
	{
		printf("����Ϊ��\n");
		return rear;
	}
	printf("%d ", a[front]);
	//front����ֱ��+1������+1����max�Ƚϣ��������max����ֱ������a[0]
	front = (front + 1 )% max;
	return front;
}

int main()
{
	int a[max];
	int front, rear;
	front = rear = 0;
	rear = enQueue(a, front, rear, 1);
	rear = enQueue(a, front, rear, 2);
	rear = enQueue(a, front, rear, 3);
	rear = enQueue(a, front, rear, 4);

	front = deQueue(a, front, rear);

	rear = enQueue(a, front, rear, 5);

	front = deQueue(a, front, rear);

	front = deQueue(a, front, rear);
	front = deQueue(a, front, rear);
	front = deQueue(a, front, rear);
	front = deQueue(a, front, rear);

	system("pause");
	return 0;
}