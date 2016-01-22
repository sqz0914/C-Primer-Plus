#include<stdio.h>
#include<ctype.h>
int report(char ch);
int main(void)
{
	char ch;
	
	while((ch = getchar()) != EOF)
	{
		if(isalpha(ch))
		   printf("%c is letter %d.\n",ch,report(ch));
        else
           printf("%c is not a letter.\n",ch);
	}
	printf("Bye!\n");
	
	return 0;
}

int report(char ch)
{
	return toupper(ch) - 'A' + 1;
}
