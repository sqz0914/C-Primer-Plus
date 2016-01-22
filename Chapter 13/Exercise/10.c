#include<stdio.h>
#include<stdlib.h>
#define MAX 40
int main(void)
{
	int pos,ch;
	char filename[MAX];
	FILE *fp;
	
	puts("Please enter the filename:");
	gets(filename);
	if((fp = fopen(filename,"r")) == NULL)
	{
		fprintf(stderr,"Can't open file %s\n",filename);
		exit(EXIT_FAILURE);
	}
	puts("Please enter the file position (a number to stop):");
	while(scanf("%d",&pos) == 1)
	{
		fseek(fp,(long) pos,SEEK_SET);
		while((ch = getc(fp)) != '\n')
		     putchar(ch);
        putchar('\n');
	}
	if(fclose(fp) != 0)
	   fprintf(stderr,"Error in closing files\n");
	puts("Done!");
	   
    return 0;
}
