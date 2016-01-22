#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void initializeList(List * plist)
{
	plist->head = NULL;
	plist->end = NULL;
}

bool ListIsEmpty(const List * plist)
{
	if (plist->head == NULL)
		return true;
	else
		return false;
}

bool ListIsFull(const List * plist)
{
	Node * pnode;
	pnode = (Node *)malloc(sizeof(Node));
	if (pnode == NULL)
		return true;
	else
	{
		free(pnode);
		return false;
	}
}

unsigned int ListItemCount(const List * plist)
{
	unsigned int count = 0;
	Node * pscan = plist->head;
	if (pscan == NULL)
		return count;
	while (pscan != plist->end)
	{
		count++;
		pscan = pscan->next;
	}
	
	return ++count;
}

bool AddItem(Item item, List * plist)
{
	Node * pnew;
	pnew = (Node*)malloc(sizeof(Node));
	
	if (pnew == NULL)
		return false;

	if (plist->head == NULL)
	{
		plist->head = pnew;
		plist->end = pnew;
		plist->end->item = item;
		return true;
	}
	else
	{
		plist->end->next = pnew;
		plist->end = pnew;
		plist->end->item = item;
		plist->end->next = NULL;
		return true;
	}
}

void traverse(const List * plist, void(*pfun)(Item item))
{
	Node * pscan = plist->head;

	while (pscan != plist->end)
	{
		(*pfun)(pscan->item);
		pscan = pscan->next;
	}
	(*pfun)(pscan->item);
}

void EmptyTheList(List * plist)
{
	Node * psave;
	Node * pscan = plist->head;

	while (pscan != plist->end)
	{
		psave = pscan;
		pscan = pscan->next;
		free(psave);
	}
	free(pscan);
}
