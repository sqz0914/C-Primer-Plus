#include<stdio.h>
extern int rand1(void);
extern void srand1(int seed);

int main(void)
{
	int count;
	int seed;
	
	printf("Please enter your choice for seed.\n");
	while(scanf("%d",&seed) == 1)
	{
		srand1(seed);
		
		for(count = 0;count < 5;count++)
		    printf("%hd\n",rand1());
     	printf("Please enter your choice for seed (q to qiut):\n");
	}
	
	puts("Done!");
	
	return 0;
}
