#include<stdio.h>
#include<stdlib.h>
#define CNTL_Z '\032'
#define SLEN 50
int main(void)
{
	FILE *fp;
	char ch;
	char file[SLEN];
	int count,last;
	
	puts("Enter the name of the file to be processed:");
	gets(file);
	if((fp = fopen(file,"rb")) == NULL)
	{
		fprintf(stderr,"reverse can't open %s\n",file);
		exit(EXIT_FAILURE);
	}
	fseek(fp,0L,SEEK_END);
	last = ftell(fp);
	for(count = 1L;count <= last;count++)
	{
		fseek(fp,-count,SEEK_END);
		if((ch = getc(fp)) != '\r' && (ch = getc(fp)) != CNTL_Z)
		   putchar(ch);
	}
	putchar('\n');
	fclose(fp);
	
	return 0;
}
