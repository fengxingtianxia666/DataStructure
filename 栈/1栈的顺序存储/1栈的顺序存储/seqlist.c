
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seqlist.h"

typedef struct _tag_SeqList
{
	int length;
	int capacity;
	unsigned int **node;//指向链表中数据
}TSeqList;

SeqList* SeqList_Create(int capacity)
{
	TSeqList *tmpList = NULL;
	int ret = 0;
	tmpList = (TSeqList *)malloc(sizeof(TSeqList));
	if (tmpList == NULL)
	{
		ret = -1;
		printf("func SeqList_Create err %d \n", ret);
		return NULL;
	}
	memset(tmpList, 0, sizeof(TSeqList));//初始化为0	 memset在<string>中定义

	//根据capacity的大小分配内存空间
	tmpList->node = (unsigned int **)malloc(sizeof(unsigned int *) * capacity);
	if (tmpList->node == NULL)
	{
		ret = -2;
		printf("func SeqList_Create malloc tmp->node err %d\n", ret);
		return NULL;
	}
	tmpList->capacity = capacity;
	tmpList->length = 0;
	return tmpList;
}

//销毁链表
void SeqList_Destroy(SeqList* list)
{
	if (list == NULL)
	{
		printf("func SeqList_Destroy list == NULL \n");
		return;
	}

	TSeqList *tmpList = (TSeqList *)list;
	if (tmpList->node != NULL)
	{
		free(tmpList->node);
	}
	free(tmpList);
	tmpList = NULL;
	return;
}

//清空链表 回到初始化状态
void SeqList_Clear(SeqList* list)
{
	if (list == NULL)
	{
		printf("func SeqList_Clear list == NULL \n");
		return;
	}

	TSeqList *tmpList = (TSeqList *)list;
	tmpList->length = 0;
	return;
}

int SeqList_Length(SeqList* list)
{
	if (list == NULL)
	{
		printf("func SeqList_Length list == NULL \n");
		return -1;
	}

	TSeqList *tmpList = (TSeqList *)list;
	return tmpList->length;
}

int SeqList_Capacity(SeqList* list)
{
	if (list == NULL)
	{
		printf("func SeqList_Capacity list == NULL \n");
		return -1;
	}

	TSeqList *tmpList = (TSeqList *)list;
	return tmpList->capacity;
}

//插入算法
//①pos后面的元素全部后移1单位
//②插入元素
int SeqList_Insert(SeqList* list, SeqListNode* node, int pos)
{
	if (list == NULL || node == NULL || pos < 0)
	{
		printf("func SeqList_Insert list == NULL || node == NULL || pos < 0 \n");
		return -1;
	}

	TSeqList *tmpList = (TSeqList *)list;
	if (tmpList->length == tmpList->capacity)
	{
		printf("func SeqList_Insert 链表已满 \n");
		return -1;
	}

	//容错修正 容量为10,长度为6(0-5),用户要在位置9插入,修正为位置6处插入
	if (pos >= tmpList->length)
	{
		pos = tmpList->length;
	}

	//把pos后面的元素全部后移1单位
	for (int i = tmpList->length; i > pos; i--)
	{
		tmpList->node[i] = tmpList->node[i - 1];
	}
	//插入元素
	tmpList->node[pos] = node;
	tmpList->length++;
	return 0;
}

SeqListNode* SeqList_Get(SeqList* list, int pos)
{
	TSeqList *tmpList = (TSeqList *)list;
	if (list == NULL || pos < 0 || pos > tmpList->length - 1)
	{
		printf("func SeqList_Get list == NULL || pos = %d \n", pos);
		return NULL;
	}

	if (tmpList->node == NULL)
	{
		printf("func SeqList_Insert tmpList->node == NULL \n");
		return NULL;
	}
	return (SeqListNode*)tmpList->node[pos];
}

//删除算法
//①先缓存pos位置的数据(要返回)
//②后面所有元素前移1单位
SeqListNode* SeqList_Delete(SeqList* list, int pos)
{
	SeqListNode* ret = NULL;
	TSeqList *tmpList = (TSeqList *)list;
	if (list == NULL || pos < 0 || pos > tmpList->length - 1)
	{
		printf("func SeqList_Insert list == NULL || pos < 0 || pos >= tmpList->length - 1 \n");
		return NULL;
	}
	ret = (SeqListNode*)tmpList->node[pos];

	for (int i = pos; i < tmpList->length; i++)
	{
		tmpList->node[i] = tmpList->node[i+1];
	}
	tmpList->length--;
	return ret;
}


