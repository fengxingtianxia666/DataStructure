#include "iostream"
using namespace std;
#include "stack"

//STL实现非递归遍历中序算法

//二叉链表
typedef struct BiNode
{
	int data;
	struct BiNode  *lchild, *rchild;
}BiNode, *BiTree;

BiNode *GoFarLeft(BiNode *T, stack<BiNode *> &s)
{
	if (T == NULL)
	{
		return NULL;
	}

	while (T->lchild)//只要有左孩子就入栈
	{
		s.push(T);
		T = T->lchild;
	}
	return T;
}

void Inorder_I(BiTree T)
{
	stack<BiNode *> s;
	BiTree t = GoFarLeft(T, s);//一直往左走,找到中序遍历的起点
	while (t)
	{
		printf("%d ", t->data);//找到节点,访问
		if (t->rchild != NULL)//如果t有右子树,查找右子树中最左下的节点
		{
			t = GoFarLeft(t->rchild, s);
		}
		else if (!s.empty())//如果t没有右子树,访问栈顶元素
		{
			t = (BiTree)s.top();
			s.pop();
		}
		else//如果t没有右子树,且栈为空,递归结束
		{
			t = NULL;
		}
	}
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

	t1.lchild = &t2;
	t1.rchild = &t3;
	t2.lchild = &t4;
	t3.lchild = &t5;

	Inorder_I(&t1);//把根节点传过去
	system("pause");
	return 0;
}
