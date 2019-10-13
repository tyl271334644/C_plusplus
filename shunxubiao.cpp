#include <stdio.h>
#include <stdlib.h>

#define Size  10

typedef struct Table
{
	int * head;
	int len;
	int size;
}table;
//numΪ���������,addΪ�����λ��
table AddTable(table t, int num, int add)
{
	//�жϲ��뱾���Ƿ�������⣨�������Ԫ��λ�ñ����ű�ĳ���+1����
	//�������ȣ���β��������
	//���߲����λ�ñ������ڣ�������Ϊ��ʾ���Զ��˳���
	if (add > t.len + 1 || add < 1)
	{
		printf("����λ������");
		return t;
	}
	if (t.len == t.size)
	{
		//���������ʱ��������Ҫ��˳����Ƿ��ж���Ĵ洢�ռ��ṩ�������Ԫ�أ�
		//���û�У���Ҫ����
		//��̬������������������ռ�ʹ�õ��� realloc ������
	    //���ң���ʵ�ֺ���Ԫ��������ƵĹ��̣�
		//Ŀ��λ����ʵ�������ݵģ�ֻ����һ���²���Ԫ��ʱ��Ѿ�Ԫ��ֱ�Ӹ��ǡ�
		t.head = (int*)realloc(t.head, (t.size + 1)*sizeof(int));
		if (!t.head)
		{
			printf("����ʧ��");
			return t;
		}
		t.size += 1;
	}
	//�����������Ҫ���Ӳ���λ�ÿ�ʼ�ĺ���Ԫ�أ��������
	for (int i = t.len - 1; i >= add - 1; --i)
	{
		t.head[i + 1] = t.head[i];
	}
	t.head[add - 1] = num;
	t.len++;
	return t;
}

//ɾ��Ԫ��
table delTable(table t,int add)
{
	if (add > t.len || add < 1)
	{
		printf("ɾ��λ������");
		return t;
	}
	for (int i = add; i < t.len; ++i)
	{
		t.head[i - 1] = t.head[i];
	}
	t.len--;
	return t;
}

//��ʼ��˳���
table initTable()
{
	table t;
	t.head = (int*)malloc(Size*sizeof(int));
	if (!t.head)
	{
		printf("��ʼ��ʧ�ܣ�");
		exit(0);
	}
	t.len = 0;
	t.size = Size;
	return t;
}
//��ӡ���
void Print(table t)
{
	for (int i = 0; i < t.len; ++i)
	{
		printf("%d ",t.head[i]);
	}
	printf("\n");
}

//����Ԫ��

int  findTable(table t, int num)
{
	for (int i = 0; i < t.len; ++i)
	{
		if (t.head[i] == num)
		{
			return i + 1;
		}
	}
	return -1;//����ʧ��
}

//����Ԫ��
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
	//�����λ�ò���1
	AddTable(t, 1, 5);
	Print(t);
	//ɾ�����ĸ�λ��Ԫ��
	delTable(t,4);
	Print(t);

	int add = findTable(t, 6);
	printf("%d\n",add);
	//��Ԫ��2��Ϊ4
	t = ChangeTable(t, 2, 4);
	Print(t);
	system("pause");
	return 0;
}