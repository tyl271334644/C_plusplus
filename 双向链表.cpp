#include <stdio.h>
#include <stdlib.h>

typedef struct line
{
	struct line* prv;
	int data;
	struct line* next;
};

//双向链表的创建
line* InitLine(line* head)
{
	head = (line*)malloc(sizeof(line));//创建链表第一个节点（首元节点）
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
//双向链表的插入
//插入一半为三种插入，头插，中间插入，尾插
//头插 ，只需要将该元素与表头元素建立双层逻辑关系即可
line* Init_begin(line* head,int data)
{
	//创建新的节点
	line* temp = (line*)malloc(sizeof(line));
	temp->data = data;
	temp->prv = NULL;
	temp->next = NULL;
	//如果为空链表
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

//中间插入，1新节点先与其直接后继节点建立双层逻辑关系；
//         2新节点的直接前驱节点与之建立双层逻辑关系；
line* Init_body(line* head,int data,int add)
{
	line * temp = (line*)malloc(sizeof(line));
	temp->data = data;
	temp->prv = NULL;
	temp->next = NULL;

	line* body = head;
	//找到要插入的位置的前一个节点
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

//尾插，需要将该元素与表尾元素建立双层逻辑关系即可
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

//节点删除
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
	printf("链表中无该元素");
	return head;
}

//查找节点

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

//更改节点
line* ChangeLine(line* head,int add,int newData)
{
	line* temp = head;
	//遍历到被删除节点
	for (int i = 1; i < add; ++i)
	{
		temp = temp->next;
	}
	temp->data = newData;
	return head;
}
//打印
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
	//头插
	head = Init_begin(head, 7);
	head = Init_begin(head, 8);
	head = Init_begin(head, 9);
	Print(head);
	//添加5到第6个位置
	head = Init_body(head, 5,6);
	head = Init_body(head, 8, 7);
	Print(head);
	//尾插元素10,11,12
	head = Init_end(head,10);
	head = Init_end(head, 11);
	head = Init_end(head, 12);
	Print(head);

	//删除节点2,3
	head=DelLine(head,2);
	head=DelLine(head,3);
	Print(head);
	
	//更改第3个节点的数据为20
	ChangeLine(head, 3, 20);
	Print(head);
	//查找节点为8的下标
	int num = FindLine(head, 8);
	if (num == -1)
		printf("没有该元素");
	else
		printf("所要查找的元素下标为: %d\n", num);

	system("pause");
	return 0;
}