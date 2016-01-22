#include<stdio.h>
#define STOP '#'
int main(void)
{
	char ch;
	
	while((ch = getchar()) != STOP)
	{
		putchar(ch);
	}
	
	return 0;
}
