#include<stdio.h>
void pound(int n);
int main(void)
{
	int a = 5;
	char b = '!';
	float c = 6.0;
	pound(a);
	pound(b);
	pound((int)c);
	return 0;
}
void pound(int n)
{
	while(n-- > 0)
	{
		printf("#");
	}
	printf("\n");
}
