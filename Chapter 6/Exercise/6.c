#include<stdio.h>
#include<string.h>
int main(void)
{
	char input[26];
	int index;
	
	printf("Please enter a single word:\n");
	scanf("%s",input);
	for(index = strlen(input) - 1;index >= 0;index--)
	   printf("%c",input[index]);
    printf("\n");
    return 0;
}
