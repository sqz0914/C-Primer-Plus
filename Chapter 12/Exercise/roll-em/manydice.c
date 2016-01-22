#include<stdio.h>
#include<stdlib.h>
extern roll_n_dice(int dice, int sides);
int main(void)
{
	int sets;
	int sides,dice;
	int i;
	
	srand((unsigned int)time(0));
	puts("Enter the number of sets; enter q to stop.");
	while(scanf("%d",&sets) == 1)
	{
		puts("How many sides and how many dice?");
		scanf("%d %d",&sides,&dice);
		printf("Here are %d sets of %d %d-sided throws.\n",sets,dice,sides);
		for(i = 0;i < sets;i++)
        {
               printf("%4d",roll_n_dice(dice,sides));
               if(i % 7 == 6)
                  putchar('\n');
        }
        putchar('\n');
        puts("How many sets? Enter q to stop.");
	}
	
	return 0;
}
