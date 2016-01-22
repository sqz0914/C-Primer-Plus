#include<stdio.h>
void display(char ch, int lines, int width);
int main(void)
{
	int ch;
	int rows;
	int cols;
	
	printf("Please enter a character and two integers:\n");
	while((ch = getchar()) != '\n')
	{
	    if(scanf("%d%d",&rows,&cols) != 2)
	       break;
        display(ch,rows,cols);
        while(getchar() != '\n')
              continue;
        printf("Enter another character and two integers:\n");
        printf("Enter a newline to qiut.\n");
	}
	printf("Bye!\n");
	
	return 0;
}
void display(char ch, int lines, int width)
{
	int rows;
	int cols;
	for(rows = 1;rows <= lines;rows++)
	{
		for(cols = 1;cols <= width;cols++)
            putchar(ch);
        putchar('\n');
	}
}
