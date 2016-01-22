#include<stdio.h>
#define PI 3.1415926 
int main(void)
{
	int cups = 5;
	float espresso = 13.5;
	int cost = 3100;
	printf("The %d CEOs drank %.1f cups of espresso.\n",cups,espresso);
	printf("The value of pi is %.7f.\n",PI);
	printf("Farewell!thou art too dear for my possessing,\n");
	printf("%c%d\n",'$',cost*2);
	getchar();
	return 0;
}
