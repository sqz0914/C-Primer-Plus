#include<stdio.h>
#define P_RATE1 10.0
#define P_RATE2 (1.5*P_RATE1)
#define T_RATE1 0.15
#define T_RATE2 0.2
#define T_RATE3 0.25
#define H_BREAK 40.0
#define T_BREAK1 300.0
#define T_BREAK2 450.0
#define P_BASE (P_RATE1*H_BREAK)
#define T_BASE1 (T_RATE1*T_BREAK1)
#define T_BASE2 (T_RATE2*(T_BREAK2 - T_BREAK1) + T_BASE1)
int main(void)
{
	double hour;
	double pay;
	double tax;
	
	printf("Please enter your hours worked in a week.\n");
	scanf("%lf",&hour);
	if(hour <= H_BREAK)
       pay = hour*P_RATE1;
    else
       pay = P_BASE + P_RATE2*(hour - H_BREAK);
    if(pay <= T_BREAK1)
       tax = T_RATE1*pay;
    else if(pay > T_BREAK1 && pay <= T_BREAK2)
       tax = T_BASE1 + T_RATE2*(pay - T_BREAK1);
    else
       tax = T_BASE2 + T_RATE3*(pay - T_BREAK2);
    printf("gross pay = $%.1f taxes = $%.1f net pay = $%.1f\n",pay,tax,pay - tax);
    
    return 0;
}
