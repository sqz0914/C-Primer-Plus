#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	unsigned int seed[10] = {0,1,2,3,4,5,6,7,8,9};
	int count[10];
	int i,j;
	
	for(i = 0;i < 10;i++)
	{
		for(j = 0;j < 10;j++)
		    count[j] = 0;
        srand(seed[i]);
        for(j = 0;j < 1000;j++)
            count[rand() % 10]++;
        printf("seed = %d\n",seed[i]);
        for(j = 0;j < 10;j++)
            printf("%d : %d times.\n",j + 1,count[j]);
        putchar('\n');
	}
	
	return 0;
}
