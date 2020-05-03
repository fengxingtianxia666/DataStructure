#include "linklist.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//带头节点,业务节点从0号节点开始
typedef struct _tag_LinkList
{
	LinkListNode header;//链表要有头节点,指向第一个链表节点
	int length;
}TLinkList;

LinkList* LinkList_Create()
{
	TLinkList *tlist = (TLinkList *)malloc(sizeof(TLinkList));
	if (tlist == NULL)
	{
		printf("LinkList_Create tlist == NULL");
		return NULL;
	}
	memset(tlist, 0, sizeof(TLinkList));
	tlist->length = 0;
	tlist->header.next = NULL;

	return tlist;
}

void LinkList_Destroy(LinkList* list)
{
	if (list != NULL)
	{
		free(list);
		list = NULL;
	}
	return;
}

//让链表恢复到初始化状态
void LinkList_Clear(LinkList* list)
{
	TLinkList *tlist = NULL;
	if (list == NULL)
	{
		printf("LinkList_Clear list == NULL");
		return;
	}
	tlist = (TLinkList *)list;
	tlist->length = 0;
	tlist->header.next = NULL;

	return;
}

int LinkList_Length(LinkList* list)
{
	TLinkList *tlist = NULL;
	if (list == NULL)
	{
		printf("LinkList_Length list == NULL");
		return -1;
	}
	tlist = (TLinkList *)list;
	return tlist->length;
}

//因为链表是单向的,pos位置元素的地址保存在pos-1号位置的next域中
//分清链表的操作逻辑和辅助指针变量之间的关系
int LinkList_Insert(LinkList* list, LinkListNode* node, int pos)
{
	int ret = 0;
	LinkListNode *current = NULL;
	TLinkList *tList = NULL;
	tList = (TLinkList *)list;
	if (list == NULL || node == NULL || pos < 0 || pos > tList->length)
	{
		printf("LinkList_Insert list == NULL || node == NULL || pos < 0 || pos > tList->length");
		ret = -1;
		return ret;
	}
	current = &(tList->header);//让current指针指向链表头部
	for (int i=0; i<pos && (current->next != NULL); i++)//让指针往后跳pos次,跳到pos-1位置处
	{
		current = current->next;
	}
	node->next = current->next;
	current->next = node;
	tList->length++;
	return ret;
}

LinkListNode* LinkList_Get(LinkList* list, int pos)
{
	LinkListNode *current = NULL;
	TLinkList *tList = NULL;
	tList = (TLinkList *)list;
	if (list == NULL || pos < 0 || pos > tList->length)
	{
		printf("LinkList_Insert list == NULL || pos < 0 || pos > tList->length");
		return NULL;
	}
	
	current = &(tList->header);//让current指针指向头节点
	for (int i = 0; i < pos && (current->next != NULL); i++)//让指针往后跳pos次,跳到pos-1位置处
	{
		current = current->next;
	}

	return current->next;
}

//分清链表的删除逻辑和辅助指针变量之间的关系
LinkListNode* LinkList_Delete(LinkList* list, int pos)
{
	LinkListNode *current = NULL;
	LinkListNode *ret = NULL;//pos节点
	TLinkList *tList = NULL;
	tList = (TLinkList *)list;
	if (list == NULL || pos < 0 || pos > tList->length)
	{
		printf("LinkList_Insert list == NULL || node == NULL || pos < 0 || pos > tList->length");
		return NULL;
	}
	current = &(tList->header);//让current指针指向头节点
	for (int i = 0; i < pos && (current->next != NULL); i++)//让指针往后跳pos次,跳到pos-1位置处
	{
		current = current->next;
	}
	ret = current->next;
	current->next = ret->next;
	tList->length--;

	return ret;//节点不是底层库创建的,所以不要直接删除,把指针返回给上层,要析构还是干别的用都跟底层无关.
}