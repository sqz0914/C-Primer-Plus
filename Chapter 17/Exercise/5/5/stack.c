#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void InitializeStack(Stack * ps)
{
	ps->top = 0;
}

bool StackIsEmpty(Stack * ps)
{
	return (ps->top == 0);
}

bool StackIsFull(Stack * ps)
{
	return (ps->top == MAXSTACK);
}

bool Push(Item item, Stack * ps)
{
	if (StackIsFull(ps))
		return false;
	else
	{
		ps->item[ps->top] = item;
		ps->top++;
		return true;
	}
}

bool Pop(Item * item, Stack * ps)
{
	if (StackIsEmpty(ps))
		return false;
	else
	{
		ps->top--;
		*item = ps->item[ps->top];
		return true;
	}
}