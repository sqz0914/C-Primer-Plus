#include<stdio.h>
int main(void)
{
	double ray1[8],ray2[8],num;
	int index;
	
	printf("Please enter eight doubles:\n");
	for(num = 0,index = 0;index < 8;index++)
	{
		scanf("%lf",&ray1[index]);
		num +=ray1[index];
		ray2[index] = num;
	}
	for(index = 0;index < 8;index++)
	{
		printf("%-6g",ray1[index]);
	}
	printf("\n");
	for(index = 0;index < 8;index++)
	{
		printf("%-6g",ray2[index]);
	}
	printf("\n");
	return 0;
}
