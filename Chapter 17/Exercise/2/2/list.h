#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>

/* program-specific declarations */
#define TSIZE 45
typedef struct film {
	char title[TSIZE];
	int rating;
} Item;

typedef struct node{
	Item item;
	struct node * next;
} Node;
typedef struct list {
	Node * head;
	Node * end;
} List;

/* function prototypes */
/* operation:        initialize a list  */
/* precondition:     plist points to a list */
/* postcondition:     the list is initialized to empty */
void initializeList(List * plist);

/* operation:       determine if list is empty */
/* precondition:    plist points to a list */
/* postcondition:    function returns True if list is empty
                    and returns False otherwise */
bool ListIsEmpty(const List * plist);

/* operation:       determine if list is full */
/* precondition:     plist points to a list */
/* postcondition:    function returns True if list is full
                    and returns False otherwise */
bool ListIsFull(const List * plist);

/* operations:      determine number of items in list*/
/* precondition:    plist points to a list */
/* postcondition:   function returns number of items in list*/
unsigned int ListItemCount(const List * plist);

/* operations:      add item to end of list */
/* precondition:    plist point to a list */
/* postcondition:   if possible, function adds item to end
                    of list and returns True; otherwise the
					function returns false */
bool AddItem(Item item, List * plist);

/* operations:      apply a function to each item in list */
/* precondition:    plist points to a list 
                    pfun points to a function that takes an 
					Item argument and has no return value */
/* postcondition:   the function pointed to by pfun is 
                    executed once for each item in the list*/
void traverse(const List * plist, void (* pfun)(Item item));

/* operations:      free allocated memory, if any */
/* precondition:    plist points to an initialized list */
/* postcondition:   any memory allocated for the list is freed
                    and the list is set to empty */
void EmptyTheList(List * plist);

#endif
                    