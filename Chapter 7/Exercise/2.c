#include<stdio.h>
#define STOP '#'
int main(void)
{
	char ch;
	int count = 0;
	
	printf("Please enter a string(enter # to end):\n");
	while((ch = getchar()) != STOP)
	{
		count++;
		printf("%c--%d\t",ch,ch);
		if(count%8 == 0)
		  printf("\n");
	}
	printf("\n");
	
	return 0;
}
