#include<stdio.h>
#include<string.h>
#define SIZE 81
void reverse(char * string, int n);
int main(void)
{
	char input[SIZE];
	
	puts("Please enter a string (# to qiut):");
	gets(input);
	
	while(*input != '#')
	{
		reverse(input,strlen(input));
		puts("Now,the string is:");
		puts(input);
		puts("Please enter a string (# to qiut):");
	    gets(input);
	}
	puts("qiut");
	
	return 0;
}
void reverse(char * string, int n)
{
	int i;
	char temp;
	for(i = 0;i < n / 2;i++)
	{
		temp = string[i];
		string[i] = string[n - i -1];
		string[n - i -1] = temp;
	}
}
