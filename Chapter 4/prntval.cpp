#include<stdio.h>
int main(void)
{
	int F = 212;
	int rv;
	rv = printf("%d F is water's boiling point.\n",F);
	printf("The printf() function printed %d characters.\n",rv);
	getchar();
	return 0;
}
