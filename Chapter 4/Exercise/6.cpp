#include<stdio.h>
#include<float.h>
int main(void)
{
	float a;
	double b;
	a = 1.0/3.0;
	b = 1.0/3.0;
	printf("%.4f %.4f\n",a,b);
	printf("%.12f %.12f\n",a,b);
	printf("%.16f %.16f\n",a,b);
	printf("%d %d\n",FLT_DIG,DBL_DIG);
	getchar();
	return 0;
}
