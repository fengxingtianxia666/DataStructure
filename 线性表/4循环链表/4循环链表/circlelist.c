#include "circlelist.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _tag_CircleList
{
	CircleListNode header;//链表要有头节点,指向第一个链表节点
	CircleListNode* slider;//游标                                                       
	int length;
}TCircleList;

CircleList* CircleList_Create()
{
	TCircleList *clist = (TCircleList *)malloc(sizeof(TCircleList));
	if (clist == NULL)
	{
		return NULL;
	}

	clist->length = 0;
	clist->header.next = NULL;
	clist->slider = NULL;

	return clist;
}

void CircleList_Destroy(CircleList* list)
{
	if (list != NULL)
	{
		free(list);
		list = NULL;
	}
	return;
}

//让链表恢复到初始化状态
void CircleList_Clear(CircleList* list)
{
	TCircleList *tlist = (TCircleList *)list;
	if (list == NULL)
	{
		printf("CircleList_Clear list == NULL");
		return;
	}
	tlist->length = 0;
	tlist->header.next = NULL;
	tlist->slider = NULL;

	return;
}

int CircleList_Length(CircleList* list)
{
	TCircleList *tlist = NULL;
	if (list == NULL)
	{
		printf("CircleList_Length list == NULL");
		return -1;
	}
	tlist = (TCircleList *)list;
	return tlist->length;
}

//因为链表是单向的,pos位置元素的地址保存在pos-1号位置的next域中
//分清链表的操作逻辑和辅助指针变量之间的关系
int CircleList_Insert(CircleList* list, CircleListNode* node, int pos)
{
	CircleListNode *current = NULL;
	TCircleList *tList =(TCircleList *)list;
	if (list == NULL || node == NULL || pos < 0 || pos > tList->length)
	{
		printf("CircleList_Insert list == NULL || node == NULL || pos < 0 || pos > tList->length");
		return -1;
	}
	current = &(tList->header);//让current指针指向链表头部
	for (int i = 0; i < pos && (current->next != NULL); i++)//让指针往后跳pos次,跳到pos-1位置处
	{
		current = current->next;
	}
	node->next = current->next;
	current->next = node;
	tList->length++;

	//若第一次插入节点,让游标指向node节点
	if (tList->length == 1)
	{
		tList->slider = node;
	}

	if (current == (CircleListNode *)tList)//若current仍然指向头部
	{
		//此时最后一个元素指向NULL,获取最后一个元素,指向第一个元素,形成循环
		CircleListNode* last = CircleList_Get(tList, tList->length - 1);
		last->next = current->next;
	}
	
	return 0;
}

CircleListNode* CircleList_Get(CircleList* list, int pos)
{
	CircleListNode *current = NULL;
	TCircleList *tList = NULL;
	tList = (TCircleList *)list;
	if (list == NULL || pos < 0 || pos > tList->length)
	{
		printf("CircleList_Insert list == NULL || pos < 0 || pos > tList->length");
		return NULL;
	}

	current = &(tList->header);//让current指针指向头节点
	for (int i = 0; i < pos && (current->next != NULL); i++)//让指针往后跳pos次,跳到pos-1位置处
	{
		current = current->next;
	}

	return current->next;
}

//1 删除普通节点
//2 删除头节点(删除0号位置处元素)
CircleListNode* CircleList_Delete(CircleList* list, int pos)
{	
	CircleListNode *ret = NULL;//pos节点
	TCircleList *tList =  (TCircleList *)list;
	int i = 0;
	if ((tList != NULL) && (pos >= 0) && (tList->length > 0))
	{
		CircleListNode *current = (CircleListNode *)tList;//指向链表头部
		CircleListNode* last = NULL;

		for (i = 0; i<pos; i++)
		{
			current = current->next;
		}

		//若删除第一个元素
		if (current == (CircleListNode *)tList)
		{
			last = (CircleListNode*)CircleList_Get(tList, tList->length - 1);//求出尾部元素
		}

		//求要删除的元素(pos位置元素)
		ret = current->next;
		current->next = ret->next;
		tList->length--;

		//判断链表是否为空
		if (last != NULL)//last != NULL,说明if (current == (CircleListNode *)tList)成立
		{
			tList->header.next = ret->next;//header.next即第一个元素
			last->next = ret->next;//尾部节点next指向pos后的元素
		}

		//若删除的元素为游标所指的元素
		if (tList->slider == ret)
		{
			tList->slider = ret->next;
		}

		//若删除元素后,链表长度为0
		if (tList->length == 0)
		{
			tList->header.next = NULL;
			tList->slider = NULL;
		}
	}

	return ret;//节点不是底层库创建的,所以不要直接删除,把指针返回给上层,要析构还是干别的用都跟底层无关.
}


//下面是游标相关API

CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node)
{
	TCircleList* tlist = (TCircleList*)list;
	CircleListNode* ret = NULL;
	int i = 0;

	if (tlist != NULL)
	{
		CircleListNode* current = (CircleListNode*)tlist;

		//查找node在循环链表中的位置i
		for (i = 0; i < tlist->length; i++)
		{
			if (current->next == node)//找到要删除的节点ret
			{
				ret = current->next;
				break;
			}

			current = current->next;
		}

		//如果ret找到,根据i去删除
		if (ret != NULL)
		{
			CircleList_Delete(tlist, i);
		}
	}

	return ret;
}

//重置游标
CircleListNode* CircleList_Reset(CircleList* list)
{
	TCircleList *tlist = (TCircleList *)list;
	CircleListNode* ret = NULL;

	if (tlist != NULL)
	{
		tlist->slider = tlist->header.next;
		ret = tlist->slider;
	}

	return ret;
}

//获取游标指向的值
CircleListNode* CircleList_Current(CircleList* list)
{
	TCircleList* tlist = (TCircleList *)list;
	CircleListNode* ret = NULL;

	if (tlist != NULL)
	{
		ret = tlist->slider;
	}

	return ret;
}

//把当前位置返回,并且游标下移
CircleListNode* CircleList_Next(CircleList* list)
{
	TCircleList* tlist = (TCircleList*)list;
	CircleListNode* ret = NULL;

	if ((tlist != NULL) && (tlist->slider != NULL))
	{
		ret = tlist->slider;
		tlist->slider = ret->next;
	}

	return ret;
}