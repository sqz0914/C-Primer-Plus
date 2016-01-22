#include<stdio.h>
#include<stdlib.h>
#define MIN 0.0f
#define MAX 100.0f
int main(void)
{
	int n = 0;
	float score;
	float total = 0.0f;
	float min = MAX;
	float max = MIN;
	
	printf("Enter the first score (q to qiut):");
	while(scanf("%f",&score) == 1)
	{
		if(score < MIN || score > MAX)
		{
			printf("Invalid Value!\n");
		   continue;
		} 
		printf("Accepting %0.1f:\n",score);
		min = (score < min)?score:min;
		max = (score > max)?score:max;
		total +=score;
		n++;  
		printf("Enter next score (q to qiut):");
	}
	if(n > 0)
	{
		printf("Average of %d scores is %0.1f.\n",n,total/n);
		printf("Low = %0.1f,high = %0.1f\n",min,max);
	}
	else
	    printf("No valid scores were entered.\n");
    system("PAUSE");
    
    return 0;
}
