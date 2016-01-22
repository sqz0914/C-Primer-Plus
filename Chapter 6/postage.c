#include<stdio.h>
#define FIRST 0.37
#define ADD 0.23
int main(void)
{
	double ounce,cost;
	printf("ounces   cost\n");
	for(ounce = 1,cost = FIRST;ounce < 16;ounce++,cost +=ADD)
	    printf("%5.0f    $%4.2f\n",ounce,cost);
    return 0;
}
