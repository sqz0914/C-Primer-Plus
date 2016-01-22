#include<stdio.h>
#define SIZE 81
int is_within(char ch, char * string);
int main(void)
{
	char input[SIZE];
	char ch;
	char * find;
	
    puts("Please enter a string(q to qiut):");
    gets(input);
    while(*input != 'q')
    {
       	puts("Please enter the character you want find:");
        ch = getchar();
        getchar();
        if(is_within(ch,input))
        {
        	puts("Find!");
        }
        else
        {
        	puts("Not found!");
        }
        puts("Please enter a string(q to qiut):");
        gets(input);
    }
    
    puts("qiut!");
    
    return 0;
}
int is_within(char ch, char * string)
{
	while(*string)
	{
		if(*string == ch)
		   return 1;
        string++;
	}
	return 0;
}
