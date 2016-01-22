#include<stdio.h>
#include<string.h>
#define SIZE 20
int main(void)
{
	char input[255];
	int index;
    
    printf("Please input some characters:\n");
    for(index = 0;index < SIZE;index++)
        scanf("%c",&input[index]);
    for(index = SIZE - 1;index >= 0;index--)
        printf("%c",input[index]);
    printf("\n");
    return 0;
}
