#include<stdio.h>
int main(void)
{
	int num;
	char response;
	
	printf("Pick an integer from 1 to 100. I will try to guess it.\n");
	printf("Respond with a y if my guess is right and with\n");
	printf("an n if it is wrong.\n");
	num = 1;
	printf("Uh...is your number %d?\n",num);
	while((response = getchar()) != 'y')
	{
		if(response == 'n')
           printf("Well, then, is it %d?\n",++num);
        else 
           printf("Sorry, I understand only \"y\" or \"n\".\n");
        while(getchar() != '\n')
           continue;
	}
	printf("I knew I could do it!\n");
	
	return 0;
}
