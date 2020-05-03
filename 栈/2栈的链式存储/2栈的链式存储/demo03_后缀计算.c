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

	while( exp[i] != '\0' )//������׺���ʽ
	{
		if( isNumber3(exp[i]) )//��������,ֱ����ջ
		{
			LinkStack_Push(stack, (void*)value(exp[i]));
		}
		else if( isOperator3(exp[i]) )//���������
		{
			int right = (int)LinkStack_Pop(stack);//��ջ�е����Ҳ�����
			int left = (int)LinkStack_Pop(stack);//��ջ�е����������
			int result = express(left, right, exp[i]);//�����������������

			LinkStack_Push(stack, (void*)result);//����������ջ
		}
		else
		{
			printf("Invalid expression!");
			break;
		}

		i++;
	}

	if( (LinkStack_Size(stack) == 1) && (exp[i] == '\0') )//������׺���ʽ����,��ջ�л�ʣһ������,�������
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
