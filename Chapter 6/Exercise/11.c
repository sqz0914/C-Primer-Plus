#include<stdio.h>
#include<math.h>
int main(void)
{
	float sum1,sum2;
	int i,term;
	
	printf("Now we have two infinite series:\n");
	printf("sum1 = 1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0+...\n");
	printf("sum1 = 1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0+...\n");
	printf("Please enter a limit of number of terms:");
	scanf("%d",&term);
	for(sum1 = 0,i = 1;i <= term;i++)
		sum1 += 1.0/(float)i;
	for(sum2 = 0,i = 1;i <= term;i++)
		sum2 += 1.0/(float)i*pow(-1,i-1);
	printf("sum1 = %f,sum2 = %f\n",sum1,sum2);
	return 0;
}
