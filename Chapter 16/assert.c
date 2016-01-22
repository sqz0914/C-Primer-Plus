#include <stdio.h>
#include <math.h>
#include <assert.h>

int main(void)
{
	int x, y, z;
	puts("Enter a pair of numbers (0 0 to qiut):");
	while(scanf("%d %d", &x, &y) == 2 && (x != 0 && y != 0))
	{
		z = x * x - y * y;
		assert(z >=0);
		printf("answer is %f\n", sqrt(z));
		puts("Next pair of numbers:");
	}
	
	return 0;
}
