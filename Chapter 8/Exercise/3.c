#include<stdio.h>
#include<ctype.h>
int main(void)
{
	char ch;
	int countlow = 0;
	int countupp = 0;
	
	printf("Please enter some characters:\n");
	while((ch = getchar()) != EOF)
	{
		if(islower(ch))
		countlow++;
		if(isupper(ch))
		countupp++;
	}
	printf("There are %d upper letters.\n",countupp);
	printf("There are %d lower letters.\n",countlow);
	
	return 0;
}
