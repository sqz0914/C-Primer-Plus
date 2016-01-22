#include <stdio.h>
#include "stack.h"
#define SLEN 81

int main(void)
{
	Stack stch;
	char input[SLEN];
	int i;
	char ch;

	InitializeStack(&stch);
	puts("Enter a line (empty line to qiut):");
	while (gets(input) != NULL && input[0] != '\0')
	{
		i = 0;
		while (input[i] != '\0' && !StackIsFull(&stch))
		{
			Push(input[i], &stch);
			i++;
		}
		while (!StackIsEmpty(&stch))
		{
			Pop(&ch, &stch);
			putchar(ch);
		}
		putchar('\n');
		puts("Next line (empty line to qiut):");
	}
	puts("Bye!");

	return 0;
}