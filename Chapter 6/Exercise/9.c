#include<stdio.h>
int main(void)
{
	int i,low,upp,sum;
	
	printf("Please enter a lower and an upper integer limits:");
	scanf("%d %d",&low,&upp);
	while(upp > low)
	{
		for(sum = 0,i = low;i <= upp;i++)
		    sum = sum + i*i;
		printf("The sums of the squares from %d to %d is %d\n",low*low,upp*upp,sum);
		printf("Enter next set of limits:");
		scanf("%d %d",&low,&upp);
	}
	printf("Done\n");
	return 0;
}
