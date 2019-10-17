#include <stdio.h>
#include <stdlib.h>

typedef struct lineStack
{
	int data;
	struct lineStack* next;
}lineStack;

lineStack* push(lineStack* stack, int num)
{
	//创建存储新元素的节点
	lineStack* line = (lineStack*)malloc(sizeof(lineStack));
	line->data = num;
	//新节点与头结点建立关系
	line->next = stack;
	stack = line;
	return stack;
}

//链表元素出栈
lineStack* pop(lineStack* stack)
{
	if (stack)
	{
		//声明一个新指针指向栈顶节点
		lineStack* p = stack;
		stack = stack->next;
		printf("出栈元素：%d ", p->data);
		if (stack)
		{
			printf("新栈顶元素：%d\n", stack->data);
		}
		else
		{
			printf("栈已空\n");
		}
		free(p);
	}
	else
	{
		printf("栈内没有元素");
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