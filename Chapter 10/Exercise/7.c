#include<stdio.h>
void copy_arr(int *ar, int *ptr, int n);
int main(void)
{
	int i;
	int ar[7] = {4,6,9,10,14,13,12};
	int copy[3];
	printf("The new 3-element array:\n");
	copy_arr(ar,copy,3);
	for(i = 0;i < 3;i++)
	   printf("%3d",copy[i]);
}
void copy_arr(int *ar, int *ptr, int n)
{
	int i;
    
    for(i = 0;i < n;i++)
        ptr[i] = ar[i+2];
}
