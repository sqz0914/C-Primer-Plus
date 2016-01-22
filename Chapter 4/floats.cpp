#include<stdio.h>
#define RENT 3852.99
int main(void)
{
	printf("*%f*\n",RENT);
	printf("*%e*\n",RENT);
	printf("*%.2f*\n",RENT);
	printf("*%.1f*\n",RENT);
	printf("*%10.3f*\n",RENT);
	printf("*%10.3e*\n",RENT);
	printf("*%+4.2f*\n",RENT);
	printf("*%010.2f*\n",RENT);
	getchar();
	return 0;
}
