#include <stdio.h>
#define TSIZE 45
#define FMAX 5

struct film {
	char title[TSIZE];
	int rating;
};

int main(void)
{
	struct film movie[FMAX];
	int i = 0;
	int j;
	
	puts("Enter first movie title:");
	while(i < FMAX && gets(movie[i].title) != NULL && movie[i].title[0] != '\0')
	{
		puts("Enter your rating <0-10>:");
		scanf("%d", &movie[i++].rating);
		while(getchar() != '\n')
		      continue;
        puts("Enter next movie title (empty line to stop):");
	}
	if(i == 0)
	  puts("No data entered.");
    else
      puts("Here is the movie list:");
    
    for(j = 0; j < i; j++)
        printf("Movie: %s  Rating: %d\n", movie[j].title, movie[j].rating);
    puts("Bye!");
    
    return 0;
}
