#include <stdio.h>
#include <stdlib.h>

int bstoi(char * str);
char * itobs(int n);

int main(int argc, char * argv[])
{
	int a, b;
	if(argc < 2)
	{
		printf("Usage: %s filename\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	a = bstoi(argv[1]);
	b = bstoi(argv[2]);
	printf("~%s is %s\n", argv[1], itobs(~a));
	printf("~%s is %s\n", argv[2], itobs(~b));
	printf("%s & %s is %s\n", argv[1], argv[2], itobs(a & b));
	printf("%s | %s is %s\n", argv[1], argv[2], itobs(a | b));
	printf("%s ^ %s is %s\n", argv[1], argv[2], itobs(a ^ b));
	
	return 0;
}

int bstoi(char * str)
{
	int value;
	
	while( *str )
	      value = 2 * value + (*str++ - '0');
	
	return value;
}

char * itobs(int n)
{
	int i;
	static int size = 8 * sizeof(int);
	char str[size + 1];
	char * ptr = str;
	
	for(i = size - 1;i >= 0; i--, n >>= 1)
		str[i] = (01 & n) + '0';
	str[size] = '\0';
	
	return ptr;
}
