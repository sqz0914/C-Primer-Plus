#include<stdio.h>
#define MAXTITL 40
#define MAXAUTH 40
#define MAXBKS 100
struct book {
	char title[MAXTITL];
	char author[MAXAUTH];
	float value;
};

int main(void)
{
	struct book library[MAXBKS];
	int count = 0;
	int index;
	
	puts("Please enter the book title.");
	puts("Press [Enter] at the start of a line to stop.");
	while(count < MAXBKS && gets(library[count].title) != NULL
	      &&library[count].title[0] != '\0')
    {
    	puts("Now enter the author.");
    	gets(library[count].author);
    	puts("Now enter the value.");
    	scanf("%f",&library[count++].value);
    	while(getchar() != '\n')
    	      continue;
        if(count < MAXBKS)
           puts("Enter the next title.");
    }
    
    if(count > 0)
    {
    	puts("Here is the list of your books:");
    	for(index = 0;index < count;index++)
    	    printf("%s by %s: $%.2f\n",library[index].title,library[index].author,library[index].value);
    }
    else
        puts("No books? Too bad.\n");
        
    return 0;
}
