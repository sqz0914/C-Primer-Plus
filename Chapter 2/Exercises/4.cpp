#include<stdio.h>
void jolly(void);
void good(void);
int main(void)
{
	printf("For he's a jolly good fellow!\n");
	jolly();
	printf("For he's a jolly good fellow!\n");
	good();
	getchar();
	return 0;
}

void jolly(void)
{
	printf("For he's a jolly good fellow!\n");
}

void good(void)
{
	printf("Which nobody can deny!\n");
}
