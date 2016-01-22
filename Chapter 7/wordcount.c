#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<stdlib.h>
#define STOP '|'
int main(void)
{
	char c;
	char cprv;
	long n_chars = 0;
	int n_words = 0;
	int n_lines = 0;
	int p_lines = 0;
	bool isword = false;
	
	printf("Enter text to be analyzed (| to terminate):\n");
	cprv = '\n';
	while((c = getchar()) != STOP)
	{
		n_chars++;
		if(c == '\n')
		   n_lines++;
		if(!isspace(c) && !isword)
        {
        	isword = true;
		    n_words++;
        }
        if(isspace(c) && isword)
           isword = false;
        cprv = c;
	}
	if(cprv != '\n')
	   p_lines = 1;
    printf("characters = %ld, words = %d, lines = %d, partial lines = %d\n",n_chars,n_words,n_lines,p_lines);
    system("PAUSE");
    return 0;
}
