#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void)
{
	int random[100];
	int i,temp;
	int top,seek;
	
	srand((unsigned int) time(0));
	for(i = 0;i < 100;i++)
	{
		random[i] = rand() % 10 + 1;
	}
	for(top = 0;top < 99;top++)
	    for(seek = top + 1;seek < 100;seek++)
    		if(random[seek] > random[top])
    		{
    			temp = random[top];
    			random[top] = random[seek];
    			random[seek] = random[top];
		    }
   for(i = 0;i < 100;i++)
   {
   	    printf("%4d",random[i]);
   	    if(i % 7 == 6)
   	    putchar('\n');
   }
   putchar('\n');
   return 0;
}
