#include <stdio.h>

char * itobs(unsigned int n, char * ps);
unsigned int rotate_l(unsigned int n, unsigned int bits);

int main(void)
{
	unsigned int n;
	unsigned int bits;
	char str[8 * sizeof(int) + 1];
	puts("Enter an non-negative integer for handling:");
	while(scanf("%ul", &n) == 1)
	{
		if(n < 0)
		  puts("Negative integer.Error!");
        else
        {
        	puts("Enter the number of bits to move:");
        	scanf("%d", &bits);
        	printf("Original: %s\n", itobs(n, str));
        	n = rotate_l(n, bits);
        	printf("Rotated: %s\n", itobs(n, str));
        }
        puts("Next value:");
	}
	puts("Bye!");
	
	return 0;
}

char * itobs(unsigned int n, char * ps)
{
	int i;
	static int size = 8 * sizeof(int);
	
	for(i = size - 1; i >= 0; i--, n >>= 1)
	    ps[i] = (n & 01) + '0';
    ps[size] = '\0';
    
    return ps;
}

unsigned int rotate_l(unsigned int n, unsigned int bits)
{
    int size = 8 * sizeof(int);
    unsigned int overflow;
    
    bits %= size;
    overflow = n >> (size - bits);
    return (n << bits) | overflow;
}
