#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void showmovies(Item item);

int main(void)
{
	List movies;
	Item temp;
	
	initializeList(&movies);
	if(ListIsFull(&movies))
	{
		fputs("No memory available!Bye!\n", stderr);
		exit(EXIT_FAILURE);
	}
	
	puts("Enter the first movie title:");
	while(gets(temp.title) != NULL && temp.title[0] != '\0')
	{
		puts("Enter your rating <0-10>:");
		scanf("%d", &temp.rating);
		while(getchar() != '\n')
		  continue;
        if(AddItem(temp, &movies) == false)
        {
        	fputs("Problem allocating memory\n",stderr);
        	break;
        }
        if(ListIsFull(&movies))
        {
        	puts("The list is now full");
        	break;
        }
        puts("Enter next movie title (empty line to qiut):");
	}
	
	if(ListIsEmpty(&movies))
	    puts("No data entered.");
    else
    {
    	puts("Here is the movie list:");
    	traverse(&movies, showmovies);
    }
    printf("You entered %d movies.\n", ListItemCount(&movies));
    
    EmptyTheList(&movies);
    puts("Bye!");
    
    return 0;
}

void showmovies(Item item)
{
	printf("Movie: %s      Rating: %d\n", item.title, item.rating);
}
