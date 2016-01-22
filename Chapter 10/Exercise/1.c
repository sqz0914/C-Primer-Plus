#include<stdio.h>
#define MONTHS 12
#define YEARS 5
void rainfall(float (*pt)[MONTHS],int years);
void month_aver(float (*pt)[MONTHS],int years);
int main(void)
{
	float rain[YEARS][MONTHS] = 
	{
		{4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
	    {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
	    {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
	    {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
	    {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
	};
	
	printf(" YEAR    RAINFALL (inches)\n");
	rainfall(rain,YEARS);
	printf("\nMONTHLY AVERAGES:\n");
	printf("\nJan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec\n");
	month_aver(rain,YEARS);
	
	return 0;
}
void rainfall(float (*pt)[MONTHS],int years)
{
	int i,j;
	float subtotal,total;
	for(i = 0,total = 0;i < years;i++)
	{
		for(j = 0,subtotal = 0;j < MONTHS;j++)
		    subtotal += pt[i][j];
        printf("%5d%15.1f\n",2000+i,subtotal);
        total += subtotal;
	}
	printf("The yearly average is %.1f inches.\n",total/years);
}
void month_aver(float (*pt)[MONTHS],int years)
{
	int i,j;
	float subtotal;
	for(j = 0;j < MONTHS;j++)
	{
		for(i = 0,subtotal = 0;i < years;i++)
		subtotal += pt[i][j];
		printf("%-4.1f",subtotal/years);
	}
}
