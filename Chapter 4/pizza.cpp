#include<stdio.h>
#define PI 3.1415926
int main(void)
{
	float circumference,area,radius;
	printf("What is the radius of your pizza?\n");
	scanf("%f",&radius);
	circumference = PI*radius*2;
	area = PI*radius*radius;
	printf("Your basic pizza parameters are as follows:\n");
	printf("circumference = %2.2f,area = %2.2f.\n",circumference,area);
	getchar();
	return 0;
}
