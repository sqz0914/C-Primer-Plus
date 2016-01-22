#include<stdio.h>
#include<string.h>
#define NAME "GIGATHINK, INC."
#define ADDRESS "101 Megabuck Plaza"
#define PLACE "Megapolis, CA 94904"
#define WIDTH 40
void show_n_char(char ch,int width);
int main(void)
{
	show_n_char('*',WIDTH);
	printf("\n");
	show_n_char(' ',(WIDTH - strlen(NAME))/2);
	printf("%s\n",NAME);
	show_n_char(' ',(WIDTH - strlen(ADDRESS))/2);
	printf("%s\n",ADDRESS);
	show_n_char(' ',(WIDTH - strlen(PLACE))/2);
	printf("%s\n",PLACE);
	show_n_char('*',WIDTH);
	printf("\n");
	
	return 0;
}

void show_n_char(char ch,int width)
{
	int i;
	
	for(i = 1;i <= width;i++)
	    putchar(ch);
}
