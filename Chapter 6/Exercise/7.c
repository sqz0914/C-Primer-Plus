#include<stdio.h>
int main(void)
{
	float a,b;
	
	printf("Please enter two floating-point numbers:\n");
	while(scanf("%f %f",&a,&b) == 2)
	{
		printf("(%.6g - %.6g)/(%.6g*%.6g) = %.6g\n",a,b,a,b,(a-b)/(a*b));
		printf("Please enter two floating-point numbers(Enter q to qiut):\n");
	} 
	printf("End\n");
	return 0;    
}
