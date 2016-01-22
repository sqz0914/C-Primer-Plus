#include<stdio.h>
double pow(double x, int y);
int main(void)
{
	double x;
	int y;
	
	printf("input the base number and the exponent:");
	scanf("%lf %d",&x,&y);
	printf("%g ^ %d = %g\n",x,y,pow(x,y));
	
	return 0;
}

double pow(double x, int y)
{	
	if(y > 0)
	x *= pow(x,y - 1);
	else if(y < 0)
	x = 1/pow(x, -y);
	else
	{
		if(x = 0)
		   x = 1/x;
        else 
           x = 1;
	}
	
	return x;
}
