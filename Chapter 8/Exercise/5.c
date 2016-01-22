#include<stdio.h>
int main(void)
{
	char ch;
	int guess = 50;
	int preguess;
	int max = 100;
	int min = 1;
	
	printf("Pick an integer from 1 to 100.I will try to guess it.\n");
	printf("Respond with a y if my guess is right and with h if it is high");
	printf(" and with l if it is low.\n");
	printf("Uh...if your number %d?\n",guess);
	while((ch = getchar()) != 'y')
	{
		preguess = guess;
		switch(ch)
		{
			case 'h':max = guess;
                     guess = (guess + min)/2;
			         printf("if your number %d?\n",guess);
			         break;
            case 'l':min = guess;
			         guess = (guess + max)/2;
                     printf("if your number %d?\n",guess);
                     break;
            default: printf("Enter error!\n");
                     break;
		}
		while(getchar() != '\n')
		continue;
	}
	printf("I knew I could do it!\n");
	
	return 0;
}
