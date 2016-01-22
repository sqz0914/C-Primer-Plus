#include<stdio.h>
#define SIZE 81
char * Strcopy(char * s1, char * s2, int n);
int main(void)
{
	char input[SIZE];
	char copy[SIZE];
	int n;
	
	puts("Please enter the string(q to qiut):");
	gets(input);
	while(*input != 'q')
	{
		puts("Enter the number of characters you want to copy:");
		scanf("%d",&n);
		getchar();
		
		Strcopy(copy,input,n);
		puts("The copyed string is:");
		puts(copy);
		puts("Please enter the string(q to qiut):");
	    gets(input);
	}
	
	puts("qiut");
	
	return 0;
}
char * Strcopy(char * s1, char * s2, int n)
{
	int i;
	for(i = 0;i < n;i++)
	{
		s1[i] = s2[i];
	}
	s1[i] = '\0';
}
