#include <stdio.h>
#include <stdlib.h>

typedef struct Link
{
	int data;
	struct Link* next;
}link;

//创建链表
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

//插入元素
//num为插入元素,add为插入位置
link* InsertData(link* p,int num,int add)
{
	link* temp = p;
	//找到要插入的位置
	for (int i = 1; i < add; ++i)
	{
		temp = temp->next;
		if (temp == NULL)
		{
			printf("插入位置无效");
			return p;
		}
	}
	//创建插入节点C
	link* c = (link*)malloc(sizeof(link));

	c->data = num;
	//先链接后面，在连接前面
	c->next = temp->next;
	temp->next = c;
	return p;
}

//删除元素，将节点从链表中取下，再释放存储空间
link* DelData(link* p,int num)
{
	link* temp = p;
	for (int i = 1; i < num; ++i)
	{
		temp = temp->next;
		if (temp->next == NULL)
		{
			printf("没有该节点");
			return p;
		}
	}
	link* del = temp->next; //单独设置一个指针指向被删除节点，防止丢失
	temp->next = temp->next->next;
	free(del);
	return p;
}

//查找元素，遍历法
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

//更新元素
link* ChangeData(link* p,int add,int newdata)
{
	link* temp = p;
	temp = temp->next; //让temp指向首元节点
	
	//遍历更新节点
	for (int i = 1; i < add; ++i)
	{
		temp = temp->next;
	}
	temp->data = newdata;
	return p;
}

//打印
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

	//第4个位置插入5
	p = InsertData(p,5,4);
	Print(p);

	//删除元素3
	p= DelData(p,3);
	Print(p);

	//查找元素2的位置
	int add = findData(p,2);
	if (add == -1)
		printf("没有该元素");
	else
		printf("元素2的位置为：%d \n",add);

	//更改第3个位置上的数据为7
	p = ChangeData(p,3,7);
	Print(p);

	system("pause");
	return 0;
}