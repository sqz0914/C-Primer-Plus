#include<stdio.h>
#define SIZE 8
int main(void)
{
	int index,number[SIZE],num;
	
	for(num = 1,index = 0;index < SIZE;index++)
	{
		num *=2;
		number[index] = num;
	}
	
	index = 0;
    do 
    {
        printf("%d  ",number[index]);
        index++;
    }
    while(index < SIZE);
	printf("\n");
	return 0;
}
