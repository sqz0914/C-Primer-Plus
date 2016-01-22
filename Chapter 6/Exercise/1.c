#include<stdio.h>
int main(void)
{
	int count;
	char letter,letters[26];
	
	for(count = 0,letter = 'a';letter <= 'z';count++,letter++)
	{
		letters[count] = letter;
		printf("%c ",letters[count]);
	}   
	printf("\n"); 
	return 0;
}
