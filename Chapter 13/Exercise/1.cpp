#include<stdio.h>
#include<stdlib.h>
#define MAX 80
int main(void)
{
	int ch;
	char filename[MAX];
	FILE *fp;
	long count = 0;
	
	puts("Please enter the file name:");
	scanf("%s",filename);
	if((fp = fopen(filename,"r")) == NULL)
	{
		fprintf(stderr,"Can't open file %s\n",filename);
		exit(EXIT_FAILURE);
	}
	while((ch = getc(fp)) != EOF)
	{
		putc(ch,stdout);
		count++;
	}
	fclose(fp);
	printf("File %s has %ld characters.\n",filename,count);
	
	return 0;
}
