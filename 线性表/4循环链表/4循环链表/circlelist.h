#pragma once

typedef void CircleList;

typedef struct _tag_CircleListNode
{
	struct _tag_CircleListNode* next;
}CircleListNode;


CircleList* CircleList_Create();

void CircleList_Destroy(CircleList* list);

void CircleList_Clear(CircleList* list);

int CircleList_Length(CircleList* list);

int CircleList_Insert(CircleList* list, CircleListNode* node, int pos);

CircleListNode* CircleList_Get(CircleList* list, int pos);

CircleListNode* CircleList_Delete(CircleList* list, int pos);

//下面是游标相关API

CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node);

CircleListNode* CircleList_Reset(CircleList* list);

//获取游标指向的值
CircleListNode* CircleList_Current(CircleList* list);

//游标后移一位,同时返回游标当前指向的值
CircleListNode* CircleList_Next(CircleList* list);