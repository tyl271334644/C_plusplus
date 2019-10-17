#include <stdio.h>
#include <stdlib.h>

typedef struct QNode
{
	int data;
	struct QNode* next;
}QNode;

QNode* InitQueue()
{
	//创建一个头结点
	QNode* queue = (QNode*)malloc(sizeof(QNode));
	//对头结点初始化
	queue->next = NULL;
	return queue;
}

//入队
QNode* enQueue(QNode* rear, int data)
{
	//用节点包裹入队元素
	QNode* temp = (QNode*)malloc(sizeof(QNode));
	temp->data = data;
	temp->next = NULL;

	//新节点与rear节点建立连接
	rear->next = temp;
	//raer指向新节点
	rear = temp;
	return rear;
}

//出队
QNode* DelQueue(QNode* top, QNode* rear)
{
	if (top->next == NULL)
	{
		printf("队列为空\n");
		return rear;
	}
	QNode* p = top->next;
	printf("%d ", p->data);
	top->next = p->next;
	if (rear == p)
	{
		rear = top;
	}
	free(p);
}

int main()
{
	QNode* queue, *top, *rear;
	queue = top = rear = InitQueue();//创建头结点
	//向链队列中添加结点，使用尾插法添加的同时，队尾指针需要指向链表的最后一个元素
	rear = enQueue(rear, 1);
	rear = enQueue(rear, 2);
	rear = enQueue(rear, 3);
	rear = enQueue(rear, 4);
	//入队完成，所有数据元素开始出队列
	rear = DelQueue(top, rear);
	rear = DelQueue(top, rear);
	rear = DelQueue(top, rear);
	rear = DelQueue(top, rear);

	rear = DelQueue(top, rear);
	system("pause");
	return 0;
}