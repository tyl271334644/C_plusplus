#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
}linklist;

//��ʼ��
linklist* Init_head(void)
{
	linklist* head = NULL;
	head = (linklist*)malloc(sizeof(linklist));
	if (head == NULL)
	{
		printf("����ռ�ʧ��");
		return NULL;
	}
	head->data = -1;
	head->next = NULL;
	return head;
}
//����
void Creat_list(linklist* head)
{
	linklist* pnew = NULL;
	linklist* pcur = head;

	int input = 0;
	scanf("&d",&input);
	while (input != -1)
	{
		pnew = (linklist*)malloc(sizeof(linklist));
		pnew->data = input;
		pnew-> next = NULL;

		pcur->next = pnew;
		pnew->next = head;
		pcur = pnew;
		scanf("&d", &input);
	}
}
//����
void Traverse(linklist* head)
{
	linklist* pcur = head->next;
	while (pcur != NULL)
	{
		printf("%d",pcur->data);
		pcur = pcur ->next;
	}
	putchar(10);
}
int main()
{
	linklist* head = Init_head();
	Creat_list(head);
	Traverse(head);
	system("pause");
	return 0;
}