#include<stdio.h>
int main(void)
{
	int n,n_cubed;
	printf("n   n cubed\n");
	for(n = 1;n <= 6;n++)
	{
		n_cubed = n*n*n;
		printf("%-4d%3d\n",n,n_cubed);
	}
	return 0;
}
