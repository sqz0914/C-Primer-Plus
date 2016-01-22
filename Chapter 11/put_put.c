#include<stdio.h>
void put1(const char * ptr);
int put2(const char * ptr);
int main(void)
{
	put1("If I'd as much money as I could spend,\n");
	printf("I count %d characters.\n",put2("I never would cry old chairs to mend."));
	
	return 0;
}
void put1(const char * ptr)
{
	while(*ptr)
	{
		putchar(*ptr++);
	}
}
int put2(const char * ptr)
{
	int count = 0;
	while(*ptr)
	{
		putchar(*ptr++);
		count++;
	}
	putchar('\n');
	return count;
}
