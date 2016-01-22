#include <stdio.h>
#define HARMONIC(X,Y) (2/((1/(X))+ (1/(Y))))

int main(void)
{
	double x,y;
	while(scanf("%lf %lf", &x, &y) == 2)
	{
		printf("The harmonic mean of %g and %g is %g\n", x, y, HARMONIC(x,y));
	}
	puts("Bye!");
	
	return 0;
}
