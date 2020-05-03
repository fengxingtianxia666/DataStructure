#include "linklist.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//��ͷ�ڵ�,ҵ��ڵ��0�Žڵ㿪ʼ
typedef struct _tag_LinkList
{
	LinkListNode header;//����Ҫ��ͷ�ڵ�,ָ���һ������ڵ�
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

//������ָ�����ʼ��״̬
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

//��Ϊ�����ǵ����,posλ��Ԫ�صĵ�ַ������pos-1��λ�õ�next����
//��������Ĳ����߼��͸���ָ�����֮��Ĺ�ϵ
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
	current = &(tList->header);//��currentָ��ָ������ͷ��
	for (int i=0; i<pos && (current->next != NULL); i++)//��ָ��������pos��,����pos-1λ�ô�
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
	
	current = &(tList->header);//��currentָ��ָ��ͷ�ڵ�
	for (int i = 0; i < pos && (current->next != NULL); i++)//��ָ��������pos��,����pos-1λ�ô�
	{
		current = current->next;
	}

	return current->next;
}

//���������ɾ���߼��͸���ָ�����֮��Ĺ�ϵ
LinkListNode* LinkList_Delete(LinkList* list, int pos)
{
	LinkListNode *current = NULL;
	LinkListNode *ret = NULL;//pos�ڵ�
	TLinkList *tList = NULL;
	tList = (TLinkList *)list;
	if (list == NULL || pos < 0 || pos > tList->length)
	{
		printf("LinkList_Insert list == NULL || node == NULL || pos < 0 || pos > tList->length");
		return NULL;
	}
	current = &(tList->header);//��currentָ��ָ��ͷ�ڵ�
	for (int i = 0; i < pos && (current->next != NULL); i++)//��ָ��������pos��,����pos-1λ�ô�
	{
		current = current->next;
	}
	ret = current->next;
	current->next = ret->next;
	tList->length--;

	return ret;//�ڵ㲻�ǵײ�ⴴ����,���Բ�Ҫֱ��ɾ��,��ָ�뷵�ظ��ϲ�,Ҫ�������Ǹɱ���ö����ײ��޹�.
}