#include<stdio.h>
#include<string.h>
#define PRAISE "What a super marvelous name!"
int main(void)
{
	char name[40];
	printf("What's your name?\n");
	scanf("%s",name);
	printf("Hello,%s.%s\n",name,PRAISE);
	printf("Your name of %d letters occupies %d memory cells.\n",strlen(name),sizeof(name));
	printf("The phrase of praise has %d letters and occupies %d memory cells.\n",strlen(PRAISE),sizeof(PRAISE));
	getchar();
	return 0;
}
