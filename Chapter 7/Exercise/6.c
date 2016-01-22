#include<stdio.h>
#define STOP '#'
int main(void)
{
	char ch;
	char prev = 0;
	int count = 0;
	
	printf("Please enter a string(# to end):\n");
	while((ch = getchar()) != STOP)
	{
		if(ch == 'i' && prev == 'e')
           count++;
        prev = ch;
	}
	printf("There are %d times of \'ei\'.\n",count);
	
	return 0;
}
