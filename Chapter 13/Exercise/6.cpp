#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 40
int main(void)
{
	FILE *in,*out;
	int ch;
	char in_file[LEN];
	char out_file[LEN];
	int count = 0;
	
	puts("Enter the name of the file:");
	scanf("%s",in_file);
	if((in = fopen(in_file,"r")) == NULL)
	{
		fprintf(stderr,"I could not open the file \"%s\"\n",in_file);
		exit(EXIT_FAILURE);
	}
	strncpy(out_file,in_file,LEN - 5);
	out_file[LEN - 5] = '\0';
	strcat(out_file,".red");
	if((out = fopen(out_file,"w")) == NULL)
	{
		fprintf(stderr,"I could not open the file \"%s\"\n",out_file);
		exit(EXIT_FAILURE);
	}
	while((ch = getc(in)) != EOF)
	{
		if(count++ % 3 == 0)
		   putc(ch,out);
	}
	if(fclose(in) != 0 || fclose(out) != 0)
	  fprintf(stderr,"Error in closing files\n");
    
    return 0;
}
