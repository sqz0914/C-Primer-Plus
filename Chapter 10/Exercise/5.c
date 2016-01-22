#include<stdio.h>
#define SIZE 4
double def(double ar[], int n);
int main(void)
{
	int i;
	double arr[SIZE] = {1.1,2.2,7.0,4.4};
    printf("The index of the largest number among them is %g.\n",def(arr,SIZE));
    
    return 0;
}
double def(double ar[],int n)
{
	int i;
	double max,min;
	
	for(i = 0,max = min = ar[0];i < n;i++)
	{
		if(ar[i] > max)
		   max = ar[i];
        if(ar[i] < min)
           min = ar[i];
	}
	return max-min;
}
