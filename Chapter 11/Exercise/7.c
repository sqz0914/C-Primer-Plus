#include<stdio.h>
#define SIZE 81
char * string_in(char * s1, char * s2);
int main(void)
{
	char s1[SIZE];
	char s2[SIZE];
	char * find;
	
	puts("Please enter a string(# to qiut):");
	gets(s1);
	while(*s1 != '#')
	{
		puts("Please enter another string:");
		gets(s2);
		
		find = string_in(s1,s2);
		if(find)
		   puts("s2 is contained in s1.");
        else
           puts("s2 is not contained in s1.");
        puts("Please enter a string(# to qiut):");
	    gets(s1);
	}
	puts("qiut!");
	
	return 0;
}
char * string_in(char * s1, char * s2)
{
    char * s1_save = s1;
    char * s2_save = s2;
    
    if(s1 == '\0' || s2 == '\0')
       return NULL;
    while(1)
    {
    	if(*s1 == *s2)
    	{
	    	if(*++s2 == '\0')
	    	  return s1_save;
   	        if(*++s1 == '\0')
   	          return NULL;
	    }
	    else
	    {
    		if(*++s1 == '\0')
    		  return NULL;
  		    s1_save = s1;
  		    s2 = s2_save;
    	}
    }
}
