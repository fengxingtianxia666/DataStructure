#pragma once


//¾Í½üÆ¥Åä³¡¾°
//±àÒëÆ÷×óÓÒ·ûºÅÆ¥Åä

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "linkstack.h"

int isLeft(char c)
{
	int ret = 0;
	switch (c)
	{
	case '<':
	case '(':
	case '[':
	case '{':
	case '\'':
	case '\"':
		ret = 1;
	default:
		ret = 0;
		break;
	}
	
	return ret;
}

int isRight(char c)
{
	int ret = 0;
	switch (c)
	{
	case '>':
	case ')':
	case ']':
	case '}':
	case '\'':
	case '\"':
		ret = 1;
	default:
		ret = 0;
		break;
	}

	return ret;
}

int match(char left, char right)
{
	int ret = 0;
	switch (left)
	{
	case '<':
		ret = (right == '>');
		break;
	case '(':
		ret = (right == ')');
		break;
	case '[':
		ret = (right == ']');
		break;
	case '{':
		ret = (right == '}');
		break;
	case '\'':
		ret = (right == '\'');
		break;
	case '\"':
		ret = (right == '\"');
		break;
	default:
		ret = 0;
		break;
	}
}

int Scanner(const char *code)
{
	int ret = 0;
	char *ptmp = code;
	int i = 0;
	if (code == NULL)
	{
		ret = -1;
		printf("ScanfCode code == NULL");
		return ret;
	}
	LinkStack *stack = LinkStack_Create();
	if (stack == NULL)
	{
		ret = -2;
		return ret;
	}

	while (code[i] != '\0')
	{
		if (isLeft(code[i]))
		{
			LinkStack_Push(stack, (void *)code[i]);
		} 
		else if (isRight(code[i]))
		{
			char top = *(char*)(LinkStack_Pop(stack));
			if ((top == NULL) || !match(top, code[i]))
			{
				ret = -3;
				printf("%c does not match! \n", code[i]);
				break;
			}
		}

		++i;
	}

	if (LinkStack_Size(stack) > 0)
	{
		ret = -4;
		printf("Invalid code \n");
		return ret;
	}
	else
	{
		printf("succeed \n");
	}
	return ret;
}