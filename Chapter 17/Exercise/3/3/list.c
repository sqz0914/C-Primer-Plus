#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void initializeList(List * plist)
{
	plist->items = 0;
}

bool ListIsEmpty(const List * plist)
{
	if (plist->items == 0)
		return true;
	else
		return false;
}

bool ListIsFull(const List * plist)
{
	if (plist->items == MAXSIZE)
		return true;
	else
		return false;
}

unsigned int ListItemCount(const List * plist)
{
	return plist->items;
}

bool AddItem(Item item, List * plist)
{
	if (plist->items == MAXSIZE)
		return false;
	else
	{
		plist->entries[plist->items] = item;
		plist->items++;
		return true;
	}
}

void traverse(const List * plist, void(*pfun)(Item item))
{
	int i;
	for (i = 0; i < plist->items; i++)
		(*pfun)(plist->entries[i]);
}

void EmptyTheList(List * plist)
{
	plist->items = 0;
}
