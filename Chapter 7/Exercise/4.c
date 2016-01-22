#include<stdio.h>
#define STOP '#'
int main(void)
{
	char ch;
	int count1 = 0;
	int count2 = 0;
	
	printf("Please enter a string(# to end):\n");
	while((ch = getchar()) != STOP)
	{
		if(ch == '.')
        {
        	ch = '!';
        	putchar(ch);
        	count1++;
        }
        else if(ch == '!')
        {
        	putchar(ch);
        	putchar(ch);
        	count2++;
        }
        else
		    putchar(ch);  
	}
	
	printf("\".\" is replaced %d times and \"!\" is replaced %d times.\n",count1,count2);
	return 0;
}
