#include <stdio.h>
#include <stdlib.h>

typedef struct Link
{
	int data;
	struct Link* next;
}link;

//��������
link* InitLink()
{
	link* p = (link*)malloc(sizeof(link));
	link* temp = p;
	for (int i = 1; i < 6; ++i)
	{
		link* a = (link*)malloc(sizeof(link));
		a->data = i;
		a->next = NULL;

		temp->next = a;
		temp = temp->next;
	}
	return p;
}

//����Ԫ��
//numΪ����Ԫ��,addΪ����λ��
link* InsertData(link* p,int num,int add)
{
	link* temp = p;
	//�ҵ�Ҫ�����λ��
	for (int i = 1; i < add; ++i)
	{
		temp = temp->next;
		if (temp == NULL)
		{
			printf("����λ����Ч");
			return p;
		}
	}
	//��������ڵ�C
	link* c = (link*)malloc(sizeof(link));

	c->data = num;
	//�����Ӻ��棬������ǰ��
	c->next = temp->next;
	temp->next = c;
	return p;
}

//ɾ��Ԫ�أ����ڵ��������ȡ�£����ͷŴ洢�ռ�
link* DelData(link* p,int num)
{
	link* temp = p;
	for (int i = 1; i < num; ++i)
	{
		temp = temp->next;
		if (temp->next == NULL)
		{
			printf("û�иýڵ�");
			return p;
		}
	}
	link* del = temp->next; //��������һ��ָ��ָ��ɾ���ڵ㣬��ֹ��ʧ
	temp->next = temp->next->next;
	free(del);
	return p;
}

//����Ԫ�أ�������
int findData(link* p,int num)
{
	link *t = p;
	int i = 1;
	while (t->next)
	{
		t = t->next;
		if (t->data==num)
		{
			return i;
		}
		i++;
	}
	return -1;
}

//����Ԫ��
link* ChangeData(link* p,int add,int newdata)
{
	link* temp = p;
	temp = temp->next; //��tempָ����Ԫ�ڵ�
	
	//�������½ڵ�
	for (int i = 1; i < add; ++i)
	{
		temp = temp->next;
	}
	temp->data = newdata;
	return p;
}

//��ӡ
void  Print(link* p)
{
	link* temp = p;
	while (temp->next)
	{
		temp = temp->next;
		printf("%d ",temp->data);
	}
	printf("\n");
}
int main()
{
	link* p = InitLink();
	Print(p);

	//��4��λ�ò���5
	p = InsertData(p,5,4);
	Print(p);

	//ɾ��Ԫ��3
	p= DelData(p,3);
	Print(p);

	//����Ԫ��2��λ��
	int add = findData(p,2);
	if (add == -1)
		printf("û�и�Ԫ��");
	else
		printf("Ԫ��2��λ��Ϊ��%d \n",add);

	//���ĵ�3��λ���ϵ�����Ϊ7
	p = ChangeData(p,3,7);
	Print(p);

	system("pause");
	return 0;
}