#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int max;
	int number;
	int i = 0;
	double * ptr;
	
	puts("What is the maximum number of entries?");
	scanf("%d",&max);
	ptr = (double *)malloc(max * sizeof(double));
	if(ptr == NULL)
	{
		puts("Memory allocation failed.Goodbye!");
		exit(EXIT_FAILURE);
	}
	puts("Enter the values (q to qiut):");
	while(i < max && scanf("%lf",&ptr[i]) == 1)
	{
		i++;
	}
	number = i;
	printf("Here are your %d entries:\n",number);
	for(i = 0;i < number;i++)
    {
	   printf("%7.2f",ptr[i]);
	   if(i % 7 == 6)
	      putchar('\n');
    }
    if(i % 7 != 0)
       putchar('\n');
    puts("Done!");
    free(ptr);
    
    return 0;
}
