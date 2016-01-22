#include<stdio.h>
#define STOP '#'
int main(void)
{
	char ch;
	int space = 0;
	int newline = 0;
	int other = 0;
	
	while((ch = getchar()) != STOP)
	{
		if(ch == ' ')
		   space++;
        else if(ch == '\n')
           newline++;
        else
           other++;
	}
	printf("the number of spaces = %d, the number of newline character = %d, "
	"the number of other character = %d\n",space,newline,other);
	
	return 0;
}
