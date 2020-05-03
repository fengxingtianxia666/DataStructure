#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "circlelist.h"

struct Value
{
	CircleListNode node;
	int v;
};

int main()
{ 
	//求约瑟夫问题
	CircleList *clist = CircleList_Create();
	struct Value v1;
	struct Value v2;
	struct Value v3;
	struct Value v4;
	struct Value v5;
	struct Value v6;
	struct Value v7;
	struct Value v8;

	int i = 0;

	v1.v = 1;
	v2.v = 2;
	v3.v = 3;
	v4.v = 4;
	v5.v = 5;
	v6.v = 6;
	v7.v = 7;
	v8.v = 8;
	CircleList_Insert(clist, (CircleListNode*)&v1, CircleList_Length(clist));//尾插法
	CircleList_Insert(clist, (CircleListNode*)&v2, CircleList_Length(clist));
	CircleList_Insert(clist, (CircleListNode*)&v3, CircleList_Length(clist));
	CircleList_Insert(clist, (CircleListNode*)&v4, CircleList_Length(clist));
	CircleList_Insert(clist, (CircleListNode*)&v5, CircleList_Length(clist));
	CircleList_Insert(clist, (CircleListNode*)&v6, CircleList_Length(clist));
	CircleList_Insert(clist, (CircleListNode*)&v7, CircleList_Length(clist));
	CircleList_Insert(clist, (CircleListNode*)&v8, CircleList_Length(clist));

	for (i = 0; i<2*CircleList_Length(clist); i++)
	{
		struct Value* pv = (struct Value*)CircleList_Get(clist, i);
		printf("%d \n", pv->v);
	}

	//重置游标,让游标回到链表的初始位置
	CircleList_Reset(clist);

	while (CircleList_Length(clist) > 0)
	{
		int m = 3;//设约瑟夫问题,报3个数出列
		struct Value * pv = NULL;
		for (i = 0; i<m; i++)
		{
			CircleList_Next(clist);
		}
		pv = (struct Value *)CircleList_Current(clist);
		printf("%d \n", pv->v);
		CircleList_Delete(clist, (CircleListNode *)pv);//出列

	}

	system("pause");
	return 0;
}