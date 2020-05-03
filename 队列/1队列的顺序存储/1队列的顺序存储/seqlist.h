#pragma once

typedef void SeqListNode;
typedef void SeqList;

//���������������ĳ����Ƕ�����ͬ�ĸ���
//���������ܳ���,������ʵ�ʲ���ĳ���,��������Ϊ8,����ֻ������6��Ԫ��(����Ϊ6).

//����һ�����Ա�
SeqList* SeqList_Create(int capacity);

//����һ�����Ա�list
void SeqList_Destroy(SeqList* list);

//��һ�����Ա�list�е�����Ԫ�����,���Ա�ص�����ʱ�ĳ�ʼ״̬
void SeqList_Clear(SeqList* list);

//����һ�����Ա�list�е�����Ԫ�ظ���
int SeqList_Length(SeqList* list);

//����һ�����Ա�list������
int SeqList_Capacity(SeqList* list);

//��һ�����Ա�list��posλ�ò�����Ԫ��node
int SeqList_Insert(SeqList* list, SeqListNode* node, int pos);

//��ȡһ�����Ա�list��posλ�ô���Ԫ��
SeqListNode* SeqList_Get(SeqList* list, int pos);

//ɾ��һ�����Ա�list��posλ�ô���Ԫ�� ����ֵΪ��ɾ����Ԫ��,NULL��ʾɾ��ʧ��
SeqListNode* SeqList_Delete(SeqList* list, int pos);


//����Ҫ����List_Insert,��ôʵ�������㷨�;�����������ͷ����?
//��SeqListNodeʵ����void��,������������Ľڵ���ʲô��������,ֻ���ĸ���һ���ڵ���ڴ��׵�ַ(node),
//Ȼ�����Щ�ڵ�ĵ��ڴ��׵�ַ��֯��һ�����Ա�.
//int SeqList_Insert(List* list, SeqListNode* node, int pos);
