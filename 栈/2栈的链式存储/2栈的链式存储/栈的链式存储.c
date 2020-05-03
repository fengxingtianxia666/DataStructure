#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "linkstack.h"
#include "jiujin.h"

int main()
{ 
	int i = 0;
	int a[10];

	const char* code = "if (stack == NULL){return;";
	int ret = Scanner(code);
	printf("MyScanfCode ret: %d \n", ret);


	LinkStack* stack = NULL;
	stack = LinkStack_Create();
	if (stack == NULL)
	{
		return;
	}

	//添加元素
	for (i = 0; i<5; i++)
	{
		a[i] = i + 1;
		LinkStack_Push(stack, &a[i]);
	}

	//获取栈的基本属性
	printf("len: %d \n", LinkStack_Size(stack));
	int top = *((int*)LinkStack_Top(stack));
	printf("top: %d \n", top);

	//删除栈元素
	while (LinkStack_Size(stack) > 0)
	{
		int tmp = *((int *)LinkStack_Pop(stack));
		printf("tmp:%d \n", tmp);
	}
	//销毁栈
	LinkStack_Destroy(stack);
	
	printf("hello \n");
	system("pause");
	return 0;
}