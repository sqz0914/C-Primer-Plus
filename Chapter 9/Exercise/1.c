#include<stdio.h>
double min(double x, double y);
int main(void)
{
	double x,y;
	
	x = 3.0;
	y = 4.0;
	
	printf("The smaller one is %.2g.\n",min(x,y));
	
	return 0;
}

double min(double x, double y)
{
    return x < y? x: y;
}
