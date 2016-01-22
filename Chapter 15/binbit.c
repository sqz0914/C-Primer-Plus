#include<stdio.h>
char * itobs(int n, char * ps);
void showstr(char * str);

int main(void)
{
	char str[8 * sizeof(int) + 1];
	int n;
	
	puts("Enter integers and see them in binary.");
	puts("Non-numeric input terminates program.");
	while(scanf("%d", &n) == 1)
	{
		itobs(n, str);
		printf("%d is ", n);
		showstr(str);
	}
	puts("Bye!");
	
	return 0;
}

char * itobs(int n, char * ps)
{
	int i;
	static size = 8 * sizeof(int);
	for(i = size - 1; i >= 0; i--, n >>= 1)
	    ps[i] = (1 & n) + '0';
    ps[size] = '\0';
}

void showstr(char * str)
{
	int i = 0;
	while(str[i])
	{
		putchar(str[i]);
		if(++i % 4 == 0 && str[i])
		      putchar(' ');
	}
	putchar('\n');
}
