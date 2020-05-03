#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include "dlinklist.h"

typedef struct _tag_DLinkList
{
	DLinkListNode header;
	DLinkListNode* slider;
	int length;
}TDLinkList;



DLinkList* DLinkList_Create()
{
	TDLinkList* ret = (TDLinkList*)malloc(sizeof(TDLinkList));

	if (ret != NULL)
	{
		ret->length = 0;
		ret->header.next = NULL;
		ret->header.pre = NULL;
		ret->slider = NULL;
	}
}

void DLinkList_Destroy(DLinkList* list)
{
	if (list != NULL)
	{
		free(list);
		list = NULL;
	}

	return;
}

//让链表恢复到初始化状态
void DLinkList_Clear(DLinkList* list)
{
	TDLinkList *tlist = (TDLinkList*)list;
	if (tlist == NULL)
	{
		printf("DLinkList_Clear tlist == NULL \n");
		return;
	}

	tlist->length = 0;
	tlist->header.next = NULL;
	tlist->slider = NULL;

	return;
}

int DLinkList_Length(DLinkList* list)
{
	TDLinkList *tlist = (TDLinkList*)list;
	int ret = 0;
	if (tlist != NULL)
	{
		ret = tlist->length;
	}

	return ret;
}

//先画图,照着图写代码逻辑
int DLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos)
{
	if (list == NULL || node == NULL || pos < 0)
	{
		return -1;
	}

	int i = 0;
	TDLinkList *tlist = (TDLinkList*)list;
	DLinkListNode* current = (DLinkListNode*)tlist;
	DLinkListNode* next = NULL;

	for (i = 0; (i<pos)&&(current->next!=NULL); i++)
	{
		current = current->next;
	}
	//①若当前链表中无元素,next指向null
	//②若在尾部插入元素,next指向null
	next = current->next;

	//步骤1-2
	current->next = node;
	node->next = next;

	//步骤3-4
	if (next != NULL)
	{
		next->pre = node;
	}
	node->pre = current;
	if (tlist->length == 0)
	{
		tlist->slider = node;//若这是链表插入的第一个元素,游标指向该元素
	}

	//若在头部插入
	if (current == (DLinkListNode*)tlist)
	{
		node->pre = NULL;
	}

	tlist->length++;

	return 0;
}

DLinkListNode* DLinkList_Get(DLinkList* list, int pos)
{
	TDLinkList* tlist = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	int i = 0;
	if ((tlist != NULL) && (0 <= pos) && (pos < tlist->length))
	{
		DLinkListNode* current = (DLinkListNode*)tlist;
		for (i = 0; i<pos; i++)
		{
			current = current->next;
		}
		ret = current->next;
	}

	return ret;
}

//画图,跟着图写代码
DLinkListNode* DLinkList_Delete(DLinkList* list, int pos)
{
	TDLinkList* tlist = (TDLinkList*)list;
	DLinkListNode* ret = NULL;//指向要删除的节点
	int i = 0;
	if (tlist == NULL || pos < 0)
	{
		return NULL;
	}

	DLinkListNode* current = (DLinkListNode*)tlist;//指向要删除的上一个节点
	DLinkListNode* next = NULL;//指向要删除的下一个节点
	for (i = 0; i<pos; i++)
	{
		current = current->next;
	}

	ret = current->next;
	next = ret->next;

	//步骤1
	current->next = next;

	//步骤2
	if (next != NULL)//若next为NULL,就不用设置pre指针了
	{
		next->pre = current;
		if (current == (DLinkListNode*)tlist)//若删除第0个位置
		{
			next->pre = NULL;
		}
	}

	if (tlist->slider == ret)
	{
		tlist->slider = next;
	}

	tlist->length--;

	return ret;//把指向要删除的节点的指针返回给上层.
}

DLinkListNode* DLinkList_DeleteNode(DLinkList* list, DLinkListNode* node)
{
	TDLinkList* tlist = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	int i = 0;

	if (tlist != NULL)
	{
		DLinkListNode* current = (DLinkListNode*)tlist;

		for (i = 0; i< tlist->length; i++)
		{
			if (current->next == node)
			{
				ret = current->next;
				break;
			}

			current = current->next;
		}

		if (ret != NULL)
		{
			DLinkList_Delete(tlist, i);
		}
	}

	return ret;
}

DLinkListNode* DLinkList_Reset(DLinkList* list)
{
	TDLinkList *tlist = (TDLinkList*)list;
	DLinkListNode *ret = NULL;
	if (tlist != NULL)
	{
		tlist->slider = tlist->header.next;
		ret = tlist->slider;
	}

	return ret;
}

DLinkListNode* DLinkList_Current(DLinkList* list)
{
	TDLinkList *tlist = (TDLinkList*)list;
	DLinkListNode *ret = NULL;
	if (tlist != NULL)
	{
		ret = tlist->slider;
	}

	return ret;
}

DLinkListNode* DLinkList_Next(DLinkList* list)
{
	TDLinkList *tlist = (TDLinkList*)list;
	DLinkListNode *ret = NULL;
	if (tlist != NULL && tlist->slider != NULL)
	{
		ret = tlist->slider;
		tlist->slider = ret->next;		
	}

	return ret;
}

DLinkListNode* DLinkList_Pre(DLinkList* list)
{
	TDLinkList *tlist = (TDLinkList*)list;
	DLinkListNode *ret = NULL;
	if (tlist != NULL && tlist->slider != NULL)
	{
		ret = tlist->slider;
		tlist->slider = ret->pre;
	}

	return ret;
}