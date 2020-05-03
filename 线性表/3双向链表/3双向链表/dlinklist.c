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

//������ָ�����ʼ��״̬
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

//�Ȼ�ͼ,����ͼд�����߼�
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
	//������ǰ��������Ԫ��,nextָ��null
	//������β������Ԫ��,nextָ��null
	next = current->next;

	//����1-2
	current->next = node;
	node->next = next;

	//����3-4
	if (next != NULL)
	{
		next->pre = node;
	}
	node->pre = current;
	if (tlist->length == 0)
	{
		tlist->slider = node;//�������������ĵ�һ��Ԫ��,�α�ָ���Ԫ��
	}

	//����ͷ������
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

//��ͼ,����ͼд����
DLinkListNode* DLinkList_Delete(DLinkList* list, int pos)
{
	TDLinkList* tlist = (TDLinkList*)list;
	DLinkListNode* ret = NULL;//ָ��Ҫɾ���Ľڵ�
	int i = 0;
	if (tlist == NULL || pos < 0)
	{
		return NULL;
	}

	DLinkListNode* current = (DLinkListNode*)tlist;//ָ��Ҫɾ������һ���ڵ�
	DLinkListNode* next = NULL;//ָ��Ҫɾ������һ���ڵ�
	for (i = 0; i<pos; i++)
	{
		current = current->next;
	}

	ret = current->next;
	next = ret->next;

	//����1
	current->next = next;

	//����2
	if (next != NULL)//��nextΪNULL,�Ͳ�������preָ����
	{
		next->pre = current;
		if (current == (DLinkListNode*)tlist)//��ɾ����0��λ��
		{
			next->pre = NULL;
		}
	}

	if (tlist->slider == ret)
	{
		tlist->slider = next;
	}

	tlist->length--;

	return ret;//��ָ��Ҫɾ���Ľڵ��ָ�뷵�ظ��ϲ�.
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