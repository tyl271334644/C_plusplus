#include <stdio.h>
#include <stdlib.h>

typedef struct QNode
{
	int data;
	struct QNode* next;
}QNode;

QNode* InitQueue()
{
	//����һ��ͷ���
	QNode* queue = (QNode*)malloc(sizeof(QNode));
	//��ͷ����ʼ��
	queue->next = NULL;
	return queue;
}

//���
QNode* enQueue(QNode* rear, int data)
{
	//�ýڵ�������Ԫ��
	QNode* temp = (QNode*)malloc(sizeof(QNode));
	temp->data = data;
	temp->next = NULL;

	//�½ڵ���rear�ڵ㽨������
	rear->next = temp;
	//raerָ���½ڵ�
	rear = temp;
	return rear;
}

//����
QNode* DelQueue(QNode* top, QNode* rear)
{
	if (top->next == NULL)
	{
		printf("����Ϊ��\n");
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
	queue = top = rear = InitQueue();//����ͷ���
	//������������ӽ�㣬ʹ��β�巨��ӵ�ͬʱ����βָ����Ҫָ����������һ��Ԫ��
	rear = enQueue(rear, 1);
	rear = enQueue(rear, 2);
	rear = enQueue(rear, 3);
	rear = enQueue(rear, 4);
	//�����ɣ���������Ԫ�ؿ�ʼ������
	rear = DelQueue(top, rear);
	rear = DelQueue(top, rear);
	rear = DelQueue(top, rear);
	rear = DelQueue(top, rear);

	rear = DelQueue(top, rear);
	system("pause");
	return 0;
}