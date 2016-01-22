#include<stdio.h>
int main(void)
{
	int n = 0;
	size_t intsize;
	
	intsize = sizeof(int);
	printf("n = %d,n has %d bytes;all int has %d bytes.\n",n,sizeof(n),intsize);
	getchar();
	return 0;
}
