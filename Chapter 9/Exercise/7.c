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
	double ans = 1.0;
	int count;
	
    if(y > 0)
	{
		for(count = 1;count <= y;count++)
		    ans *= x;
	}
	else if(y < 0)
	{
		for(count = 1;count <= -y;count++)
		    ans *= (1/x);
	}
	else
	{
		if(x = 0)
		ans = 1/x;
		else
		ans = 1;
	}
	
	return ans;	
}
