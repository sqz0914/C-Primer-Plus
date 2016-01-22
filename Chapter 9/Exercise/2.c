#include<stdio.h>
void chline(char ch, int i, int j);
int main(void)
{
	char ch;
	int i,j;
	
	printf("Please enter the character:");
	scanf("%c",&ch);
	printf("Please enter two integers:");
	scanf("%d %d",&i,&j);
	chline(ch,i,j);
	
	return 0;
}

void chline(char ch, int i, int j)
{
	int k;
	for(k = 1;k <= i;k++)
        putchar(' ');
	for(;k <= j;k++)
        putchar(ch);
    putchar('\n');
}

