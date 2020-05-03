#include "seqqueue.h"
#include <stdlib.h>
#include <stdio.h>
#include "seqlist.h"

//队列也是一直特殊的线性表,用线性表顺序存储模拟队列的顺序存储


//创建一个队列,相当于创建一个线性表
SeqQueue* SeqQueue_Create(int capacity)
{
	return SeqList_Create(capacity);
}

//销毁一个队列,相当于销毁一个线性表
void SeqQueue_Destroy(SeqQueue* queue)
{
	SeqList_Destroy(queue);
	return;
}

void SeqQueue_Clear(SeqQueue* queue)
{
	SeqList_Clear(queue);
	return;
}

//向队列中添加元素
int SeqQueue_Append(SeqQueue* queue, void* item)
{
	return SeqList_Insert(queue, item, SeqList_Length(queue));
}

//出队列
void* SeqQueue_Retrieve(SeqQueue* queue)
{
	return SeqList_Delete(queue, 0);
}

//返回队头元素的地址
void* SeqQueue_Header(SeqQueue* queue)
{
	return SeqList_Get(queue, 0);
}

int SeqQueue_Length(SeqQueue* queue)
{
	return SeqList_Length(queue);
}

int SeqQueue_Capacity(SeqQueue* queue)
{
	return SeqList_Capacity(queue);
}