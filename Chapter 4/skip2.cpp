#include<stdio.h>
int main(void)
{
	int n;
	printf("Please enter three integers:\n");
	scanf("%*d %*d %d",&n);
	printf("The last integer is %d.\n",n);
	getchar();
	return 0;
}
