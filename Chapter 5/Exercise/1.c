#include<stdio.h>
#include<stdlib.h>
#define M_PER_H 60
int main(void)
{
	int min,hour,left;
	
	printf("This is a program that converts time in minutes to time in hours and minutes.\n");
    printf("Please enter time in minutes.\n");
    printf("And you can enter \'0\' to end the program.\n");
    scanf("%d",&min);
    while(min > 0)
    {
    	hour = min/M_PER_H;
    	left = min%M_PER_H;
    	printf("%d minutes are %d hours and %d minutes.\n",min,hour,left);
    	printf("Next value?\n");
    	scanf("%d",&min);
    }
    printf("Bye!");
    system("PAUSE");
    return 0;
}
