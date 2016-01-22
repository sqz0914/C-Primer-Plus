#include<stdio.h>
#include<stdlib.h>
#define MAX 40
int main(void)
{
	FILE *fp;
	char words[MAX];
	int count = 1;
	
	if((fp = fopen("wordy","a+")) == NULL)
	{
		fprintf(stderr,"Can't open file \"wordy\"\n");
		exit(EXIT_FAILURE);
	}
	
	puts("Enter words to add to the file; press the Enter");
	puts("key at the beginning of a line to terminate.");
	while(gets(words) != NULL && words[0] != '\0')
        fprintf(fp,"Word%d:%s\n",count++,words);	
    puts("File contents:");
    rewind(fp);
    while(fscanf(fp,"%s",words) == 1)
    	puts(words);
    if(fclose(fp) != 0)
       fprintf(stderr,"Error in closing files\n");
    
    return 0;
} 
