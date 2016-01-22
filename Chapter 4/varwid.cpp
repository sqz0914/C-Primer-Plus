#include<stdio.h>
int main(void)
{
	unsigned width,precision;
	int number = 256;
	double weight = 242.500;
	printf("What field width?\n");
	scanf("%u",&width);
	printf("The number is %*d.\n",width,number);
	printf("Now enter a width and precision.\n");
	scanf("%u %u",&width,&precision);
	printf("Weight = %*.*f\n",width,precision,weight);
	printf("Done!\n");
	getchar();
	return 0;
}
