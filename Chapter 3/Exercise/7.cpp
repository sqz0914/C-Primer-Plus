#include<stdio.h>
int main(void)
{
	float cen_height;
	printf("Please enter your height in centimeters ");
	scanf("%f",&cen_height);
	printf("Your height is %f inches.\n",cen_height/2.54);
	getchar();
	return 0;
}
