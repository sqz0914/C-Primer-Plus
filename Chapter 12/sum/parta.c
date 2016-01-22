//various storage classes
#include<stdio.h>
void accumulate(int k);
void report_count();
int count = 0;

int main(void)
{
	int value;
	register int i;
	
	puts("Enter a positive integer (0 to qiut):");
	while(scanf("%d",&value) == 1 && value > 0)
	{
		++count;
		for(i = value;i >= 0;i--)
		    accumulate(i);
        puts("Enter a positive integer (0 to qiut):");
	}
	report_count();
	
	return 0;
}
void report_count()
{
	printf("Loop executed %d times\n",count);
}
