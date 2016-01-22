#include<stdio.h>
#define YEARS 5
#define MONTHS 12
int main(void)
{
	const float rainfall[YEARS][MONTHS] = 
	{
		{4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
	    {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
	    {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
	    {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
	    {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
	};
	int year,month;
	float subtotal,total;
	
	printf(" YEAR    RAINFALL (inches)\n");
	for(total = 0,year = 0;year < YEARS;year++)
	{
		for(subtotal = 0,month = 0;month < MONTHS;month++)
		    subtotal += rainfall[year][month];
        printf("%5d%15.1f\n",year + 2000,subtotal);
        total += subtotal;
	}
	printf("The yearly average is %.1f inches.\n",total/YEARS);
	printf("\nMONTHLY AVERAGES:\n");
	printf("\nJan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec\n");
	for(month = 0;month < MONTHS;month++)
	{
		for(subtotal = 0,year = 0;year < YEARS;year++)
		    subtotal += rainfall[year][month];
        printf("%-4.1f",subtotal/YEARS);
	}
	
	return 0;
}
