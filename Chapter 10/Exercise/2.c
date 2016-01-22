#include<stdio.h>
void copy_arr(double ar[], double pt[], int n);
void copy_ptr(double *ar, double *pt, int n);
int main(void)
{
	double source[5] = {1.1,2.2,3.3,4.4,5.5};
	double target1[5];
	double target2[5];
	
	copy_arr(source,target1,5);
	copy_ptr(source,target2,5);
	
	return 0;
}
void copy_arr(double ar[], double pt[], int n)
{
	int i;
	printf("The targer1 array:");
	for(i = 0;i < n;i++)
    {
    	pt[i] = ar[i];
    	printf("%4.1f",pt[i]);
    }
    printf("\n");
}
void copy_ptr(double *ar, double *pt, int n)
{
	int i;
	printf("The target2 array:");
	for(i = 0;i < n;i++)
	{
		*(pt + i) = *(ar + i);
		printf("%4.1f",*(pt + i));
	}
	printf("\n");
}
