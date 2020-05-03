#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "seqstack.h"

int main()
{ 
	int i = 0;
	int a[10];
	SeqStack* stack = NULL;
	stack = SeqStack_Create(10);
	if (stack == NULL)
	{
		return;
	}

	//循环压栈
	for (i = 0; i < 5; i++)
	{
		a[i] = i + 1;
		SeqStack_Push(stack, &a[i]);
	}

	printf("Capacity: %d \n", SeqStack_Capacity(stack));//栈的容量
	printf("length: %d \n", SeqStack_Size(stack));//栈的长度
	printf("top: %d \n", *((int *)SeqStack_Top(stack)));//栈顶元素的值

	while (SeqStack_Size(stack) > 0)//遍历弹出栈的元素
	{
		int tmp = *((int *)SeqStack_Pop(stack));
		printf("弹出的元素tmp: %d \n", tmp);//

	}

	SeqStack_Destroy(stack);


	printf("hello \n");
	system("pause");
	return 0;
}