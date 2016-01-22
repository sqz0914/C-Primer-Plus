#include <stdio.h>
#include "hotel.h"
int menu(void)
{
	int code;
	
	printf("\n%s%s\n",STARS,STARS);
	printf("Enter the number of the desired hotel:\n");
	printf("1) Fairfield Arms           2) Hotel Olympic\n");
	printf("3) Chertworthy Plaza        4) The Stockton\n");
	printf("5) qiut\n");
	printf("\n%s%s\n",STARS,STARS);
	while(scanf("%d",&code) != 1 || (code < 1 || code > 5))
	{
		while(getchar() != '\n')
		      continue;
        printf("Enter an integer from 1 to 5,please.\n");
	}
	
	return code;
}

int getnights(void)
{
	int nights;
	
	printf("How many nights are needed? ");
	while(scanf("%d",&nights) != 1)
	{
		while(getchar() != '\n')
		     continue;
        printf("Please enter an integer, such as 2.\n");
	}
	
	return nights;
}

void showprice(double rate, int nights)
{
	int n;
	double total;
	double factdisc;
	
	for(n = 1,total = 0,factdisc = 1;n <= nights;n++,factdisc *= DISCOUNT)
	    total += rate * factdisc;
    printf("The total cost will be $%0.2f.\n",total);
}
