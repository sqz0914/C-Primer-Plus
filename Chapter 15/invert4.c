#include <stdio.h>

char * itobs(int n, char * ps);
void show_bstr(char * str);
int invert_end(int num, int bits);

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
		show_bstr(str);
		n = invert_end(n, 4);
		puts("Inverting the last 4 bits gives");
		show_bstr(itobs(n, str));
	}
	puts("Bye!");
	
	return 0;
}

char * itobs(int n, char * ps)
{
	int i;
	static size = 8 * sizeof(int);
	
	for(i = size - 1; i >= 0; i--, n >>= 1)
	    ps[i] = (01 & n) + '0';
    ps[size] = '\0';
    return ps;
}

void show_bstr(char * str)
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

int invert_end(int num, int bits)
{
	int MASK = 0;
	int bitval = 1;
	while( bits-- )
	{
		MASK |= bitval;
		bitval <<= 1;
	}
	
	return num ^ MASK;	
}
