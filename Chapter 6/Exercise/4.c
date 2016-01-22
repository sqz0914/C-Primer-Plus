#include<stdio.h>
int main(void)
{
	char ch1,ch2,ch3;
	int ROWS,row,i;
	
	printf("Please enter an uppercase letter:\n");
	scanf("%c",&ch1);
	ROWS = ch1 - 'A' + 1;
	for(row = 1;row <= ROWS;row++)
	{
		for(i = ROWS;i > row;i--)
		    printf(" ");
		for(ch2 = 'A';ch2 < 'A' + row;ch2++)
		    printf("%c",ch2);
		for(ch3 = 'A'+ row - 2;ch3 >= 'A';ch3--)
		    printf("%c",ch3);
		printf("\n");
	}
	return 0;
}
