#include<stdio.h>
#define MAXTIL 41
#define MAXAUT 31
struct book {
   char title[MAXTIL];
   char author[MAXAUT];
   float value;
};
	
int main(void)
{
	struct book library;
	puts("Please enter the book title.");
	gets(library.title);
	puts("Now enter the author.");
	gets(library.author);
	puts("Now enter the value.");
	scanf("%f",&library.value);
	printf("%s by %s : $%.2f\n",library.title,library.author,library.value);
	printf("%s: \"%s\" ($%.2f)\n",library.author,library.title,library.value);
	
	return 0;
}
