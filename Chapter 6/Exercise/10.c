#include<stdio.h>
#define SIZE 8
int main(void)
{
	int index,input[SIZE];
	
	printf("Please enter %d integers:\n",SIZE);
	for(index = 0;index < SIZE;index++)
	   scanf("%d",&input[index]);
    for(index = SIZE - 1;index >= 0;index--)
       printf("%-5d",input[index]);
    return 0;
}
