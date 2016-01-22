#include<stdio.h>
#include<stdlib.h>
#define D_PER_W 60
int main(void)
{
	int day,week,left;
	
	printf("This is a program that converts days to weeks and days.\n");
    printf("Please enter a number of days.\n");
    printf("And you can enter a nonpositive number to end the program.\n");
    scanf("%d",&day);
    while(day > 0)
    {
    	week = day/D_PER_W;
    	left = day%D_PER_W;
    	printf("%d days are %d weeks and %d days.\n",day,week,left);
    	printf("Enter another value!\n");
    	scanf("%d",&day);
    }
    printf("Bye!");
    system("PAUSE");
    return 0;
}
