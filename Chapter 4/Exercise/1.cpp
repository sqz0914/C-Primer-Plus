#include<stdio.h>
int main(void)
{
	char first[20],last[20];
	printf("Please enter your first name and last name:\n");
	scanf("%s %s",first,last);
	printf("Your name is %s %s.\n",first,last);
	getchar();
	return 0;
}
