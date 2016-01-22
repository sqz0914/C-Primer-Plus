#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void de_glit(int num[][30]);
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
       	       de_glit(num);
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

void de_glit(int num[][30])
{
	int cols,rows;
	for(rows = 1;rows <= 20;rows++)
		for(cols = 1;cols <= 30;cols++)
		{
			if(rows == 1 && cols == 1)
			{
				if(abs(num[rows][cols] - num[rows + 1][cols]) > 1 && abs(num[rows][cols] - num[rows][cols + 1]) > 1)
				   num[rows][cols] = (num[rows + 1][cols] + num[rows][cols + 1]) / 2 + 0.5;
			}
			else if(rows == 1 && cols == 30)
			{
				if(abs(num[rows][cols] - num[rows + 1][cols]) > 1 && abs(num[rows][cols] - num[rows][cols - 1]) > 1)
				   num[rows][cols] = (num[rows + 1][cols] + num[rows][cols - 1]) / 2 + 0.5;
			}
			else if(rows == 20 && cols == 1)
			{
				if(abs(num[rows][cols] - num[rows - 1][cols]) > 1 && abs(num[rows][cols] - num[rows][cols + 1]) > 1)
				   num[rows][cols] = (num[rows - 1][cols] + num[rows][cols + 1]) / 2 + 0.5;
			}
			else if(rows == 20 && cols == 30)
			{
				if(abs(num[rows][cols] - num[rows - 1][cols]) > 1 && abs(num[rows][cols] - num[rows][cols - 1]) > 1)
				   num[rows][cols] = (num[rows - 1][cols] + num[rows][cols - 1]) / 2 + 0.5;
			}
			else if(rows == 1 && (cols > 1 && cols < 30))
			{
				if(abs(num[rows][cols] - num[rows + 1][cols]) > 1 && abs(num[rows][cols] - num[rows][cols - 1]) > 1
				   && abs(num[rows][cols] - num[rows][cols + 1]) > 1)
				   num[rows][cols] = (num[rows + 1][cols] + num[rows][cols - 1] + num[rows][cols + 1]) / 2 + 0.5;
			}
			else if(rows == 20 && (cols > 1 && cols < 30))
			{
			    if(abs(num[rows][cols] - num[rows - 1][cols]) > 1 && abs(num[rows][cols] - num[rows][cols - 1]) > 1
				   && abs(num[rows][cols] - num[rows][cols + 1]) > 1)
				   num[rows][cols] = (num[rows - 1][cols] + num[rows][cols - 1] + num[rows][cols + 1]) / 2 + 0.5;
			}
			else if((rows > 1 && rows < 20) && cols == 1)
			{
				if(abs(num[rows][cols] - num[rows + 1][cols]) > 1 && abs(num[rows][cols] - num[rows][cols + 1]) > 1
				   && abs(num[rows][cols] - num[rows - 1][cols]) > 1)
				   num[rows][cols] = (num[rows + 1][cols] + num[rows][cols + 1] + num[rows][cols] - num[rows - 1][cols]) / 2 + 0.5;
			}
			else if((rows > 1 && rows < 20) && cols == 30)
			{
				if(abs(num[rows][cols] - num[rows + 1][cols]) > 1 && abs(num[rows][cols] - num[rows][cols - 1]) > 1
				   && abs(num[rows][cols] - num[rows - 1][cols]) > 1)
				   num[rows][cols] = (num[rows + 1][cols] + num[rows][cols - 1] + num[rows][cols] - num[rows - 1][cols]) / 2 + 0.5;
			}
			else
			{
				if(abs(num[rows][cols] - num[rows + 1][cols]) > 1 && abs(num[rows][cols] - num[rows][cols - 1]) > 1
				   && abs(num[rows][cols] - num[rows - 1][cols]) > 1 && abs(num[rows][cols] - num[rows][cols + 1]) > 1)
				   num[rows][cols] = (num[rows + 1][cols] + num[rows][cols - 1] + num[rows][cols] - num[rows - 1][cols] + 
				   num[rows][cols + 1]) / 2 + 0.5;
			}
		}
}
