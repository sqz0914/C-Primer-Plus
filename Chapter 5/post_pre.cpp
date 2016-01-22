#include<stdio.h>
int main(void)
{
	int a,b,aplus,bplus;
	a = b = 1;
	aplus = a++;
	bplus = ++b;
	
	printf("a   aplus  b   bplus\n");
	printf("%d %5d %4d %5d\n",a,aplus,b,bplus);
	getchar();
	return 0;
}
