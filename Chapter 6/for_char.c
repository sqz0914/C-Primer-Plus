#include<stdio.h>
int main(void)
{
	char count;
	for(count = 'a';count <= 'z';count++)
	   printf("The ASCII value for %c is %d.\n",count,count);
    return 0;
}
