#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define TSIZE 45

struct film {
	char title[TSIZE];
	int rating;
	struct film * next;
};

void show_rec(struct film * plist);

int main(void)
{
	struct film * head = NULL;
	struct film * prev, * current;
	char input[TSIZE];

	puts("Enter first movie title:");
	while (gets(input) != NULL && input[0] != '\0')
	{
		current = (struct film *)malloc(sizeof(struct film));
		if (head == NULL)
			head = current;
		else
			prev->next = current;
		current->next = NULL;
		strcpy(current->title, input);
		puts("Enter your rating <0-10>:");
		scanf("%d", &current->rating);
		while (getchar() != '\n')
			continue;
		puts("Enter next movie title(empty line to qiut):");
		prev = current;
	}

	if (head == NULL)
		puts("No data entered.");
	else
		puts("Here is the movie list:");
	current = head;
	while (current != NULL)
	{
		printf("Movie: %s       Rating:%d\n", current->title, current->rating);
		current = current->next;
	}

	if (head != NULL)
	{
		puts("Here is the reversed movie list:");
		show_rec(head);
	}

	puts("Bye!");
	system("PAUSE");

	return 0;
}

void show_rec(struct film * plist)
{
	if (plist->next != NULL)
		show_rec(plist->next);
	printf("Movie: %s       Rating:%d\n", plist->title, plist->rating);
		
}