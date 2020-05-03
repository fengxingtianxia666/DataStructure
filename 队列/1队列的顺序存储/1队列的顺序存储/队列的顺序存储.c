#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "seqqueue.h"

int main()
{ 
	int capacity = 10;
	int i = 10;
	int a[10];
	int ret;

	SeqQueue* queue = NULL;
	queue = SeqQueue_Create(capacity);
	if (queue == NULL)
	{
		printf("queue == NULL \n");
		return;
	}

	//入队列
	for (i = 0; i<5; i++)
	{
		a[i] = i + 1;
		ret = SeqQueue_Append(queue, &a[i]);
		//printf("ret = %d \n", ret);
	}

	//打印队列的属性
	printf("len: %d \n", SeqQueue_Length(queue));
	printf("header: %d \n", *((int*)SeqQueue_Header(queue)));
	printf("capacity: %d \n", SeqQueue_Capacity(queue));

	//出队列
	while (SeqQueue_Length(queue) > 0)
	{
		int tmp = *((int*)SeqQueue_Retrieve(queue));//因为我们存在队列的是int型数据,所以要转换成int型
		printf("tmp: %d \n", tmp);
	}
	SeqQueue_Destroy(queue);

	
	printf("hello \n");
	system("pause");
	return 0;
}