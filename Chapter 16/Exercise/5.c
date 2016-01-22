#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 51
#define PICKS 6
void eatline(void);
void select(int ar[], int ar_size, int picks);
int main(void)
{
	int lotto[SIZE];
	int choice,index;
	
	for(index = 0; index < SIZE; index++)
	   lotto[index] = index + 1;
    do
    {
    	select(lotto, SIZE, PICKS);
    	puts("\nDo you want to continue?<y/n>");
    	choice = getchar();
    	eatline();
    }
    while(choice == 'y' || choice == 'Y');
    puts("Bye!");
    
    return 0;
}

void eatline(void)
{
	while(getchar() != '\n')
	   continue;
}

void select(int ar[], int ar_size, int picks)
{
	int i, index, temp;
	
	srand((unsigned int)time(0));
	if(picks > ar_size)
    {
   	    fputs("Number of picks > array size\n", stderr);
        fputs("Setting picks = array size\n", stderr);
        picks = ar_size;
    }
    for(i = 0; i < picks; i++)
	{
		index = rand() % (ar_size - 1);
		temp = ar[index];
		printf("%4d", temp);
		if(i % 7 == 6)
		   putchar('\n');
		ar[index] = ar[ar_size - 1];
		ar[ar_size - 1] = ar[index];
		ar_size--;
	}
	if(i % 7 == 0)
	   putchar('\n');
}
