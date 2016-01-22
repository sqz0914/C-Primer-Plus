#include <stdio.h>
int count_on(int n);
int main(void)
{
	int i;
	puts("Enter an integer (# to qiut):");
	while(scanf("%d", &i) == 1)
	{
		printf("The number of \"on\" bits is %d.\n",count_on(i));
		puts("Next value:");
	}
	puts("Bye!");
	
	return 0;
}

int count_on(int n)
{
	int count = 0;
	while(n > 0)
	{
		if(n & 01)
		   count++;
        n >>= 1;
	}
	
	return count;
}
