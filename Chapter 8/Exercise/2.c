#include<stdio.h>
int main(void)
{
	char ch;
	int count;
	
	printf("Please enter some characters:\n");
	for(count = 1;(ch = getchar()) != EOF;count++)
	{
		if(ch >= ' '||ch == '\n'||ch == '\t')
		printf("%-4c",ch);
		else if(ch < ' ')
		printf("^%c  ",ch + 64);
		else
		printf("%-4c",ch);
		printf("--%-4d",ch);
		if(count%10 == 0)
		printf("\n");
	}
	return 0;
}
