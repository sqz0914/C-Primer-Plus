#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int i,sum,times;
	i = 0;
	sum = 0;
    
    printf("Please enter a number to tell the program how far it should proceed.\n");
    scanf("%d",&times);
    while(i++ < times)
    	sum = sum + i;
   	printf("%d",sum);
   	system("PAUSE");
   	return 0;
}
