#include<stdio.h>
#include<string.h>
#define MAXTITL 40
#define MAXAUTH 40
#define MAXBKS 100

struct book {
	char title[MAXTITL];
	char author[MAXAUTH];
	float value;
};

void show_ori(struct book ori[], int count);
void show_alpha(struct book alpha[], int count);
void show_value(struct book value[], int count);

int main(void)
{
	struct book library[MAXBKS];
	int count = 0;
	
	puts("Please enter the book title.");
	puts("Press [Enter] at the start of a line to stop");
	while(count < MAXBKS && gets(library[count].title) != NULL
	      && library[count].title[0] != '\0')
    {
    	puts("Now enter the author.");
    	gets(library[count].author);
    	puts("Now enter the value");
    	scanf("%f",&library[count++].value);
    	while(getchar() != '\n')
    	      continue;
        if(count < MAXBKS)
           puts("Please enter the next title:");
    }
    
    if(count > 0)
    {
    	show_ori(library, count);
    	show_alpha(library, count);
    	show_value(library, count);
    }
    else
        puts("No books? Too bad.\n");
}

void show_ori(struct book ori[], int count)
{
	int index;
	
	puts("Here is the list of your books:");
	for(index = 0; index < count; index++)
	    printf("%s by %s: $%.2f\n",ori[index].title,ori[index].author,
		       ori[index].value);
    putchar('\n');
}

void show_alpha(struct book alpha[], int count)
{
	int index;
	int seek;
	struct book ptr;
	for(index = 0; index < count - 1; index++)
	    for(seek = index + 1; seek < count; seek++)
	    {
    		if(strcmp(alpha[index].title, alpha[seek].title) > 0)
    		{
		    	ptr = alpha[index];
		    	alpha[index] = alpha[seek];
		    	alpha[seek] = ptr;
		    }
    	}
	puts("Here is the list of your books alphabetized by title:");
	for(index = 0; index < count; index++)
	    printf("%s by %s: $%.2f\n",alpha[index].title,alpha[index].author,
		       alpha[index].value);
    putchar('\n');
}

void show_value(struct book value[], int count)
{
	int index;
	int seek;
	struct book ptr;
	for(index = 0; index < count - 1; index++)
	    for(seek = index + 1; seek < count; seek++)
	    {
    		if((value[index].value - value[seek].value) > 0)
    		{
		    	ptr = value[index];
		    	value[index] = value[seek];
		    	value[seek] = ptr;
		    }
    	}
	puts("Here is the list of your books in order of increased value :");
	for(index = 0; index < count; index++)
	    printf("%s by %s: $%.2f\n",value[index].title,value[index].author,
		       value[index].value);
    putchar('\n');
}
