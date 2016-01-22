#include<stdio.h>
#define sec_per_min 60
int main(void)
{
	int sec,min,left;
	
	printf("Convert seconds to minutes and seconds!\n");
	printf("Enter the number of seconds (<=0 to quit):\n");
	scanf("%d",&sec);
	while(sec > 0)
	{
		min = sec/sec_per_min;
		left = sec%sec_per_min;
		printf("%d seconds is %d minutes,%d seconds.\n",sec,min,left);
		printf("Enter next value (<=0 to quit):\n");
		scanf("%d",&sec);
	}
	printf("Input Error!\n");
	getchar();
	return 0;
}
