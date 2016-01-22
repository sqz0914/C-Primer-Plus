#include<stdio.h>
int main(void)
{
	const int PAGES = 931;
	printf("*%d*\n",PAGES);
	printf("*2d*\n",PAGES);
	printf("*%10d*\n",PAGES);
	printf("*%-10d*\n",PAGES);
	getchar();
	return 0;
}
