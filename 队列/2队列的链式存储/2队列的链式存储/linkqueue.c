#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"
#include "linkqueue.h"

//队列也是一直特殊的线性表

//队列的业务节点的数据结构
typedef struct _tag_LinkQueueNode
{
	LinkListNode node;
	void* item;
}TLinkQueueNode;

LinkQueue* LinkQueue_Create() 
{
	return LinkList_Create();
}

//销毁队列,相当于销毁线性表
//涉及节点的内存管理
void LinkQueue_Destroy(LinkQueue* queue)
{
	LinkQueue_Clear(queue);
	LinkList_Destroy(queue);
	return;
}

void LinkQueue_Clear(LinkQueue* queue)
{
	while (LinkQueue_Length(queue) > 0)
	{
		LinkQueue_Retrieve(queue);
	}
	LinkList_Clear(queue);
	return;
}

//向队列中插入元素,相当于向线性表的尾部添加元素
int LinkQueue_Append(LinkQueue* queue, void* item)
{
	int ret = 0;
	//需要把item(队列的业务节点)转化成线性表的节点
	TLinkQueueNode* tmp = (TLinkQueueNode*)malloc(sizeof(TLinkQueueNode));
	if (tmp == NULL)
	{
		ret = -1;
		printf("func LinkQueue_Append tmp == NULL %d \n", ret);
		return ret;
	}
	memset(tmp, 0, sizeof(TLinkQueueNode));
	tmp->item = item;
	ret = LinkList_Insert(queue, (LinkListNode*)tmp, LinkList_Length(queue));
	if (ret != 0)
	{
		printf("func LinkList_Insert err %d \n", ret);
		if (tmp != NULL)
		{
			free(tmp);
		}
		return ret;
	}

	return 0;
}

//从队列中出列一个元素
void* LinkQueue_Retrieve(LinkQueue* queue)
{
	int ret = 0;
	TLinkQueueNode* node = NULL;
	void* item = NULL;

	node = (TLinkQueueNode*)LinkList_Delete(queue, 0);
	if (node == NULL)
	{
		ret = -1;
		printf("LinkQueue_Retrieve err %d \n", ret);
		return NULL;
	}
	item = node->item;
	free(node);
	return item;
}

void* LinkQueue_Header(LinkQueue* queue)
{
	int ret = 0;
	TLinkQueueNode* node = NULL;
	void* item = NULL;

	node = (TLinkQueueNode*)LinkList_Get(queue, 0);
	if (node == NULL)
	{
		ret = -1;
		printf("LinkQueue_Header err %d \n", ret);
		return NULL;
	}
	item = node->item;
	return item;
}

int LinkQueue_Length(LinkQueue* queue)
{
	return LinkList_Length(queue);
}