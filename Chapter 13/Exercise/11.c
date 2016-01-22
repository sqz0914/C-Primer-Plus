#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 256
int main(int argc, char * argv[])
{
	char line[MAX];
	FILE *fp;
	if(argc < 2)
	{
		printf("Usage: %s filename\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	if((fp = fopen(argv[2],"r")) == NULL)
	{
		fprintf(stderr,"Can't open file %s\n",argv[2]);
		exit(EXIT_FAILURE);
	}
	while(fgets(line,MAX,fp) != NULL)
	{
		if(strstr(line,argv[1]) != NULL)
           fputs(line,stdout);
	}
	if(fclose(fp) != 0)
	fprintf(stderr,"Error in closing files\n");
	
	return 0;
}
