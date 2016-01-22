#include<stdio.h>
#define TIME 40.0
#define ADD 1.5
#define LIMIT1 300.0
#define LIMIT2 150.0
#define RATE1 0.15
#define RATE2 0.2
#define RATE3 0.25
int get_int(void);
int main(void)
{
	double hour;
	double gross;
	double tax;
	double basic;
	int num;
	
	printf("Enter the number corresponding to the desired pay rate or action:\n");
	printf("1) $8.75/hr\t\t\t\t2) $9.33/hr\n");
	printf("3) $10.00hr\t\t\t\t4) $11.20/hr\n");
	printf("5) qiut\n");
	switch(get_int())
	{
		case 1:basic = 8.75;
		       break;
		case 2:basic = 9.33;
               break;
		case 3:basic = 10.00;
		       break;
		case 4:basic = 11.20;
		       break;
		default:printf("qiut\n");return 0;
	}
	printf("you have select $%.2lf\n",basic);
    printf("input the work hours of a week:");
    scanf("%lf",&hour);
	if (hour > 40) 
	    hour = 40 + (hour - 40) * 1.5;
    gross = hour * basic;
    printf("gross income:\t\t%lf\n",gross);
    if (gross <= LIMIT1) 
	    tax = gross * RATE1;
    else if (gross <= LIMIT2) 
	    tax = LIMIT1 * RATE1 + (gross - LIMIT1) * RATE2;
    else 
	    tax = LIMIT1 * RATE1 + LIMIT2 * RATE2 + (gross - LIMIT1 - LIMIT2) * RATE3;
    printf("tax:\t\t\t%lf\n",tax);
    printf("net income:\t\t%lf\n",gross - tax);
    return 0;
}

int get_int(void)
{
	int num;
	char ch[225];
	while(scanf("%d",&num) != 1)
	{
		printf("error!%s is not a number!input again!\n",ch);
	}
	while(getchar() != '\n')
	     continue;
    
	return num;
}
