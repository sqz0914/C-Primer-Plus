#include<stdio.h>
#include<string.h>
#define SIZE 81
void fetword(char * string);
int main(void)
{
	char input[SIZE];
	int n;
	
	puts("Please enter some words in a line:");
	gets(input);
	fetword(input);
	puts(input);
	
	return 0;
}
void fetword(char * string)
{
    int begin,end;
    for(begin = 0;isspace(*(string + begin));begin++);
    for(end = begin;!isspace(*(string + end));end++);
    *(string + end) = '\0';
    for(;*(string + begin) !='\0';string++)
        *string = *(string + begin);
    *string = '\0';
}


