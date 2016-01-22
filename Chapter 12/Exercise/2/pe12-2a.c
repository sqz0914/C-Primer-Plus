#include <stdio.h>
#include "pe12-2a.h"
static int mode;
static double distance;
static double fuel;
void set_mode(int n)
{
	if(n > 1)
    {
       printf("Invalid mode specified. Mode 1(US) used.\n");
       mode = 1;
    }
    else if(n == 1)
       mode = 1;
    else
       mode = 0;
}
void get_info(void)
{
	if(mode == 0)
	{
		printf("Enter distance traveled in kilometers:");
		scanf("%lf",&distance);
		printf("Enter fuel consumed in liters:");
		scanf("%lf",&fuel);
	}
	if(mode == 1)
	{
		printf("Enter distance traveled in miles:");
		scanf("%lf",&distance);
		printf("Enter fuel consumed in gallons:");
		scanf("%lf",&fuel);
	}
}
void show_info(void)
{
	if(mode == 0)
	{
		printf("Fuel consumption is %4.2f liters per 100 km.\n",fuel/(distance/100));
	}
	if(mode == 1)
	{
		printf("Fuel consumption is %4.2f miles per gallon.\n",distance/fuel);
	}
}
