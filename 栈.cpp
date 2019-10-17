#include <stdio.h>
#include <stdlib.h>

/////////////////////////////////////
/////////////顺序栈///////////////////
//元素入栈
int push(int*a ,int top,int data)
{
	a[++top] = data;
	return top;
}

//元素出栈
int pop(int* a, int top)
{
	if (top == -1)
	{
		return -1;
	}
	printf("弹出元素%d\n ", a[top]);
	top--;
	return top;
}
int main()
{
	int a[100];
	int top = -1;
	top = push(a, top,1);
	top = push(a, top, 2);
	top = push(a, top, 3);
	top = push(a, top, 4);

	top = pop(a, top);
	system("pause");
	return 0;
}
///////////////////////////////////////////
