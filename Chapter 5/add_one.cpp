#include<stdio.h>
int main(void)
{
	int super,ultra;
	super = ultra =0;
	while(super < 5)
	{
		super++;
		++ultra;
		
		printf("super = %d,ultra = %d\n",super,ultra);
	}
	getchar();
	return 0;
}
