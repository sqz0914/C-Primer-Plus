#include<stdio.h>
#include<stdlib.h>
const double F_C = 1.8;
const double LEFT = 32.0;
const double LEFT2 = 273.16;
void Temperatures(double fahr);
int main(void)
{
	double fahr;
	printf("Please enter a Fahrenheit temperature.\n");
	
	while(scanf("%lf",&fahr) == 1)
    {
    	Temperatures(fahr);
    	printf("Enter another value.(enter a nonnumeric value to qiut.)\n");
    }
    printf("End.\n");
    system("PAUSE");
    return 0;
}

void Temperatures(double fahr)
{
	double cel,kel;
	if(fahr > -459.69)
	{
	    cel = (fahr - LEFT)/F_C;
	    kel = cel + LEFT2;
        printf("Fahrenheit    Celsius    Kelvin\n");
	    printf("%-13.2f %-10.2f %-6.2f\n",fahr,cel,kel);
	}
	else
	{
		printf("Error!Enter a correct value.\n");
	}
}
