#include<stdio.h>
#include<stdlib.h>
int roll_n_dice(int dice, int sides);
static int rollem(int sides)
{
	int roll;
	
	roll = rand() % sides + 1;
	
	return roll;
}
int roll_n_dice(int dice, int sides)
{
	int i;
	int total = 0;
	if(sides < 2)
	{
		printf("Need at least 2 sides.\n");
		return -2;
	}
	if(dice < 1)
	{
		printf("Need at least 1 dice.\n");
		return -1;
	}
	
	for(i = 0;i < dice;i++)
	    total += rollem(sides);
    
    return total;
}
