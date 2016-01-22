#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFSIZE 1024
#define SLEN 80
void append(FILE *fa, FILE *fs);
int main(void)
{
	FILE *fa,*fs;
	int files = 0;
	char file_app[SLEN];
	char file_src[SLEN];
	puts("Enter name of destination file:");
	gets(file_app);
	if((fa = fopen(file_app,"a")) == NULL)
	{
		fprintf(stderr,"Can't open %s\n",file_app);
		exit(EXIT_FAILURE);
	}
	if(setvbuf(fa,NULL,_IOFBF,BUFSIZE) != 0)
	{
		fputs("Can't create output buffer\n",stderr);
		exit(EXIT_FAILURE);
	}
	puts("Enter name of first source file (empty line to qiut):");
	while(gets(file_src) && file_src[0] != '\0')
	{
		if(strcmp(file_app,file_src) == 0)
		   fputs("Can't append file to itself\n",stderr);
        else if((fs = fopen(file_src,"r")) == NULL)
        {
        	fprintf(stderr,"Can't open %s\n",file_src);
        	exit(EXIT_FAILURE);
        }
        else
        {
        	if((setvbuf(fs,NULL,_IOFBF,BUFSIZE)) != 0)
        	   fputs("Can't create input buffer",stderr);
     	    append(fa,fs);
     	    if(ferror(fs) != 0)
     	       fprintf(stderr,"Error in reading file %s\n",file_src);
  	        if(ferror(fa) != 0)
  	           fprintf(stderr,"Error in reading file %s\n",file_app);
            fclose(fs);
            files++;
            printf("File %s appended\n",file_src);
        	puts("Next file (empty line to qiut):");
        }
	}
	printf("Done. %d files appended.\n",files);
	
	return 0;
}
void append(FILE *fa, FILE *fs)
{
	size_t bytes;
	static char temp[BUFSIZE];
	while((bytes = fread(temp,sizeof(char),BUFSIZE,fs)) > 0)
	     fwrite(temp,sizeof(char),bytes,fa);
}
