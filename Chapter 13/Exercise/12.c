#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	char photo[20][31];
	int num[20][30];
	int cols,rows;
	int i = 0;
	FILE *fp;
	char table[9] = " .':~*=%#";
	
	if((fp = fopen("12.txt","r")) == NULL)
	{
		fprintf(stderr,"Can't open file \"12.txt\"\n");
		exit(EXIT_FAILURE);
	}
	for(rows = 1;rows <= 20;rows++)
		for(cols = 1;cols <= 30;cols++)
        {
       	       fscanf(fp,"%d",&num[rows][cols]);
       	       photo[rows][cols] = table[num[rows][cols]];
        }
   for(rows = 1;rows <= 20;rows++)
       photo[rows][31] = '\0';
   for(rows = 1;rows <= 20;rows++)
   {
       puts(photo[rows]);
   }
   if(fclose(fp) != 0)
      fprintf(stderr,"Error in closing files\n");
   if((fp = fopen("12.txt","a+")) == NULL)
   {
   	   fprintf(stderr,"Can't open file \"12.txt\"\n");
   	   exit(EXIT_FAILURE);
   }
   for(rows = 1;rows <= 20;rows++)
       fprintf(fp,"%s",photo[rows]);
   if(fclose(fp) != 0)
      fprintf(stderr,"Error in closing files\n");
   
   return 0;
}