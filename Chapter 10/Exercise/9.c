#include<stdio.h>
void sum(double * ar1, double * ar2, double *ar3, int n);
void show(double * ar, int n);
int main(void)
{
	double ar1[5] = {2,4,5,8,9};
	double ar2[5] = {7,5,6,9,10};
	double ar3[5];
	
	sum(ar1,ar2,ar3,5);
	show(ar3,5);
	
	return 0;
 }
 void sum(double * ar1, double * ar2, double *ar3, int n)
 {
 	int i;
 	for(i = 0;i < n;i++)
 	   ar3[i] = ar1[i] + ar2[i];
 }
 void show(double * ar, int n)
 {
 	int i;
 	printf("The new array:\n");
 	for(i = 0;i < n;i++)
 	    printf("%6.1f",ar[i]);
 }
 