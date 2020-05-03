#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"
#include "linkstack.h"

typedef struct _tag_LinkStackNode//����ҵ��ڵ�
{
	LinkListNode node;
	void* item; //ջ��ҵ��ڵ�
}TLinkStackNode;


//����ջ�൱�ڴ���һ�����Ա�
LinkStack* LinkStack_Create()
{
	return LinkList_Create();
}

//����һ��ջ,���������һ�����Ա�
void LinkStack_Destroy(LinkStack* stack)
{
	LinkStack_Clear(stack);//��Ϊ��ջʱ��malloc�ڴ�,������LinkStack_Clear���ջԪ�ز������ڴ�
	LinkList_Destroy(stack);
	return;
}

//���һ��ջ,�൱�����һ�����Ա�
//���һ��ջ,�漰��ջԪ���������ڵĹ���
//��Ϊ��ջʱ����malloc�ڴ���,���ʱ��Ҫ���ڴ�ȫ������
void LinkStack_Clear(LinkStack* stack)
{
	if (stack == NULL)
	{
		return;
	}

	while (LinkList_Length(stack) > 0)
	{
		LinkStack_Pop(stack);//��LinkStack_Pop����������������,ֱ�Ӹ���
	}
	LinkList_Clear(stack);
	return;
}

//��ջ�����Ԫ��,�൱�������Ա��ͷ������Ԫ��
//void* item ջ��ҵ��ڵ�,Ҫת���������ҵ��ڵ�
//����Ҫ��ֱ��ʹ�����Ա���ʽ�洢�Ĵ���,�����Զ�����������,����ջ��ҵ��ڵ�void*�����Ա���ʽ�ڵ�
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

//��ջ�е���Ԫ��,�൱�ڴ����Ա��ͷ��ɾ��Ԫ��
//�����Ա��ҵ��ڵ�,ת����ջ��ҵ��ڵ�
void* LinkStack_Pop(LinkStack* stack)
{
	void* item = NULL;
	TLinkStackNode* tmp = (TLinkStackNode*)LinkList_Delete(stack, 0);
	if (tmp == NULL)
	{
		return NULL;
	}
	item = tmp->item;
	free(tmp);//��������ջʱ,malloc�ڴ���,���Ҫ������
	return item;
}

//ֻ�ǻ�ȡջ��Ԫ��,����ɾ��,���Բ���Ҫ����
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