#include<stdio.h>
#include<string.h>
#define SIZE 81
int AtoI(char * string);
int main(void)
{
	char input[SIZE];
	
	puts("Please enter some numbers:");
	gets(input);
	printf("The number you enter is %d.\n",AtoI(input));
	
	return 0;
}
int AtoI(char * string)
{
	int n = 0;
	while(*string != '\0')
	{
	   if(isdigit(*string))
	   n = n * 10 + *string - '0';
	   string++;	
	}
	
	return n;
}
