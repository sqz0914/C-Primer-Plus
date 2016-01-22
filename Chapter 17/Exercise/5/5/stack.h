#ifndef STACK_H_
#define STACK_H_
#include <stdbool.h>

typedef char Item;

#define MAXSTACK 100

typedef struct stack {
	Item item[MAXSTACK];
	int top;
} Stack;

void InitializeStack(Stack * ps);

bool StackIsEmpty(Stack * ps);

bool StackIsFull(Stack * ps);

bool Push(Item item, Stack * ps);

bool Pop(Item * item, Stack * ps);

#endif