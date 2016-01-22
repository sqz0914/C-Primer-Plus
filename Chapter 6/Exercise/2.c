#include<stdio.h>
#define ROW 5
int main(void)
{
	int row,i;
	
	for(row = 1;row <= ROW;row++)
	{
		for(i = 1;i <= row;i++)
		    printf("$");
        printf("\n");
	}
	return 0;
}
