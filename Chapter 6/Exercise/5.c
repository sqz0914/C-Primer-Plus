#include<stdio.h>
int main(void)
{
	int n,low_n,upp_n;
	
	printf("Please input an integer to give the lower limit of the table:\n");
	scanf("%d",&low_n);
	printf("the upper limit of the table:\n");
	scanf("%d",&upp_n);
	printf("Integer   squared   cubed\n");
	
	for(n = low_n;n <= upp_n;n++)
	    printf("%-10d%-10d%-10d\n",n,n*n,n*n*n);
    return 0;
}
