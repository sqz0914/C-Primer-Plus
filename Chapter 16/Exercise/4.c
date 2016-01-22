#include <stdio.h>
#include <time.h>

void delay(double time);
int main(void)
{
	double time;
	puts("Enter the desired time delay:");
	while(scanf("%lf", &time) == 1)
	{
		delay(time);
		puts("Time out!");
		puts("Next value:");
	}
	puts("Bye!");
	
	return 0;
}

void delay(double time)
{
	double original;
	original = clock() / CLOCKS_PER_SEC;
	while((clock() / CLOCKS_PER_SEC) < (original + time))
	      continue;
}
