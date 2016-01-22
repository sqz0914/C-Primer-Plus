#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
int main(void)
{
	char ch;
	int countletter = 0;
	int countword = 0;
	bool inword;
	
	inword = false;
	printf("Please enter some strings:\n");
	while((ch = getchar()) != EOF)
	{
		if(isalpha(ch))
		countletter++;
		if(!isspace(ch) && !inword &&!ispunct(ch))
        {
        	countword++;
        	inword = true;
        }
        if((isspace(ch) || ispunct(ch)) && inword)
            inword = false;	    
	}
	printf("the average number of letters per word is %.3g",(double)countletter/(double)countword);
	
	return 0;
}
