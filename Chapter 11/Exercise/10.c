#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define LIM 10
#define SIZE 81
char get_choice(void);
char get_first(void);
void ori(char * strings[], int n);
void ASCII(char * strings[], int n);
void len(char * strings[], int n);
int len_first_word(char * string);
void len_word(char * strings[], int n);
int main(void)
{
	char input[LIM][SIZE];
	char *ptr[LIM];
	int i = 0;
	char choice;
	
	puts("Please input not more than 10 strings:");
	while(i < LIM && gets(input[i]) != NULL)
	{
		ptr[i] = input[i];
		i++;
	}
    while((choice = get_choice()) != 'q')
    {
    	switch(choice)
    	{
	    	case 'a': puts("the original list of strings:");
	    	          ori(ptr,i);
	    	          break;
            case 'b': puts("the strings in ASCII collating sequence:");
                      ASCII(ptr,i);
                      break;
            case 'c': puts("the strings in order of increasing length:");
                      len(ptr,i);
                      break;
            case 'd': puts("the strings in order of the length of the first word:");
                      len_word(ptr,i);
                      break;
	    }
    }
    puts("qiut!");
    
    return 0;
}
char get_choice(void)
{
	int ch;
	puts("Enter the letter of your choice:");
	puts("a.print the original list of strings");
	puts("b.print the strings in ASCII collating sequence");
	puts("c.print the strings in order of increasing length");
	puts("d.print the strings in order of the length of the first word in the string");
	puts("q.qiut");
	
	ch = get_first();
	while((ch < 'a' || ch > 'd') && ch != 'q')
	{
		puts("Please response with a,b,c,d or q.");
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
void ori(char * strings[], int n)
{
	int i;
	for(i = 0;i < n;i++)
	    puts(strings[i]);
}
void ASCII(char * strings[], int n)
{
	int i,top,seek;
	char * temp;
	for(top = 0;top < n - 1;top++)
    {
    	for(seek = top + 1;seek < n;seek++)
    	{
	    	if(strcmp(strings[seek],strings[top]) < 0)
	    	{
	    		temp = strings[top];
	    		strings[top] = strings[seek];
	    		strings[seek] = temp;	
	    	}
	    }
    }
    for(i = 0;i < n;i++)
	    puts(strings[i]);
}
void len(char * strings[], int n)
{
	int i,top,seek;
	char * temp;
		for(top = 0;top < n - 1;top++)
    {
    	for(seek = top + 1;seek < n;seek++)
    	{
	    	if(strlen(strings[top]) > strlen(strings[seek]))
	    	{
	    		temp = strings[top];
	    		strings[top] = strings[seek];
	    		strings[seek] = temp;	
	    	}
	    }
    }
    for(i = 0;i < n;i++)
	    puts(strings[i]);
}
int len_first_word(char * string)
{
	int count;
	for(;!isalpha(*string);string++)
	{
		if(*string == '\0')
	    return 0;
	}  
	for(count = 0;isalpha(string[count]);count++);
	
	return count;  
	
}
void len_word(char * strings[], int n)
{
	int i,top,seek;
	char * temp;
	for(top = 0;top < n - 1;top++)
    {
    	for(seek = top + 1;seek < n;seek++)
    	{
	    	if(len_first_word(strings[top]) > len_first_word(strings[seek]))
	    	{
	    		temp = strings[top];
	    		strings[top] = strings[seek];
	    		strings[seek] = temp;	
	    	}
	    }
    }
    for(i = 0;i < n;i++)
	    puts(strings[i]);
}
