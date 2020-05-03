#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "linkstack.h"

int isNumber(char c)
{
	return ('0' <= c) && (c <= '9');
}

int isOperator(char c)
{
	return (c == '+') || (c == '-') || (c == '*') || (c == '/');
}

int isLeft(char c)
{
	return (c == '(');
}

int isRight(char c)
{
	return (c == ')');
}

int priority(char c)
{
	int ret = 0;

	if( (c == '+') || (c == '-') )
	{
		ret = 1;
	}

	if( (c == '*') || (c == '/') )
	{
		ret = 2;
	}

	return ret;
}

void output(char c)
{
	if( c != '\0' )
	{
		printf("%c", c);
	}
}

//后缀表达式就是高优先级符合放前面,低优先级放后面
void transform(const char* exp)
{
	int i = 0;
	LinkStack* stack = LinkStack_Create();

	while( exp[i] != '\0' )//遍历中缀表达式
	{
		if( isNumber(exp[i]) )//若是数字,直接输出
		{
			output(exp[i]);
		}
		else if( isOperator(exp[i]) )//若是运算符,要跟栈中符合比较优先级.当前运算符比栈中高,则直接入栈,比栈中低,则先出栈输出,直到自己比栈中高,再入栈
		{
			while( priority(exp[i]) <= priority((char)(int)LinkStack_Top(stack)) )
			{
				output((char)(int)LinkStack_Pop(stack));
			}

			LinkStack_Push(stack, (void*)(int)exp[i]);
		} 
		else if( isLeft(exp[i]) )//若是左括号,直接入栈
		{
			LinkStack_Push(stack, (void*)(int)exp[i]);
		} 
		else if( isRight(exp[i]) )//若是右括号,栈顶符号弹出并输出,直到匹配左括号
		{
			//char c = '\0';
			while( !isLeft((char)(int)LinkStack_Top(stack)) )
			{
				output((char)(int)LinkStack_Pop(stack));
			}

			LinkStack_Pop(stack);
		}
		else
		{
			printf("Invalid expression!");
			break;
		}

		i++;
	}

	while( (LinkStack_Size(stack) > 0) && (exp[i] == '\0') )//遍历中缀表达式结束后,若栈中还有运算符,出栈并输出.
	{
		output((char)(int)LinkStack_Pop(stack));
	}

	LinkStack_Destroy(stack);
}

int mainzth()
//int main()
{
	transform("8+(3-1)*5");

	printf("\n");
	system("pause");
	return 0;
}
