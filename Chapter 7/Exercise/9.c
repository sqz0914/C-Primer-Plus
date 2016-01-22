#include<stdio.h>
#include<stdbool.h>
int main(void)
{
	int input;
	int num;
	int div;
	bool isprime;
	
	printf("Please enter an integer:\n");
	scanf("%d",&input);
	printf("All the prime numbers smaller than or equal to that number is:\n");
	for(num = 1;num <= input;num++)
	{
	    for(div = 2,isprime = true;div*div <= num;div++)
		{
			if(num%div == 0)	
		    {
    			isprime = false;
    			break;
    		}
		}
		if(isprime)
		   printf("%d\t",num);	
	}
	printf("\n");
	return 0;
}
