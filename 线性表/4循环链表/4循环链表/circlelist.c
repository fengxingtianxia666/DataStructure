#include "circlelist.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _tag_CircleList
{
	CircleListNode header;//����Ҫ��ͷ�ڵ�,ָ���һ������ڵ�
	CircleListNode* slider;//�α�                                                       
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

//������ָ�����ʼ��״̬
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

//��Ϊ�����ǵ����,posλ��Ԫ�صĵ�ַ������pos-1��λ�õ�next����
//��������Ĳ����߼��͸���ָ�����֮��Ĺ�ϵ
int CircleList_Insert(CircleList* list, CircleListNode* node, int pos)
{
	CircleListNode *current = NULL;
	TCircleList *tList =(TCircleList *)list;
	if (list == NULL || node == NULL || pos < 0 || pos > tList->length)
	{
		printf("CircleList_Insert list == NULL || node == NULL || pos < 0 || pos > tList->length");
		return -1;
	}
	current = &(tList->header);//��currentָ��ָ������ͷ��
	for (int i = 0; i < pos && (current->next != NULL); i++)//��ָ��������pos��,����pos-1λ�ô�
	{
		current = current->next;
	}
	node->next = current->next;
	current->next = node;
	tList->length++;

	//����һ�β���ڵ�,���α�ָ��node�ڵ�
	if (tList->length == 1)
	{
		tList->slider = node;
	}

	if (current == (CircleListNode *)tList)//��current��Ȼָ��ͷ��
	{
		//��ʱ���һ��Ԫ��ָ��NULL,��ȡ���һ��Ԫ��,ָ���һ��Ԫ��,�γ�ѭ��
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

	current = &(tList->header);//��currentָ��ָ��ͷ�ڵ�
	for (int i = 0; i < pos && (current->next != NULL); i++)//��ָ��������pos��,����pos-1λ�ô�
	{
		current = current->next;
	}

	return current->next;
}

//1 ɾ����ͨ�ڵ�
//2 ɾ��ͷ�ڵ�(ɾ��0��λ�ô�Ԫ��)
CircleListNode* CircleList_Delete(CircleList* list, int pos)
{	
	CircleListNode *ret = NULL;//pos�ڵ�
	TCircleList *tList =  (TCircleList *)list;
	int i = 0;
	if ((tList != NULL) && (pos >= 0) && (tList->length > 0))
	{
		CircleListNode *current = (CircleListNode *)tList;//ָ������ͷ��
		CircleListNode* last = NULL;

		for (i = 0; i<pos; i++)
		{
			current = current->next;
		}

		//��ɾ����һ��Ԫ��
		if (current == (CircleListNode *)tList)
		{
			last = (CircleListNode*)CircleList_Get(tList, tList->length - 1);//���β��Ԫ��
		}

		//��Ҫɾ����Ԫ��(posλ��Ԫ��)
		ret = current->next;
		current->next = ret->next;
		tList->length--;

		//�ж������Ƿ�Ϊ��
		if (last != NULL)//last != NULL,˵��if (current == (CircleListNode *)tList)����
		{
			tList->header.next = ret->next;//header.next����һ��Ԫ��
			last->next = ret->next;//β���ڵ�nextָ��pos���Ԫ��
		}

		//��ɾ����Ԫ��Ϊ�α���ָ��Ԫ��
		if (tList->slider == ret)
		{
			tList->slider = ret->next;
		}

		//��ɾ��Ԫ�غ�,������Ϊ0
		if (tList->length == 0)
		{
			tList->header.next = NULL;
			tList->slider = NULL;
		}
	}

	return ret;//�ڵ㲻�ǵײ�ⴴ����,���Բ�Ҫֱ��ɾ��,��ָ�뷵�ظ��ϲ�,Ҫ�������Ǹɱ���ö����ײ��޹�.
}


//�������α����API

CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node)
{
	TCircleList* tlist = (TCircleList*)list;
	CircleListNode* ret = NULL;
	int i = 0;

	if (tlist != NULL)
	{
		CircleListNode* current = (CircleListNode*)tlist;

		//����node��ѭ�������е�λ��i
		for (i = 0; i < tlist->length; i++)
		{
			if (current->next == node)//�ҵ�Ҫɾ���Ľڵ�ret
			{
				ret = current->next;
				break;
			}

			current = current->next;
		}

		//���ret�ҵ�,����iȥɾ��
		if (ret != NULL)
		{
			CircleList_Delete(tlist, i);
		}
	}

	return ret;
}

//�����α�
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

//��ȡ�α�ָ���ֵ
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

//�ѵ�ǰλ�÷���,�����α�����
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