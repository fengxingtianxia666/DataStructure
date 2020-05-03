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

//��׺���ʽ���Ǹ����ȼ����Ϸ�ǰ��,�����ȼ��ź���
void transform(const char* exp)
{
	int i = 0;
	LinkStack* stack = LinkStack_Create();

	while( exp[i] != '\0' )//������׺���ʽ
	{
		if( isNumber(exp[i]) )//��������,ֱ�����
		{
			output(exp[i]);
		}
		else if( isOperator(exp[i]) )//���������,Ҫ��ջ�з��ϱȽ����ȼ�.��ǰ�������ջ�и�,��ֱ����ջ,��ջ�е�,���ȳ�ջ���,ֱ���Լ���ջ�и�,����ջ
		{
			while( priority(exp[i]) <= priority((char)(int)LinkStack_Top(stack)) )
			{
				output((char)(int)LinkStack_Pop(stack));
			}

			LinkStack_Push(stack, (void*)(int)exp[i]);
		} 
		else if( isLeft(exp[i]) )//����������,ֱ����ջ
		{
			LinkStack_Push(stack, (void*)(int)exp[i]);
		} 
		else if( isRight(exp[i]) )//����������,ջ�����ŵ��������,ֱ��ƥ��������
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

	while( (LinkStack_Size(stack) > 0) && (exp[i] == '\0') )//������׺���ʽ������,��ջ�л��������,��ջ�����.
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
