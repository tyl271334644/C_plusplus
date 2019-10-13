#include <stdio.h>
#include <stdlib.h>

#define Size  10

typedef struct Table
{
	int * head;
	int len;
	int size;
}table;
//num为插入的数字,add为插入的位置
table AddTable(table t, int num, int add)
{
	//判断插入本身是否存在问题（如果插入元素位置比整张表的长度+1还大
	//（如果相等，是尾随的情况）
	//或者插入的位置本身不存在，程序作为提示并自动退出）
	if (add > t.len + 1 || add < 1)
	{
		printf("插入位置有误");
		return t;
	}
	if (t.len == t.size)
	{
		//做插入操作时，首先需要看顺序表是否有多余的存储空间提供给插入的元素，
		//如果没有，需要申请
		//动态数组额外申请更多物理空间使用的是 realloc 函数。
	    //并且，在实现后续元素整体后移的过程，
		//目标位置其实是有数据的，只是下一步新插入元素时会把旧元素直接覆盖。
		t.head = (int*)realloc(t.head, (t.size + 1)*sizeof(int));
		if (!t.head)
		{
			printf("申请失败");
			return t;
		}
		t.size += 1;
	}
	//插入操作，需要将从插入位置开始的后序元素，逐个后移
	for (int i = t.len - 1; i >= add - 1; --i)
	{
		t.head[i + 1] = t.head[i];
	}
	t.head[add - 1] = num;
	t.len++;
	return t;
}

//删除元素
table delTable(table t,int add)
{
	if (add > t.len || add < 1)
	{
		printf("删除位置有误");
		return t;
	}
	for (int i = add; i < t.len; ++i)
	{
		t.head[i - 1] = t.head[i];
	}
	t.len--;
	return t;
}

//初始化顺序表
table initTable()
{
	table t;
	t.head = (int*)malloc(Size*sizeof(int));
	if (!t.head)
	{
		printf("初始化失败！");
		exit(0);
	}
	t.len = 0;
	t.size = Size;
	return t;
}
//打印输出
void Print(table t)
{
	for (int i = 0; i < t.len; ++i)
	{
		printf("%d ",t.head[i]);
	}
	printf("\n");
}

//查找元素

int  findTable(table t, int num)
{
	for (int i = 0; i < t.len; ++i)
	{
		if (t.head[i] == num)
		{
			return i + 1;
		}
	}
	return -1;//查找失败
}

//更改元素
table ChangeTable(table t, int num, int newnum)
{
	int add = findTable(t, num);
	t.head[add - 1] = newnum;
	return t;
}

int main()
{
	table t = initTable();
	
	for (int i =1; i <= Size; ++i)
	{
		t.head[i-1] = i;
		t.len++;
	}
	Print(t);
	//第五个位置插入1
	AddTable(t, 1, 5);
	Print(t);
	//删除第四个位置元素
	delTable(t,4);
	Print(t);

	int add = findTable(t, 6);
	printf("%d\n",add);
	//将元素2改为4
	t = ChangeTable(t, 2, 4);
	Print(t);
	system("pause");
	return 0;
}