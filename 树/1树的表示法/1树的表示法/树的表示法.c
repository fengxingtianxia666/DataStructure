#include "stdio.h"
#include "string.h"
#include "stdlib.h"

/*
struct BiNode
{
	int data;
	struct BiNode  *lchild, *rchild;
};
//重新重命名类型
typedef struct BiNode BiNode;
//也是重命名类型 是一个指针的数据类型
typedef struct BiNode *BiTree;
*/


//二叉链表
typedef struct BiNode
{
	int data;
	struct BiNode  *lchild, *rchild;
}BiNode, *BiTree;

//三叉链表
typedef struct TriTNode
{
	int data;
	//左右孩子指针
	struct TriTNode *lchild, *rchild;
	struct TriTNode *parent;
}TriTNode, *TriTree;


//双亲链表
#define MAX_TREE_SIZE 100
typedef struct BPTNode
{
	int data;
	int parentPosition; //指向双亲的指针 //数组下标
	char LRTag; //左右孩子标志域
}BPTNode;

typedef struct BPTree
{
	BPTNode nodes[100]; //因为节点之间是分散的，需要把节点存储到数组中
	int num_node;  //节点数目
	int root; //根结点的位置 //注意此域存储的是父亲节点在数组的下标
}BPTree;

//用这个数据结构能表达出一颗树。。。能，怎么表达？不能why


void main11()
{
	BPTree tree;

	BiNode t1, t2, t3, t4, t5;
	memset(&t1, 0, sizeof(BiNode));
	memset(&t2, 0, sizeof(BiNode));
	memset(&t3, 0, sizeof(BiNode));
	memset(&t4, 0, sizeof(BiNode));
	memset(&t5, 0, sizeof(BiNode));
	t1.data = 1;
	t2.data = 2;
	t3.data = 3;
	t4.data = 4;
	t5.data = 5;

	//建立树关系

	//t1的左孩子为t2
	t1.lchild = &t2;

	//t1的右孩子为t3
	t1.rchild = &t3;

	//t2的左孩子为t4
	t2.lchild = &t4;

	//t3的左孩子为t5
	t3.lchild = &t5;


	system("pause");
}

void main()
{
	BiTree p1, p2, p3, p4, p5;

	p1 = (BiTree)malloc(sizeof(BiNode));
	p2 = (BiTree)malloc(sizeof(BiNode));
	p3 = (BiTree)malloc(sizeof(BiNode));
	p4 = (BiTree)malloc(sizeof(BiNode));
	p5 = (BiTree)malloc(sizeof(BiNode));
	memset(p1, 0, sizeof(BiNode));
	memset(p2, 0, sizeof(BiNode));
	memset(p3, 0, sizeof(BiNode));
	memset(p4, 0, sizeof(BiNode));
	memset(p5, 0, sizeof(BiNode));

	p1->data = 1;
	p2->data = 2;
	p3->data = 3;
	p4->data = 4;
	p5->data = 5;

	//建立树关系

	//t1的左孩子为t2
	p1->lchild = p2;

	//t1的右孩子为t3
	p1->rchild = p3;

	//t2的左孩子为t4
	p2->lchild = p4;

	//t3的左孩子为t5
	p3->lchild = p5;


	system("pause");
}