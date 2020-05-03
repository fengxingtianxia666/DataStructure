#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"
#include "linkqueue.h"

//����Ҳ��һֱ��������Ա�

//���е�ҵ��ڵ�����ݽṹ
typedef struct _tag_LinkQueueNode
{
	LinkListNode node;
	void* item;
}TLinkQueueNode;

LinkQueue* LinkQueue_Create() 
{
	return LinkList_Create();
}

//���ٶ���,�൱���������Ա�
//�漰�ڵ���ڴ����
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

//������в���Ԫ��,�൱�������Ա��β�����Ԫ��
int LinkQueue_Append(LinkQueue* queue, void* item)
{
	int ret = 0;
	//��Ҫ��item(���е�ҵ��ڵ�)ת�������Ա�Ľڵ�
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

//�Ӷ����г���һ��Ԫ��
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