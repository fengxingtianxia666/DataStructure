// 线性表存储设计与实现.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <stdlib.h>
#include "seqlist.h"


typedef struct Teacher
{
	int age;
	int sex;
	char name[64];
}Teacher;

typedef struct Student//链表算法跟具体数据类型无关,插入什么类型都可以
{
	int age;
	char name[64];
}Student;


int main()
{
	int	ret = 0, i = 0;
	SeqList* list = NULL;

	Teacher t1, t2, t3, t4, t5;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	t4.age = 34;
	t5.age = 35;
	t1.sex = 1;
	t2.sex = 2;
	t3.sex = 3;
	t4.sex = 4;
	t5.sex = 5;

	list = SeqList_Create(10);//创建线性表
	if (list == NULL)
	{
		printf("SeqList_Create  failed ret:%d \n ", ret);
		return 0;
	}


	ret = SeqList_Insert(list, &t1, 0);//头插法
	ret = SeqList_Insert(list, &t2, 0);//头插法
	ret = SeqList_Insert(list, &t3, 0);//头插法
	ret = SeqList_Insert(list, &t4, 0);//头插法
	ret = SeqList_Insert(list, &t5, 0);//头插法

	for (i = 0; i < SeqList_Length(list); i++)//遍历链表
	{
		Teacher* tmp = (Teacher*)SeqList_Get(list, i);
		if (tmp == NULL)
		{
			return 0;
		}
		printf("tmp:age %d: tmp:sex: %d \n", tmp->age, tmp->sex);
	}

	while (SeqList_Length(list) > 0)//删除
	{
		SeqList_Delete(list, 0);
	}

	system("pause");
}


