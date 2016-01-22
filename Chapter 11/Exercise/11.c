#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#define SIZE 255 
int main(void)
{
	int i,wordcount,uppcount,lowcount,puncount,digitcount;
	bool inword = false;
	char input[SIZE];
	
	wordcount = uppcount = lowcount = puncount = digitcount = 0;
	puts("Please enter some words:");
	gets(input);
	for(i = 0;input[i] != '\0';i++)
	{
		if(isalpha(input[i]))
		{
			if(!inword)
			{
				wordcount++;
				inword = true;
			}
		}
		else
            inword = false;
        if(isupper(input[i]))
           uppcount++;
        if(islower(input[i]))
           lowcount++;
        if(ispunct(input[i]))
           puncount++;
        if(isdigit(input[i]))
           digitcount++;
        
	}
	
	printf("the number of words: %d\n",wordcount);
	printf("the number of uppercase letter: %d\n",uppcount);
	printf("the number of lowercase letter: %d\n",lowcount);
	printf("the number of punctuation: %d\n",puncount);
	printf("the number of digits: %d\n",digitcount);
	
	return 0;
}