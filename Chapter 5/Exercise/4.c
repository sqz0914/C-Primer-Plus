#include<stdio.h>
#include<stdlib.h>
#define FOOT 30.48
int main(void)
{
	float height,inch;
	int feet;
	
	printf("Please enter your height in centimeters.");
	scanf("%f",&height);
	while(height > 0)
	{
		feet = height/FOOT;
		inch = height/(FOOT/12) - feet*12;
		printf("%.1f cm = %d feet,%.1f inches.\n",height,feet,inch);
		printf("Enter a height in centimeters (<=0 to quit)");
		scanf("%f",&height);
	}
	printf("END!\n");
	system("PAUSE");
	return 0;
}
