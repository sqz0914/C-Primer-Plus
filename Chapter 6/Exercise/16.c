#include<stdio.h>
#define WITHDRAW 100000
int main(void)
{
	int count;
	float sum;
	
	for(count = 0,sum = 1000000;sum > 0;count++)
	{
		sum += sum*0.08;
		sum -= WITHDRAW;
	}   
	   
    printf("It takes Chuckie Lucky %d years to empty his account.\n",count);
    return 0;
}
