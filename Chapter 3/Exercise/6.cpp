#include<stdio.h>
int main(void)
{
	float quart;
	double amount;
	printf("Please enter an amount of water in quarts ");
	scanf("%f",&quart);
	amount = quart*950/3.0e-23;
	printf("It has %e water molecule.\n",amount);
	getchar();
	return 0;
}
