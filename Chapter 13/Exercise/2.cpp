#include<stdio.h>
#include<stdlib.h>

int main(int argc, char * argv[])
{
	FILE *ori,*copy;
	int ch;
	
	if(argc < 2)
	{
		printf("Usage: %s filename\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	if((ori = fopen(argv[1],"rb")) == NULL)
	{
		fprintf(stderr,"Can't open the original file %s\n",argv[1]);
		exit(EXIT_FAILURE);
	}
	if((copy = fopen(argv[2],"wb")) == NULL)
	{
		fprintf(stderr,"Can't open the copy file %s\n",argv[2]);
		exit(EXIT_FAILURE);
	}
	while((ch = getc(ori)) != EOF)
	{
		putc(ch,copy);
	}
	if(fclose(ori) != 0 || fclose(copy) != 0)
		printf("Error in closing files.\n");
	printf("Copy finished\n");
	
	return 0;
}
