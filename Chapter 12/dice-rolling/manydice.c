#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "diceroll.h"
int main(void)
{
	int dice,roll;
	int sides;
	
	srand((unsigned int) time(0));
	puts("Enter the number of sides per die, 0 to stop.");
	
	while(scanf("%d",&sides) == 1 && sides > 0)
	{
		puts("How many dice?");
		scanf("%d",&dice);
		roll = roll_n_dice(dice,sides);
		printf("You have rolled a %d using %d %d-sided dice.\n",roll,dice,sides);
		puts("How many sides? Enter 0 to stop.");
	}
	printf("The rollem() function was called %d times.\n",count);
	puts("GOOD FORTUNE TO YOU!");
	
	return 0;
}
