#pragma once

typedef void SeqListNode;
typedef void SeqList;

//链表的容量和链表的长度是二个不同的概念
//容量代表总长度,长度是实际插入的长度,可能容量为8,但是只插入了6个元素(长度为6).

//创建一个线性表
SeqList* SeqList_Create(int capacity);

//销毁一个线性表list
void SeqList_Destroy(SeqList* list);

//将一个线性表list中的所有元素清空,线性表回到创建时的初始状态
void SeqList_Clear(SeqList* list);

//返回一个线性表list中的所有元素个数
int SeqList_Length(SeqList* list);

//返回一个线性表list的容量
int SeqList_Capacity(SeqList* list);

//向一个线性表list的pos位置插入新元素node
int SeqList_Insert(SeqList* list, SeqListNode* node, int pos);

//获取一个线性表list的pos位置处的元素
SeqListNode* SeqList_Get(SeqList* list, int pos);

//删除一个线性表list的pos位置处的元素 返回值为被删除的元素,NULL表示删除失败
SeqListNode* SeqList_Delete(SeqList* list, int pos);


//最重要的是List_Insert,怎么实现链表算法和具体的数据类型分离的?
//看SeqListNode实际是void型,链表根本不关心节点是什么数据类型,只关心给我一个节点的内存首地址(node),
//然后把这些节点的的内存首地址组织成一个线性表.
//int SeqList_Insert(List* list, SeqListNode* node, int pos);
