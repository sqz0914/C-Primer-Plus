#include<stdio.h>
float cal(float a,float b);
int main(void)
{
	float a,b;
	
	printf("Please enter two floating-point numbers:\n");
	while(scanf("%f %f",&a,&b) == 2)
	{
		printf("(%.6g - %.6g)/(%.6g*%.6g) = %.6g\n",a,b,a,b,cal(a,b));
		printf("Please enter two floating-point numbers(Enter q to qiut):\n");
	} 
	printf("End\n");
	return 0;    
}

float cal(float a,float b)
{
	return((a-b)/(a*b));
}
