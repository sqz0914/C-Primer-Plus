#include <stdio.h>
#include <math.h>
#define MAX 20

double twice(double );
double half(double );
void transform(double [], double [], int, double (*pt)(double ));

int main(void)
{
	double source[MAX];
	double target[MAX];
	int index;
	int choice;
	double (*pt[4])(double ) = {twice, half, sin, sqrt};
	
	for(index = 0; index < MAX; index++)
	    source[index] = index + 1;
    for(choice = 0; choice < 4; choice++)
    {
    	transform(source, target, MAX, (*pt[choice]));
    	puts("\nThe target array:\n");
        for(index = 0; index < MAX; index++)
        {
    	       printf("%.2f  ",target[index]);
    	       if((index  + 1) % 7 == 0)
    	          putchar('\n');
        }
        putchar('\n');
    }
    
    return 0;
}

double twice(double x)
{
	return (x * 2);
}
double half(double x)
{
	return (x / 2);
}
void transform(double source[], double target[], int size, double (*pt)(double ))
{
	int index;
	for(index = 0; index < size; index++)
	    target[index] = (*pt)(source[index]);
}
