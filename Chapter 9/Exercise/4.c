#include<stdio.h>
double harm(double x, double y);
int main(void)
{
	double a,b;
	
    printf("Please enter two numbers to get their harmonic mean:");
    scanf("%lf %lf",&a,&b);
	printf("the harmonic mean of the two number is %g.\n",harm(a,b));
	
	return 0; 
}

double harm(double x, double y)
{
	return 2/(1/x + 1/y);
}
