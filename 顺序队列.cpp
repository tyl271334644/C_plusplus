#include <stdio.h>
#include <stdlib.h>

#define max 5 //表示顺序表申请的空间大小
//入队
/*int enQueue(int* a, int rear, int data)
{
	a[rear] = data;
	rear++;
	return rear;
}

//出队
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
//存在问题：当所有元素出队后，front和rear位置重合志在a[4]位置
//而不在是a[0]，整个顺序队列在数据不断进队过程中，在顺序表中的位置不断后移
//顺序队列之前的数组存储空间将无法再被使用，造成空间浪费
//如果顺序表申请的空间不够大，则直接造成程序数组溢出

//将顺序表打造成环状表，在之前的代码上进行修改

//入队
int enQueue(int *a, int front,int rear, int data)
{
	//添加判断语句，如果rear超过max，则直接将其从a[0]重新开始存储
	//如果rear+1和front重合，则标识数组已满
	if ((rear + 1) % max == front)
	{
		printf("空间已满");
		return rear;
	}
	a[rear%max] = data;
	rear++;
	return rear;
}

//出队
int deQueue(int* a, int front, int rear)
{
	if (front == rear%max)
	{
		printf("队列为空\n");
		return rear;
	}
	printf("%d ", a[front]);
	//front不在直接+1，而是+1后与max比较，如果等于max，则直接跳到a[0]
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