#include<stdio.h>
int main(void)
{
	printf("%x %X %#X\n",31,31,31);
	printf("**%d**% d**%d**\n",42,42,-42);
	printf("**%5d**%.3d**%05d**%05.3d**\n",6,6,6,6);
	getchar();
	return 0;
}
