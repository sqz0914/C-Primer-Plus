#include<stdio.h>
#define RATE1 0.15
#define RATE2 0.28
int main(void)
{
	double limit;
	double tax;
	double income;
	int input;
	
	printf("Please enter a integer corresponding to the desired tax category:\n");
	printf("1) single\t\t\t\t2) Head of Household\n");
	printf("3) Married,Joint\t\t\t4) Married,Separate\n");
	printf("5) qiut\n");
	
	while(scanf("%d",&input) == 1)
	{
		switch(input)
		{
			case 1:limit = 17850.0;break;
		    case 2:limit = 23900.0;break;
		    case 3:limit = 29750.0;break;
		    case 4:limit = 14875.0;
		    default:printf("quit.\n");return 0;
		}
		printf("Please enter your income:\n");
		scanf("%lf",&income);
		if(income <= limit)
           tax = income*RATE1;
        else 
           tax = limit*RATE1 + (income - limit)*RATE2;
        printf("Your tax is $%.1f.\n",tax);
		printf("Please enter a integer corresponding to the desired tax category:\n");
	}
	printf("End!\n");
	
	return 0;
}
