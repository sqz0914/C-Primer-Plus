#include<stdio.h>
int main(void)
{
	double time,sum;
	int count,term;
	printf("Enter the number of terms you want:");
	scanf("%d",&term);
	for(time = 1,count = 1,sum = time;count <= term;sum += 0.5*time,time *=0.5,count++)
	   printf("time = %f when terms = %d.\n",sum,count);
    return 0;
}
