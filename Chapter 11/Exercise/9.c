#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define LINE 20
#define SIZE 81
void delspace(char * string);
int main(void)
{
	char input[LINE][SIZE];
	int i = 0;
	
	puts("Please enter some lines of strings:");
	while(i < LINE && gets(input[i]) != '\0' && input[i][0] != '\0')
	{
		delspace(input[i]);
		puts(input[i]);
		i++;
	}
    
    return 0;
}
void delspace(char * string)
{
	char * find;
	
	while(*string != '\0')
	{
		if(*string == ' ')
		{
			find = string;
			while(*find != '\0')
			{
				*find = *(find + 1);
				find++;
			}
			string--;
		}
		string++;
	}
}
