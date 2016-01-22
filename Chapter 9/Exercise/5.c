#include<stdio.h>
void larger_of(double * x, double * y);
int main(void)
{
	double a,b;
	
	printf("Please enter two numbers:");
	scanf("%lf %lf",&a,&b);
	larger_of(&a,&b);
	printf("a = %g b = %g\n",a,b);
}

void larger_of(double * x, double * y)
{	
    *x = *y = *x < *y?*y:*x;
}
