#include<stdio.h>
#include<stdlib.h>
int main(int argc, char * argv[])
{
	int i;
	FILE *fp;
	int ch;
	
	if(argc < 2)
	{
		printf("Usage: %s filename\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	for(i = 1;i <= argc;i++)
	{
		if((fp = fopen(argv[i],"r")) == NULL)
		{
			fprintf(stderr,"Can't open file %s\n",argv[i]);
			exit(EXIT_FAILURE);
		}
		printf("The content of file %s:\n",argv[i]);
		while((ch = getc(fp)) != EOF)
		{
			putc(ch,stdout);
		}
		fclose(fp);
		putchar('\n');
	}
	putchar('\n');
	
	return 0;
}
