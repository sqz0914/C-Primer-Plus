#include<stdio.h>
#include<stdlib.h>
#define BUF 256
int main(int argc, char *argv[])
{
	FILE *fp1, *fp2;
	char lines1[BUF];
	char lines2[BUF];
	
	if(argc < 2)
	{
		fprintf(stderr,"Usage: %s filename\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	if((fp1 = fopen(argv[1],"r")) == NULL)
	{
		fprintf(stderr,"Can't open file %s\n",argv[1]);
		exit(EXIT_FAILURE);
	}
	if((fp2 = fopen(argv[2],"r")) == NULL)
	{
		fprintf(stderr,"Can't open file %s\n",argv[2]);
		exit(EXIT_FAILURE);
	}
	while(fscanf(fp1,"%s",lines1) != 1 || fscanf(fp2,"%s",lines2) != 1)
	{
		if(fscanf(fp1,"%s",lines1) != 1)
		   printf("%s",lines1); 
        if(fscanf(fp2,"%s",lines2) != 1)
		   printf("%s",lines2); 
        putchar('\n');
	}
	if(fclose(fp1) != 0 || fclose(fp2) != 0)
		fprintf(stderr,"Error in closing files\n");
		
	return 0;
}
