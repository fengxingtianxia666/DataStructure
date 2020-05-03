
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seqlist.h"

typedef struct _tag_SeqList
{
	int length;
	int capacity;
	unsigned int **node;//ָ������������
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
	memset(tmpList, 0, sizeof(TSeqList));//��ʼ��Ϊ0	 memset��<string>�ж���

	//����capacity�Ĵ�С�����ڴ�ռ�
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

//��������
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

//������� �ص���ʼ��״̬
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

//�����㷨
//��pos�����Ԫ��ȫ������1��λ
//�ڲ���Ԫ��
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
		printf("func SeqList_Insert �������� \n");
		return -1;
	}

	//�ݴ����� ����Ϊ10,����Ϊ6(0-5),�û�Ҫ��λ��9����,����Ϊλ��6������
	if (pos >= tmpList->length)
	{
		pos = tmpList->length;
	}

	//��pos�����Ԫ��ȫ������1��λ
	for (int i = tmpList->length; i > pos; i--)
	{
		tmpList->node[i] = tmpList->node[i - 1];
	}
	//����Ԫ��
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

//ɾ���㷨
//���Ȼ���posλ�õ�����(Ҫ����)
//�ں�������Ԫ��ǰ��1��λ
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


