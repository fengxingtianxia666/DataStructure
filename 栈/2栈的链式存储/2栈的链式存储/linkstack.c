#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"
#include "linkstack.h"

typedef struct _tag_LinkStackNode//链表业务节点
{
	LinkListNode node;
	void* item; //栈的业务节点
}TLinkStackNode;


//创建栈相当于创建一个线性表
LinkStack* LinkStack_Create()
{
	return LinkList_Create();
}

//销毁一个栈,相对与销毁一个线性表
void LinkStack_Destroy(LinkStack* stack)
{
	LinkStack_Clear(stack);//因为入栈时有malloc内存,可以用LinkStack_Clear清空栈元素并析构内存
	LinkList_Destroy(stack);
	return;
}

//清空一个栈,相当于清空一个线性表
//清空一个栈,涉及到栈元素生命周期的管理
//因为入栈时我们malloc内存了,清空时需要把内存全析构掉
void LinkStack_Clear(LinkStack* stack)
{
	if (stack == NULL)
	{
		return;
	}

	while (LinkList_Length(stack) > 0)
	{
		LinkStack_Pop(stack);//因LinkStack_Pop中我们做了析构了,直接复用
	}
	LinkList_Clear(stack);
	return;
}

//向栈中添加元素,相当于向线性表的头部插入元素
//void* item 栈的业务节点,要转化成链表的业务节点
//我们要想直接使用线性表链式存储的代码,必须自定义数据类型,包含栈的业务节点void*和线性表链式节点
int LinkStack_Push(LinkStack* stack, void* item)
{
	TLinkStackNode* tmp = NULL;
	int ret = 0;
	tmp = (TLinkStackNode*)malloc(sizeof(TLinkStackNode));
	if (tmp == NULL)
	{
		return -1;
	}
	memset(tmp, 0, sizeof(TLinkStackNode));
	tmp->item = item;

	ret = LinkList_Insert(stack, (LinkListNode*)tmp, 0);
	if (ret != 0)
	{
		printf("LinkStack_Push LinkList_Insert error: %d \n", ret);
		if (tmp != NULL)
		{
			free(tmp);
			tmp = NULL;
		}
	}
	return ret;
}

//从栈中弹出元素,相当于从线性表的头部删除元素
//把线性表的业务节点,转化成栈的业务节点
void* LinkStack_Pop(LinkStack* stack)
{
	void* item = NULL;
	TLinkStackNode* tmp = (TLinkStackNode*)LinkList_Delete(stack, 0);
	if (tmp == NULL)
	{
		return NULL;
	}
	item = tmp->item;
	free(tmp);//我们在入栈时,malloc内存了,这儿要析构掉
	return item;
}

//只是获取栈顶元素,并不删除,所以不需要析构
void* LinkStack_Top(LinkStack* stack)
{
	void* item = NULL;
	TLinkStackNode* tmp = (TLinkStackNode*)LinkList_Get(stack, 0);
	if (tmp == NULL)
	{
		return NULL;
	}
	item = tmp->item;
	return item;
}


int LinkStack_Size(LinkStack* stack)
{
	return LinkList_Length(stack);
}