#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "linkqueue.h"

int main()
{ 
	int i, a[10];
	LinkQueue *queue = NULL;
	queue = LinkQueue_Create();
	if (queue == NULL)
	{
		return 0;
	}

	//向队列中添加元素
	for (i=0; i<5; i++)
	{
		a[i] = i + 1;
		LinkQueue_Append(queue, &a[i]);
	}
	LinkQueue_Clear(queue);

	//向队列中添加元素
	for (i = 0; i < 5; i++)
	{
		a[i] = i + 1;
		LinkQueue_Append(queue, &a[i]);
	}

	//求队列的属性
	printf("len: %d \n", LinkQueue_Length(queue));
	printf("header: %d \n", *((int*)LinkQueue_Header(queue)));

	//出列
	while (LinkQueue_Length(queue) > 0)
	{
		int tmp;
		tmp = *((int*)(LinkQueue_Retrieve(queue)));
		printf("tmp: %d \n", tmp);
	}

	//销毁队列
	LinkQueue_Destroy(queue);

	
	system("pause");
	return 0;
}