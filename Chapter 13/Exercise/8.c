#include<stdio.h>
#include<stdlib.h>
#define MAX 80
int count_char(FILE *fp, int ch);

int main(int argc, char * argv[])
{
	FILE *fp;
	int i;
	int ch;
	
	if(argc < 2)
	{
		printf("Usage: %s filename\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	ch = argv[1][0];
	else if(argc == 2)
	{
		printf("The character %c appears %d times\n",ch,count_char(fp,stdin));
	}
	else
	{
		for(i = 2;i <= argc;i++)
		{
		    if((fp = fopen(argv[i],"r")) == NULL)
		    {
			    fprintf(stderr,"Can't open file %s\n",argv[i]);
			    continue;
		    }
		    printf("The character %c appears in file %s %d times\n",ch,argv[i],count_char(fp,ch));
		    fclose(fp);
		}
	}
	
	return 0;
}

int count_char(FILE *fp, int ch)
{
	int cmp;
	int count = 0;
	while((cmp = getc(fp)) != EOF)
	{
		if(cmp == ch)
		   count++;
	}
	
	return count;
}
