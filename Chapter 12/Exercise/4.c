#include <stdio.h>
int called(void);
int main(void)
{
	int i;
	for(i = 0;i < 5;i++)
	    printf("called() has been called %d times.\n",called());
	    
    return 0;
}
int called(void)
{
	static int count = 0;
	count++;
	
	return count;
}
