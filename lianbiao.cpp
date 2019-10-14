#include <stdio.h>
#include <stdlib.h>

typedef  struct Link
{
	char data;
	struct Link* next;
}link;

//创建一个无头节点的链表
link* InitLink()
{
	link* p = NULL; //创建头指针
	link* temp = (link*)malloc(sizeof(link)); //创建首元节点
	//首元节点初始化
	temp->data = 1;
	temp->next = NULL;
	p = temp; //头指针指向首元节点

	//从第二个节点开始创建
	for (int i = 2; i < 6; ++i)
	{
		link* a = (link*)malloc(sizeof(link));
		a->data = i;
		a->next = NULL;

		//将temp节点新建立的的节点建立逻辑关系
		temp->next = a;
		//指针temp每次都指向新链表的最后一个节点
		temp = temp->next;
	}
	return p;
}

//创建一个有头结点的链表
link* InitLink_head()
{
	link* p = (link*)malloc(sizeof(link));
	link* temp = p; //声明一个指针指向头结点
	for (int i = 1; i < 6; ++i)
	{
		link *a = (link*)malloc(sizeof(link));
		a->data = i;
		a->next = NULL;
		temp->next = a;
		temp = temp->next;
	}
	return p;
}

//无头节点打印
void Print(link* p)
{
	link* temp = p;
	while (temp)
	{
		printf("%d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
//有头结点打印
void Print_head(link* p)
{
	link* temp = p;
	while (temp->next)
	{
		temp = temp->next;
		printf("%d",temp->data);
	}
	printf("\n");
}
int main()
{ 
	link* p = InitLink();
	Print(p);
	link* p1 = InitLink_head();
	Print_head(p1);
	system("pause");
	return 0;
}