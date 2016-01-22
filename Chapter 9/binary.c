#include<stdio.h>
void to_binary(unsigned long n);
int main(void)
{
    unsigned long n;
	
	printf("Enter an integer (q to qiut):\n");
	while(scanf("%lu",&n) == 1)
	{
		printf("Binary eqiuvalent: ");
		to_binary(n);
		printf("\n");
		printf("Enter an integer (q to qiut):\n");
	}
	printf("Done!\n");
	
	return 0;
}

void to_binary(unsigned long n)
{
	int r;
	
	r = n % 2;
	if( n >= 2)
	  to_binary(n/2);
    putchar('0' + r);
}
