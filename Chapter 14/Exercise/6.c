#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 18

struct player {
	int number;
	char fname[20];
	char lname[20];
	int bits;
	int hits;
	int walks;
	int RBIs;
	float average;
};

void clearstruct(struct player info[]);
void get_info(struct player info[]);
void cal_aver(struct player info[]);
void show(struct player info[]);

int main(void)
{
	struct player handle[MAX];
	clearstruct(handle);
	get_info(handle);
	cal_aver(handle);
	show(handle);
	
	return 0;
}

void clearstruct(struct player info[])
{
	int index;
	for(index = 0; index < MAX; index++)
	{
		info[index].number = index + 1;
		strcpy(info[index].fname, "");
		strcpy(info[index].lname, "");
		info[index].bits = 0;
		info[index].hits = 0;
		info[index].walks = 0;
		info[index].RBIs = 0;
		info[index].average = 0;
	}
}

void get_info(struct player info[])
{
	int number,bits,hits,walks,RBIs;
	int index;
	char fname[20];
	char lname[20];
	char filename[20];
	
	puts("Input the filename:");
	gets(filename);
	FILE * fp;
	if((fp = fopen(filename,"r")) == NULL)
	{
		fprintf(stderr,"Can't open file %s\n",filename);
		exit(EXIT_FAILURE);
	}
	for(index = 0; index < MAX; index++)
	{
		while(fscanf(fp, "%d %s %s %d %d %d %d\n",&number, fname, lname, &bits, &hits,
              &walks, &RBIs) == 7)
        {
        	if(info[index].number == number)
        	{
	        	strcpy(info[index].fname, fname);
	        	strcpy(info[index].lname, lname);
        	    info[index].bits += bits;
        	    info[index].hits += hits;
        	    info[index].walks += walks;
        	    info[index].RBIs += RBIs;
	        }
        }
	}
	if(fclose(fp) != '\0')
	   fputs("Error in closing files.",stderr);
}

void cal_aver(struct player info[])
{
	int index;
	for(index = 0; index < 18; index++)
    {
		if(info[index].bits)
		   info[index].average = (float)info[index].hits / (float)info[index].bits;
	}	
}

void show(struct player info[])
{
	int index;
	struct player total = {0,"","",0,0,0,0,0};
	for(index = 0; index < MAX; index++)
	{
		printf("%7d%10s%10s%5d%5d%5d%5d%10g\n", index + 1, info[index].fname, info[index].lname,
		       info[index].bits, info[index].hits, info[index].walks, info[index].RBIs, info[index].average);
	    total.bits += info[index].bits;
		total.hits += info[index].hits;
		total.walks += info[index].walks;
		total.RBIs += info[index].RBIs; 
	}
	if(total.bits)
	   total.average = (float)total.hits / (float)total.bits;
    printf("Total team:\n");
    printf("%5d%5d%5d%5d%10g\n", total.bits, total.hits, total.walks, total.RBIs, total.average);
}
