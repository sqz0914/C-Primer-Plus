#include<stdio.h>
#define SQUARE 64
#define CROP 1E15
int main(void)
{
	double current,total;
	int count = 1;
	
	printf("square     grains       total     fraction of\n");
	printf("           added        grains      US total\n");
	total = current = 1;
	printf("%4d %13.2e %12.2e %12.2e\n",count,current,total,total/CROP);
	while(count < SQUARE)
	{
		count = count + 1;
		current = 2*current;
		total = total + current;
		
		printf("%4d %13.2e %12.2e %12.2e\n",count,current,total,total/CROP);
	}
	getchar();
	return 0;
}
