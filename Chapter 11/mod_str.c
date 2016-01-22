#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 80
void ToUpper(char * string);
int PunctCount(const char * string);
int main(void)
{
	char line[MAX];
	
	puts("Please enter a line:");
	gets(line);
	ToUpper(line);
	puts(line);
	printf("That line has %d punctuation characters.\n",PunctCount(line));
	
	return 0;
}
void ToUpper(char * string)
{
	while(*string)
	{
		*string = toupper(*string);
		string++;
	}
}
int PunctCount(const char * string)
{
	int count = 0;
	while(*string)
	{
		if(ispunct(*string))
		   count++;
        string++;
	}
	
	return count;
}
