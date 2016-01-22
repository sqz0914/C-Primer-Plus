#include<stdio.h>
#include<string.h>
#define LIM 20
#define SIZE 81
#define HALT ""
void strsort(char * string[], int num);
int main(void)
{
	char input[LIM][SIZE];
	char * ptr[LIM];
	int ct = 0;
	int k;
	
	printf("Input up to %d lines, and I will sort them.\n",LIM);
	printf("To stop, press the enter key at a line's start.\n");
	while(ct < LIM && gets(input[ct]) != NULL && input[ct][0] != '\0')
	{
		ptr[ct] = input[ct];
		ct++;
	}
	strsort(ptr,ct);
	printf("\nHere's the sorted list:\n");
	for(k = 0;k < ct;k++)
	    puts(ptr[k]);
	
	return 0;
}
void strsort(char * string[], int num)
{
	char * temp;
	int top,seek;
	
	for(top = 0;top < num - 1;top++)
	{
		for(seek = top + 1;seek < num;seek++)
		{
			if(strcmp(string[top],string[seek]) > 0)
		      {
			      temp = string[top];
			      string[top] = string[seek];
			      string[seek] = temp;
		      }
		}
	}
}
