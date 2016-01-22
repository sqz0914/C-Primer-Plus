#include<stdio.h>
#include<string.h>
#define SIZE 40
#define LIM 5
#define TARGETSIZE 7
int main(void)
{
	char qwords[LIM][SIZE];
	char temp[SIZE];
	int i = 0;
	
	printf("Enter %d words beginning with q:\n",LIM);
	while(i < LIM && gets(temp))
	{
		if(strncmp(temp,"q",1) != 0)
		   printf("%s doesn't begin with q!\n",temp);
        else
        {
        	strncpy(qwords[i],temp,TARGETSIZE - 1);
        	qwords[i][TARGETSIZE-1] = '\0';
        	i++;
        }
	}
	puts("Here are the words accepted:");
	for(i = 0;i < LIM;i++)
	   puts(qwords[i]);
	   
    return 0;
}
