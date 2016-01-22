#include<stdio.h>
#include<stdlib.h>
#define MAX 40
int main(void)
{
	char words[MAX];
	FILE *fp;
	
	if((fp = fopen("wordy","a+")) == NULL)
	{
		fprintf(stdout,"Can't open \"wordy\" file.\n");
		exit(EXIT_FAILURE);
	}
	puts("Enter words to add to the file;press the Enter");
	puts("Key at the beginning of a line to terminate");
	while(gets(words) != NULL && words[0] != '\0')
	{
		fprintf(fp,"%s",words);
	}
	
	puts("File contents:");
	while((fscanf(fp,"%s",words)) == 1)
	{
		puts(words);
	}
	
	if(fclose(fp) != 0)
	   fprintf(stderr,"Error closing file\n");
	   
    return 0;
}
