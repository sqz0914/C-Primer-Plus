#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"

void printitem(Item item);
char menu(void);
void showwords(const Tree * pt);
void findword(const Tree * pt);

int main(void)
{
	Tree wordcount;
	FILE * fp;
	char filename[SLEN];
	char word[SLEN];
	Item entry;
	char choice;

	puts("Enter the filename you want to process:");
	gets(filename);

	if ((fp = fopen(filename, "r")) == NULL)
	{
		fprintf(stderr, "Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	
	InitializeTree(&wordcount);
	while (fscanf(fp, "%s", word) == 1 && !TreeIsFull(&wordcount))
	{
		strcpy(entry.word, word);
		AddItem(&entry, &wordcount);
	}

	while ((choice = menu()) != 'q')
	{
		switch (choice)
		{
		case 's': showwords(&wordcount);
			      break;
		case 'l': findword(&wordcount);
			      break;
		default : puts("Switch Error!");
			      break;
		}
	}
	fclose(fp);
	puts("Bye!");

	return 0;
}

char menu(void)
{
	int ch;
	puts("Word Counting Program");
	puts("Word counting program");
	puts("Enter the letter corresponding to your choice:");
	puts("s) show word list     f) find a word");
	puts("q) quit");
	while ((ch = getchar()) != EOF)
	{
		while (getchar() != '\n')
			continue;
		ch = tolower(ch);
		if (strchr("sfq", ch) == NULL)
			puts("Please enter s, f, q ");
		else
			break;
	}
	if (ch == EOF)
		ch = 'q';

	return ch;
}

void printitem(Item item)
{
	printf("Word: %s    Times: %d", item.word, item.count);
}

void showwords(const Tree * pt)
{
	if (TreeIsEmpty(pt))
		puts("No entries!");
	else
		Traverse(pt, printitem);
}

void findword(const Tree * pt)
{
	char word[SLEN];
	Item entry;
	if (TreeIsEmpty(pt))
	{
		puts("No entries!");
		return;
	}
	
	puts("Enter the word you want to find:");
	scanf("%s", word);
	while (getchar() != '\n')
		continue;
	strcpy(entry.word, word);
	if (InTree(&entry, pt))
		printf("%s appears %d times.\n", word, entry.count);
	else
		printf("%s is not found.\n", word);
}