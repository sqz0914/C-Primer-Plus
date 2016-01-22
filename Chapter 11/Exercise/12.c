#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 81
int main(void)
{
	char input[SIZE];
	char temp;
	int i,j,n,length;
	gets(input);
	for(i = 0,n = strlen(input);i < n/2;i++)
	{
		temp = input[i];
		input[i] = input[n - i - 1];
		input[n - 1 - i] = temp;
	}
	i = 0;
	length = 0;
	do
	{
		if(isalpha(input[i]))
		   length++;
        else
        {
        	if(length > 1)
        	{
	        	for(j = 0;j < length/2;j++)
	        	{
	        		temp = input[i - 1 - j];
	        		input[i - 1 - j] = input[i - length + j];
	        		input[i - length + j] = temp;
	        	}
	        }
	        length = 0;
        }
	}
	while(input[i++] != '\0');
	puts(input);
	
	return 0;
}