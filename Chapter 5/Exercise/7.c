#include<stdio.h>
#include<stdlib.h>
void cube(float n)
{
	float cubed;
	cubed = n*n*n;
	printf("the value of %f cubed is %f.\n",n,cubed);
}

int main(void)
{
	float input;
	printf("Please enter a float number.\n");
	scanf("%f",&input);
	cube(input);
	system("PAUSE");
	return 0;
}
