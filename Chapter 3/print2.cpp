#include<stdio.h>
int main(void)
{
	unsigned int un = 3000000000;
	short end = 200;
	long big = 65537;
	long long verybig = 1234567890;
	
	printf("un = %u and not %d\n",un,un);
	printf("end = %hd and not %d\n",end,end);
	printf("big = %ld and not %hd\n",big,big);
	printf("verybig = %lld and nit %ld\n",verybig,verybig);
	getchar();
	return 0;
}