#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 40
int main(void)
{
	char src_file[MAX];
	char output_file[MAX];
	FILE *src,*output;
	char ch;
	
	puts("Please enter the name of the text file:");
	gets(src_file);
	puts("Please enter the name of the output file:");
	gets(output_file);
	if((src = fopen(src_file,"r")) == NULL)
	{
		fprintf(stderr,"Can't open the text file %s\n",src_file);
		exit(EXIT_FAILURE);
	}
	if((output = fopen(output_file,"w")) == NULL)
	{
		fprintf(stderr,"Can't open the output file %s\n",output_file);
		exit(EXIT_FAILURE);
	}
	while((ch = getc(src)) != EOF)
	{
		putc((int) toupper(ch) , output);
	}
	if(fclose(src) != 0 || fclose(output) != 0)
	{
		fprintf(stderr,"Error in closing files\n");
	}
	printf("Copy finished\n");
	
	return 0;
}
