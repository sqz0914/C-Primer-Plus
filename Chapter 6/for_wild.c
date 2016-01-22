#include<stdio.h>
int main(void)
{
	int x;
	int y = 55;
	printf("     x     y\n");
	for(x = 1;y <= 75;y = (++x*5)+50)
	   printf("%6d%7d\n",x,y);
    return 0;
}
