#include<stdio.h>
void to_base_n(unsigned long n, int m);
int main(void)
{
	unsigned long number;
	int base;
	
	printf("Enter an integer and the number base:(q to qiut)");
	while(scanf("%lu %d",&number,&base) == 2)
	{
		printf("Base-%d equivalent: ",base);
		to_base_n(number,base);
		putchar('\n');
		printf("Enter an integer and the number base:(q to qiut)");
	}
	printf("Done!\n");
	return 0;
}

void to_base_n(unsigned long n, int m)
{
	int r;
	
	r = n % m;
	if(n >= m)
      to_base_n(n/m,m);
    putchar('0' + r);
}
