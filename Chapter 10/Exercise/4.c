#include<stdio.h>
#define SIZE 4
int retu(double ar[], int n);
int main(void)
{
	int i;
	double arr[SIZE] = {1.1,2.2,3.3,4.4};
    printf("The index of the largest number among them is %d.\n",retu(arr,SIZE));
    
    return 0;
}
int retu(double ar[], int n)
{
	int i;
	int max;
	for(i = 0,max = 0;i < n;i++)
	{
		if(ar[i] > ar[max])
		   max = i;
	}
	return max;
}
