#include<stdio.h>
#include<string.h>
void fit(char * ptr, unsigned int size);
int main(void)
{
	char mesg[] = "Things should be as simple as possible,"
	              " but not simpler.";
    puts(mesg);
    fit(mesg,38);
    puts(mesg);
    printf("Let's look at some more of the string.\n");
    puts(mesg+39);
    
    return 0;
}
void fit(char * ptr, unsigned int size)
{
	if(strlen(ptr) > size)
	   *(ptr + size) = '\0';
}
