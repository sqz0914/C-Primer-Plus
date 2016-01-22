#include<stdio.h>
int main(void)
{
	int countchar;
	
	printf("Please enter some characters:\n");
	for(countchar = 0;getchar() != EOF;countchar++)
	    continue;
    printf("The number of the characters your just enter is %d.\n",countchar);
    return 0;
}
