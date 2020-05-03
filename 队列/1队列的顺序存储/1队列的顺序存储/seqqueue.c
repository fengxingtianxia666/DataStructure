#include "seqqueue.h"
#include <stdlib.h>
#include <stdio.h>
#include "seqlist.h"

//����Ҳ��һֱ��������Ա�,�����Ա�˳��洢ģ����е�˳��洢


//����һ������,�൱�ڴ���һ�����Ա�
SeqQueue* SeqQueue_Create(int capacity)
{
	return SeqList_Create(capacity);
}

//����һ������,�൱������һ�����Ա�
void SeqQueue_Destroy(SeqQueue* queue)
{
	SeqList_Destroy(queue);
	return;
}

void SeqQueue_Clear(SeqQueue* queue)
{
	SeqList_Clear(queue);
	return;
}

//����������Ԫ��
int SeqQueue_Append(SeqQueue* queue, void* item)
{
	return SeqList_Insert(queue, item, SeqList_Length(queue));
}

//������
void* SeqQueue_Retrieve(SeqQueue* queue)
{
	return SeqList_Delete(queue, 0);
}

//���ض�ͷԪ�صĵ�ַ
void* SeqQueue_Header(SeqQueue* queue)
{
	return SeqList_Get(queue, 0);
}

int SeqQueue_Length(SeqQueue* queue)
{
	return SeqList_Length(queue);
}

int SeqQueue_Capacity(SeqQueue* queue)
{
	return SeqList_Capacity(queue);
}