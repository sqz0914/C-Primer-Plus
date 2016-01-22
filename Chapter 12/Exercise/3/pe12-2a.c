#include <stdio.h>
#include "pe12-2a.h"
void set_mode(int * n)
{
	if(*n > 1)
    {
       printf("Invalid mode specified. Mode 1(US) used.\n");
       *n = 1;
    }
    else if(*n == 1)
       *n = 1;
    else
       *n = 0;
}
void get_info(int mode, double * distance, double * fuel)
{
	if(mode == 0)
	{
		printf("Enter distance traveled in kilometers:");
		scanf("%lf",distance);
		printf("Enter fuel consumed in liters:");
		scanf("%lf",fuel);
	}
	if(mode == 1)
	{
		printf("Enter distance traveled in miles:");
		scanf("%lf",distance);
		printf("Enter fuel consumed in gallons:");
		scanf("%lf",fuel);
	}
}
void show_info(int mode, double distance, double fuel)
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
