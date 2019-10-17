#include <stdio.h>
#include <stdlib.h>

typedef struct lineStack
{
	int data;
	struct lineStack* next;
}lineStack;

lineStack* push(lineStack* stack, int num)
{
	//�����洢��Ԫ�صĽڵ�
	lineStack* line = (lineStack*)malloc(sizeof(lineStack));
	line->data = num;
	//�½ڵ���ͷ��㽨����ϵ
	line->next = stack;
	stack = line;
	return stack;
}

//����Ԫ�س�ջ
lineStack* pop(lineStack* stack)
{
	if (stack)
	{
		//����һ����ָ��ָ��ջ���ڵ�
		lineStack* p = stack;
		stack = stack->next;
		printf("��ջԪ�أ�%d ", p->data);
		if (stack)
		{
			printf("��ջ��Ԫ�أ�%d\n", stack->data);
		}
		else
		{
			printf("ջ�ѿ�\n");
		}
		free(p);
	}
	else
	{
		printf("ջ��û��Ԫ��");
		return stack;
	}
	return stack;
	
}
int main()
{
	lineStack* stack = NULL;
	stack = push(stack, 1);
	stack = push(stack, 2);
	stack = push(stack, 3);
	stack = push(stack, 4);
	stack = pop(stack);
	stack = pop(stack);
	stack = pop(stack);
	stack = pop(stack);
	stack = pop(stack);
	system("pause");
	return 0;
}