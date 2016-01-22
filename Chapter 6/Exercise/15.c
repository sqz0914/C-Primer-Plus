#include<stdio.h>
#define RATE1 0.1
#define RATE2 0.05
int main(void)
{
	double dap,dei,ori;
	int count;
	
	for(ori = 100,dap = 100,dei = 100,count = 0;dei <= dap;count++)
	{
		dap += ori*RATE1;
		dei *=(1+RATE2);
	}
	printf("It spends %d years when Deirdre's investment exceeds Daphne's.\n",count);
	printf("And Deirdre's investment is %f,Daphne's is %f.\n",dei,dap);
	return 0;
}
