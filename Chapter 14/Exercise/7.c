#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXTITL 40
#define MAXAUTH 40
#define MAXBKS 100
#define CONTINUE 0
#define DONE 1
#define YES 1
#define NO 0

struct book {
	char title[MAXTITL];
	char author[MAXAUTH];
	float value;
	int Delete;
};

int getlet(const char * s);
int getbook(struct book * pb);
void update(struct book * item);

int main(void)
{
	struct book library[MAXBKS];
	int count = 0;
	int deleted = 0;
	int index, filecount,open;
	FILE * pbooks;
	int size = sizeof(struct book);
	
	if((pbooks = fopen("book.txt","r+b")) == NULL)
	{
		fputs("Can't open file \"book.txt\"\n",stderr);
		exit(EXIT_FAILURE);
	}
	rewind(pbooks);
	while(count < MAXBKS && fread(&library[count],size,1,pbooks) == 1)
	{
		if(count == 0)
		   puts("Current contents of \"book.txt\"");
        printf("%s by %s: %.2f\n", library[count].title, library[count].author,
		       library[count].value);
        puts("Do you wish to change or delete this entry? <y/n>");
        if(getlet("yn") == 'y')
        {
        	puts("Enter c to change, d to delete:");
        	if(getlet("cd") == 'd')
        	{
	        	library[count].Delete = YES;
	        	deleted++;
	        	puts("Entry marked for deletion.");
	        }
	        else
	           update(&library[count]);
        }
        count++;
	}
	filecount = count - deleted;
	if(count == MAXBKS)
	{
		fputs("The \"book.txt\" file is full.",stderr);
		exit(EXIT_FAILURE);
	}
	
	puts("Please add new book titiles.");
	puts("Press [Enter] at the start of a line to stop.");
	open = 0;
	while(filecount < MAXBKS)
	{
		if(filecount < count)
		{
			while(library[open].Delete == NO)
			      open++;
            if(getbook(&library[open]) == DONE)
               break;
		}
		else if(getbook(&library[filecount]) == DONE)
		        break;
        filecount++;
        if(filecount < MAXBKS)
           puts("Enter the next title.");
	}
	if(filecount > 0)
	{
		puts("Here is the list of your books:");
		for(index = 0; index < filecount; index++)
		    if(library[index].Delete == NO)
            {
           	     printf("%s by %s: %.2f\n", library[index].title, library[index].author,
		                library[index].value);
                 fwrite(&library[index],size,1,pbooks);
            }    
	}
	fclose(pbooks);
	puts("Done!");
}

int getlet(const char * s)
{
	int c;
	c = getchar();
	while(strchr(s,c) == NULL)
	{
		printf("Enter the character in the list %s.\n",s);
		while(getchar() != '\n')
		      continue;
		c = getchar();
	}
	while(getchar() != '\n')
          continue;
    
	return c;
}

int getbook(struct book * pb)
{
	int status = CONTINUE;
	if(gets(pb->title) == NULL && pb->title[0] == '\0')
	   status = DONE;
    else
    {
    	puts("Now enter the author:");
    	gets(pb->author);
    	puts("Now enter the value");
    	while(scanf("%f",&pb->value) != 1)
    	{
	    	puts("Plese enter the numeric value.");
	    	scanf("%*s");
	    }
	    while(getchar() != '\n')
	          continue;
        pb->Delete = NO;
    }
    
    return status;
}

void update(struct book * item)
{
	struct book copy;
	char c;
	
	copy = *item;
	puts("Enter the letter that indicates your choice:");
    puts("t) modify title     a) modify author");
    puts("v) modify value     s) quit, saving changes");
    puts("q) quit, ignore changes");
    while((c = getlet("tavsq")) != 's' && c != 'q')
    {
    	switch(c)
    	{
	    	case 't' : puts("Enter new title: ");
                       gets (copy.title);
                       break;
            case 'a' : puts("Enter new author: ");
                       gets (copy.author);
                       break;
            case 'v' : puts("Enter new value: ");
                       while (scanf("%f", &copy.value) != 1)
                       {
                           puts ("Enter a numeric value: ");
                           scanf("%*s");
                       }
                       while( getchar() != '\n')
                           continue;
                       break; 
	    }
	    puts("Enter the letter that indicates your choice:");
        puts("t) modify title     a) modify author");
        puts("v) modify value     s) quit, saving changes");
        puts("q) quit, ignore changes");
    }
    if(c == 's')
      *item = copy;
}
