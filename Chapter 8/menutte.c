#include<stdio.h>
char get_choice(void);
char get_first(void);
int get_int(void);
void count(void);
int main(void)
{
	int choice;
	void count(void);
	
	while((choice = get_choice()) != 'q')
	{
		switch(choice)
		{
			case 'a' : printf("Buy low, sell high.\n");
			           break;
            case 'b' : putchar('\a');
                       break;
            case 'c' : count();
                       break;
            default  : printf("Program error!\n");
                       break;
		}
	}
	printf("Bye!\n");
	
	return 0;
}

void count(void)
{
	int num,max;
	
	printf("Count how far? Enter an integer:\n");
	max = get_int();
	for(num = 1;num <= max;num++)
	    printf("%d\n",num);
    while(getchar() != 'n')
        continue;
}

int get_int(void)
{
	int num;
	char ch;
	
	while(scanf("%d",&num) != 1)
	{
		while((ch = getchar()) != '\n')
		      putchar(ch);
        printf(" is not an integer.\nPlease enter an integer value,such as 25"
		       ", -178, or 3: ");
	}
	
	return num;
}

char get_choice(void)
{
	int ch;
	
	printf("Enter the letter of your choice:\n");
	printf("a. advice               b. bell\n");
	printf("c. count                q. qiut\n");
	ch = get_first();
	while((ch < 'a' || ch > 'c') && ch != 'q')
	{
		printf("Please respond with a,b,c, or q.\n");
		ch = get_first();
	}
	
	return ch;
}

char get_first(void)
{
	int ch;
	
	ch = getchar();
	while(getchar() != '\n')
	     continue;
	     
    return ch;
}
