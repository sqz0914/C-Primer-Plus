#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int a,count;
	count = 0;
	printf("Do you want to see something interesting?\n");
	printf("Please enter an integer.\n");
	scanf("%d",&a);
	while(count++ <= 10)
    {
    	printf("%5d",a++);
    }
    system("PAUSE");
    return 0;
}
