#include <stdio.h>
#include <stdlib.h>

typedef  struct Link
{
	char data;
	struct Link* next;
}link;

//����һ����ͷ�ڵ������
link* InitLink()
{
	link* p = NULL; //����ͷָ��
	link* temp = (link*)malloc(sizeof(link)); //������Ԫ�ڵ�
	//��Ԫ�ڵ��ʼ��
	temp->data = 1;
	temp->next = NULL;
	p = temp; //ͷָ��ָ����Ԫ�ڵ�

	//�ӵڶ����ڵ㿪ʼ����
	for (int i = 2; i < 6; ++i)
	{
		link* a = (link*)malloc(sizeof(link));
		a->data = i;
		a->next = NULL;

		//��temp�ڵ��½����ĵĽڵ㽨���߼���ϵ
		temp->next = a;
		//ָ��tempÿ�ζ�ָ������������һ���ڵ�
		temp = temp->next;
	}
	return p;
}

//����һ����ͷ��������
link* InitLink_head()
{
	link* p = (link*)malloc(sizeof(link));
	link* temp = p; //����һ��ָ��ָ��ͷ���
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

//��ͷ�ڵ��ӡ
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
//��ͷ����ӡ
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