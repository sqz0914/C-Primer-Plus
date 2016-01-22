#include<stdio.h>
#include<stdlib.h>
float cube(float num)
{
	return(num*num*num);
}
int main(void)
{
    float number;
	printf("Please enter a float number.\n");
	scanf("%f",&number);
	printf("the value of %f cubed is %f.\n",number,cube(number));
	system("PAUSE");
	return 0;	
}
