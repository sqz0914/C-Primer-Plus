#include<stdio.h>
void chline(char ch, int row, int col);
int main(void)
{
	char ch;
	int row,col;
	
	printf("Please enter the character:");
	scanf("%c",&ch);
	printf("Please enter two integers:");
	scanf("%d %d",&row,&col);
	chline(ch,row,col);
	
	return 0;
}

void chline(char ch, int row, int col)
{
	int i,j;
	for(i = 1;i <= row;i++)
    {
    	for(j = 1;j <= col;j++)
    	    putchar(ch);
	    putchar('\n');
    }
}

