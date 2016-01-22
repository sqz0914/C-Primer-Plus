#include<stdio.h>
int main(void)
{
	double debt;
	for(debt = 100;debt < 150; debt *= 1.1)
	   printf("Your debt is now $%.2f\n",debt);
    return 0;
}
