#include <stdio.h>
#include <stdlib.h>

typedef struct line
{
	struct line* prv;
	int data;
	struct line* next;
};

//˫������Ĵ���
line* InitLine(line* head)
{
	head = (line*)malloc(sizeof(line));//���������һ���ڵ㣨��Ԫ�ڵ㣩
	head->prv = NULL;
	head->next = NULL;
	head->data = 1;
	line* list = head;
	for (int i = 2; i < 6; ++i)
	{
		line* body = (line*)malloc(sizeof(line));
		body->prv = NULL;
		body->next = NULL;
		body->data = i;

		list->next = body;
		body->prv = list;
		list = list->next;
	}
	return head;
}
//˫������Ĳ���
//����һ��Ϊ���ֲ��룬ͷ�壬�м���룬β��
//ͷ�� ��ֻ��Ҫ����Ԫ�����ͷԪ�ؽ���˫���߼���ϵ����
line* Init_begin(line* head,int data)
{
	//�����µĽڵ�
	line* temp = (line*)malloc(sizeof(line));
	temp->data = data;
	temp->prv = NULL;
	temp->next = NULL;
	//���Ϊ������
	if (head->next==NULL)
	{
		temp->next = NULL;
		temp->prv = NULL;
		head->next= temp;
	}
	else
	{
		temp->next = head;
		head->prv = temp;
		head = temp;
	}
	return head;
}

//�м���룬1�½ڵ�������ֱ�Ӻ�̽ڵ㽨��˫���߼���ϵ��
//         2�½ڵ��ֱ��ǰ���ڵ���֮����˫���߼���ϵ��
line* Init_body(line* head,int data,int add)
{
	line * temp = (line*)malloc(sizeof(line));
	temp->data = data;
	temp->prv = NULL;
	temp->next = NULL;

	line* body = head;
	//�ҵ�Ҫ�����λ�õ�ǰһ���ڵ�
	for (int i = 1; i < add - 1; i++)
	{
		body = body->next;
	}
	body->next->prv = temp;
	temp->next = body->next;
	body->next = temp;
	temp->prv = body;

	return head;
}

//β�壬��Ҫ����Ԫ�����βԪ�ؽ���˫���߼���ϵ����
line* Init_end(line* head,int data)
{
	line* temp = (line*)malloc(sizeof(line));
	temp->data = data;
	temp->prv = NULL;
	temp->next = NULL;

	line* body = head;
	for (int i = 1; i < data; i++)
	{
		body = body->next;
	}
	if (body->next == NULL)
	{
		body->next = temp;
		temp->prv = body;
	}
	return head;
}

//�ڵ�ɾ��
line* DelLine(line* head,int data)
{
	line* temp = head;
	while (temp)
	{
		if (temp->data == data)
		{
			temp->prv->next = temp->next;
			temp->next->prv = temp->prv;
			free(temp);
			return head;
		}
		temp = temp->next;
	}
	printf("�������޸�Ԫ��");
	return head;
}

//���ҽڵ�

int  FindLine(line* head,int data)
{
	line* t = head;
	int i = 1;
	while (t)
	{
		if (t->data == data)
		{
			return i;
		}
		i++;
		t = t->next;
	}
	return -1;
}

//���Ľڵ�
line* ChangeLine(line* head,int add,int newData)
{
	line* temp = head;
	//��������ɾ���ڵ�
	for (int i = 1; i < add; ++i)
	{
		temp = temp->next;
	}
	temp->data = newData;
	return head;
}
//��ӡ
void Print(line* head)
{
	line* temp = head;
	while (temp)
	{
		if (temp->next == NULL)
		{
			printf("%d\n", temp->data);
		}
		else
		{
			printf("%d <->", temp->data);
		}
		temp = temp -> next;
	}
}


int main()
{
	line* head = NULL;
	head = InitLine(head);
	Print(head);
	//ͷ��
	head = Init_begin(head, 7);
	head = Init_begin(head, 8);
	head = Init_begin(head, 9);
	Print(head);
	//���5����6��λ��
	head = Init_body(head, 5,6);
	head = Init_body(head, 8, 7);
	Print(head);
	//β��Ԫ��10,11,12
	head = Init_end(head,10);
	head = Init_end(head, 11);
	head = Init_end(head, 12);
	Print(head);

	//ɾ���ڵ�2,3
	head=DelLine(head,2);
	head=DelLine(head,3);
	Print(head);
	
	//���ĵ�3���ڵ������Ϊ20
	ChangeLine(head, 3, 20);
	Print(head);
	//���ҽڵ�Ϊ8���±�
	int num = FindLine(head, 8);
	if (num == -1)
		printf("û�и�Ԫ��");
	else
		printf("��Ҫ���ҵ�Ԫ���±�Ϊ: %d\n", num);

	system("pause");
	return 0;
}