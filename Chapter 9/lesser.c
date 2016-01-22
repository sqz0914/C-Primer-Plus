#include<stdio.h>
int imin(int a, int b);
int main(void)
{
	int a;
	int b;
	
	printf("Enter a pair of integers (q to qiut):\n");
	while(scanf("%d %d",&a,&b) == 2)
	{
		printf("The lesser of %d and %d is %d.\n",a,b,imin(a,b));
		printf("Enter a pair of integers (q to qiut):\n");
	}
	printf("Bye!\n");
	
	return 0;
}

int imin(int a,int b)
{
	int min;
	if(a > b)
	min = b;
	else
	min = a;
	
	return min;
}
