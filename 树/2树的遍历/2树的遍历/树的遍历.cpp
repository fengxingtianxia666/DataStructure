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

//中序遍历
void inOrder(BiNode *root)
{
	if (root != NULL)
	{
		inOrder(root->lchild);
		printf("%d ", root->data);
		inOrder(root->rchild);
	}
	return;
}

//先序遍历
void preOrder(BiNode *root)
{
	if (root != NULL)
	{
		printf("%d ", root->data);
		preOrder(root->lchild);
		preOrder(root->rchild);
	}
	return;
}

//后序遍历
void postOrder(BiNode *root)
{
	if (root != NULL)
	{
		printf("%d ", root->data);
		postOrder(root->lchild);
		postOrder(root->rchild);
	}
	return;
}

//例1 求叶子节点的数目
//先序,中序,后序得到的结果都是一样的,因为这3种算法的访问路径是相同的,只是访问节点的时机不同.
void countLeafNum(BiNode *root, int *num)
{
	if (root != NULL)
	{
		if (root->lchild ==NULL && root->rchild == NULL)//先root再左右,用的是先序遍历
		{
			(*num)++;
		}
		countLeafNum(root->lchild, num);//递归遍历左子树
		countLeafNum(root->rchild, num);//递归遍历右子树
	}
}

//例2 求树的深度
int GetDepth(BiNode *root)
{
	int depth = 0;
	int depthleft = 0;
	int depthright = 0;

	if (root == NULL)
	{
		depth = 0;
		return depth;
	}
	depthleft = GetDepth(root->lchild);
	depthright = GetDepth(root->rchild);
	depth = (depthleft > depthright) ? depthleft : depthright;
	++depth;//加上头节点深度1
	return depth;
}

//例3 递归拷贝树
BiNode *copyTree(BiNode *T)
{
	BiNode *newLptr = NULL;
	BiNode *newRptr = NULL;
	BiNode *newNode = NULL;
	//拷贝左子树
	if (T->lchild != NULL)
	{
		newLptr = copyTree(T->lchild);
	}
	else
	{
		newLptr = NULL;
	}

	//拷贝右子树
	if (T->rchild != NULL)
	{
		newRptr = copyTree(T->rchild);
	}
	else
	{
		newRptr = NULL;
	}
	newNode = (BiNode*)malloc(sizeof(BiNode));
	if (newNode == NULL)
	{
		return NULL;
	}
	//打造节点关系
	newNode->lchild = newLptr;
	newNode->rchild = newRptr;
	newNode->data = T->data;
	return newNode;
}

int main()
{
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
	t1.lchild = &t2;
	t1.rchild = &t3;
	t2.lchild = &t4;
	t3.lchild = &t5;

	inOrder(&t1);
	printf("\n");
	preOrder(&t1);
	printf("\n");
	postOrder(&t1);
	printf("\n");

	int num = 0;
	countLeafNum(&t1, &num);
	printf("叶子节点总数: %d\n ", num);

	printf("树的高度为: %d\n ", GetDepth(&t1));

	BiNode *root = NULL;
	root = copyTree(&t1);
	inOrder(root);//打印查看copy的对不对

	system("pause");
	return 0;
}
