#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFSIZE 1024
void append(FILE *source, FILE *dest);
int main(int argc, char *argv[])
{
	FILE *fa,*fs;
	int files = 0;
	int i;
	if((fa = fopen(argv[1],"a")) == NULL)
	{
		fprintf(stderr,"Can't open file %s\n",argv[1]);
		exit(EXIT_FAILURE);
	}
	if(setvbuf(fa,NULL,_IOFBF,BUFSIZE) != 0)
	{
		fprintf(stderr,"Can't create output buffer\n");
		exit(EXIT_FAILURE);
	}
	for(i = 2;i <= argc;i++)
	{
		if(strcmp(argv[1],argv[i]) == 0)
		   fputs("Can't append file itself\n",stderr);
		else if((fs = fopen(argv[i],"r")) == NULL)
		{
			fprintf(stderr,"Can't open file %s\n",argv[i]);
			exit(EXIT_FAILURE);
		}
		else
		{   if(setvbuf(fs,NULL,_IOFBF,BUFSIZE) != 0)
		    {
			     fputs("Can't create input buffer\n",stderr);
			     continue;
	        }
	        append(fs,fa);
	        if(ferror(fs) != 0)
	           fprintf(stderr,"Error in reading file %s\n",argv[i]);
            if(ferror(fa) != 0)
               fprintf(stderr,"Error in writing file %s\n",argv[1]);
            fclose(fs);
            files++;
            printf("File %s appended.\n",argv[i]);
		}
	}
	printf("Done. %d files appended.\n",files);
	fclose(fa);
	
	return 0;
}

void append(FILE *source, FILE *dest)
{
	size_t bytes;
	static char temp[BUFSIZE];
	while((bytes = fread(temp,sizeof(char),BUFSIZE,source)) > 0)
	      fwrite(temp,sizeof(char),bytes,dest);
}
