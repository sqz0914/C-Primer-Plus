#include <stdio.h>
int check_bit(int n, int pos);
int main(void)
{
	int n;
	int pos;
	
	puts("Enter the integer to handle (# to qiut):");
	while(scanf("%d", &n) == 1)
	{
		puts("Enter the positon to check:");
		scanf("%d", &pos);
		if(check_bit(n, pos))
		   puts("The bit position is 1\n");
        else
           puts("The bit position is 0\n");
        puts("Next value:");
	}
	puts("Bye!");
	
	return 0;
}

int check_bit(int n, int pos)
{
	int mask = 1;
    mask <<= pos;

	
	if(n & mask)
	   return 1;
    else 
       return 0;
}
