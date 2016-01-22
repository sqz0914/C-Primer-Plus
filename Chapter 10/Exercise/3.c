#include<stdio.h>
#define SIZE 10
int max(int ar[],int size);
int main(void)
{
	int i;
	int ar[SIZE];
	printf("Please enter %d integers:\n",SIZE);
	for(i = 0;i < SIZE;i++)
	    scanf("%d",&ar[i]);
    printf("The max integer among them is %d.\n",max(ar,SIZE));
    
    return 0;
}
int max(int ar[],int size)
{
	int i;
	int max;
	
	for(i = 1,max = ar[0];i < size;i++)
	{
		if(ar[i] > max)
		   max = ar[i];
	}
	
	return max;
}
