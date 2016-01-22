#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	long a,sum;
	sum = 0L;
	
	printf("Please enter an integer to be summed (q to qiut):");
	
	while(scanf("%ld",&a) == 1)
	{
		sum = sum + a;
		printf("Please enter next integer (q to qiut):");
	}
	printf("Those integers sum to %ld.\n",sum);
	system("PAUSE");
	return 0;
}
