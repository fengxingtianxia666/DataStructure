#include <stdio.h>
#include "LinkStack.h"

int isNumber3(char c)
{
	return ('0' <= c) && (c <= '9');
}

int isOperator3(char c)
{
	return (c == '+') || (c == '-') || (c == '*') || (c == '/');
}

int value(char c)
{
	return (c - '0');
}

int express(int left, int right, char op)
{
	int ret = 0;

	switch(op)
	{
	case '+':
		ret = left + right;
		break;
	case '-':
		ret = left - right;
		break;
	case '*':
		ret = left * right;
		break;
	case '/':
		ret = left / right;
		break;
	default:
		break;
	}

	return ret;
}

int compute(const char* exp)
{
	LinkStack* stack = LinkStack_Create();
	int ret = 0;
	int i = 0;

	while( exp[i] != '\0' )//遍历后缀表达式
	{
		if( isNumber3(exp[i]) )//若是数字,直接入栈
		{
			LinkStack_Push(stack, (void*)value(exp[i]));
		}
		else if( isOperator3(exp[i]) )//若是运算符
		{
			int right = (int)LinkStack_Pop(stack);//从栈中弹出右操作数
			int left = (int)LinkStack_Pop(stack);//从栈中弹出左操作数
			int result = express(left, right, exp[i]);//根据运算符进行运算

			LinkStack_Push(stack, (void*)result);//将运算结果入栈
		}
		else
		{
			printf("Invalid expression!");
			break;
		}

		i++;
	}

	if( (LinkStack_Size(stack) == 1) && (exp[i] == '\0') )//遍历后缀表达式结束,若栈中还剩一个数字,即最后结果
	{
		ret = (int)LinkStack_Pop(stack);
	} 
	else 
	{
		printf("Invalid expression!");
	}

	LinkStack_Destroy(stack);

	return ret;
}

int mainhc()
//int main()
{
	printf("8 + (3 - 1) * 5  = %d\n", compute("831-5*+"));
	system("pause");
	return 0;
}
