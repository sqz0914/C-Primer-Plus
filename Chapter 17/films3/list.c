#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static void CopyToNode(Item item, Node * pnode);

void initializeList(List * plist)
{
	* plist = NULL;
}

bool ListIsEmpty(const List * plist)
{
	if(*plist == NULL)
	  return true;
    else
      return false;
}

bool ListIsFull(const List * plist)
{
	Node * pnode;
    bool full;
    
    pnode = (Node *)malloc(sizeof(Node));
    if(pnode == NULL)
      full = true;
    else
      full = false;
	  
	return full; 
}

unsigned int ListItemCount(const List * plist)
{
	Node * pnode;
	unsigned int count = 0;
	
	pnode = *plist;
	while(pnode != NULL)
	{
		count++;
		pnode = pnode->next;
	}
	
	return count;
}

bool AddItem(Item item, List * plist)
{
	Node * pnew;
	Node * scan = *plist;
	
	pnew = (Node *)malloc(sizeof(Node));
	if(pnew == NULL)
       return false;
    
    CopyToNode(item, pnew);
    pnew->next = NULL;
    if(scan == NULL)
       *plist = pnew;
    else
    {
    	while(scan->next != NULL)
    	     scan = scan->next;
        scan->next = pnew;
    }
    
    return true;
}

void traverse(const List * plist, void(* pfun)(Item item))
{
	Node * pnode;
	
	pnode = *plist;
	while(pnode != NULL)
	{
		(*pfun)(pnode->item);
		pnode = pnode->next;
	}
}

void EmptyTheList(List * plist)
{
	Node * psave;
	
	while(*plist != NULL)
	{
	    psave = (*plist)->next;
		free(*plist);
		*plist = psave;
	}
}

static void CopyToNode(Item item, Node * pnode)
{
	pnode->item = item;
}
