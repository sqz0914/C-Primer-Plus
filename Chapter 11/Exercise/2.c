#include<stdio.h>
#define SIZE 81
void fetchar(char * string, int n);
int main(void)
{
	char input[SIZE];
	int n;
	
	puts("Please enter the char number of your string:");
	scanf("%d",&n);
	getchar();
	puts("Please enter a string:");
	fetchar(input,n);
	puts(input);
	
	return 0;
}
void fetchar(char * string, int n)
{
	int i;
	for(i = 0;i < n;i++)
	{
		*(string + i) = getchar();
		if(isspace(*(string + i)))
		   *(string + i) = '\0';
	}
}

