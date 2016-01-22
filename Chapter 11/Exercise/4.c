#include<stdio.h>
#define SIZE 81
char * ptr(char * string, char ch);
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
        find = ptr(input,ch);
        if(find)
	    {
		  puts("Find!");
		  puts(find);
	    }
	    else
	      puts("Not found!");
        puts("Please enter a string(q to qiut):");
        gets(input);
	}
    puts("Qiut!");
	      
    return 0;
}
char * ptr(char * string, char ch)
{
	char * find;
	if(*string == '\0')
	   return NULL;
	while(*string)
	{
		if(*string == ch)
        {
            find = string;
            return find;
        }
        string++;
	}
	return NULL;
}
