#include<stdio.h>
#define ROW 6
int main(void)
{
	int row;
	char i;
	
	for(row = 1;row <= ROW;row++)
	{
		for(i = 'F';i > 'F' - row;i--)
		   printf("%c",i);
        printf("\n");
	}
	return 0;
}
