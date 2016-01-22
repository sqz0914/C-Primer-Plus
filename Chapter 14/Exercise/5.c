#include<stdio.h>
#define SCORES 3
#define CSIZE 4
#define LEN 20

struct name {
	char fname[LEN];
	char sname[LEN];
};

struct student {
	struct name handle;
	float grade[SCORES];
	float average;
};

void get_info(struct student info[]);
void get_aver(struct student info[]);
void show_info(struct student info[]);
void show_aver(struct student info[]);

int main(void)
{
	int index;
	struct student info[CSIZE] = {
		{{"Shen","Qizhuo"}},
		{{"Sun","Yuefan"}},
		{{"Xia","Lei"}},
		{{"Xu","Zhiming"}}
	};
    get_info(info);
    get_aver(info);
	show_info(info);
	show_aver(info);
	return 0;
}

void get_info(struct student info[])
{
    int i,j;
    for(i = 0; i < CSIZE; i++)
    {
    	printf("Please enter %d scores for %s %s:\n",SCORES,info[i].handle.fname,
		        info[i].handle.sname);
        for(j = 0; j < SCORES; j++)
        {
        	while(scanf("%f",&info[i].grade[j]) != 1)
        	{
	        	scanf("%*s");
	        	printf("Please use numeric input.");
	        }
        }
    }
}

void get_aver(struct student info[])
{
	int i,j;
	float total;
	
	for(i = 0; i < CSIZE; i++)
	{
		for(j = 0,total = 0; j < SCORES; j++)
		    total += info[i].grade[j];
        info[i].average = total / SCORES;
	}    
	    
}

void show_info(struct student info[])
{
	int index;
	int i;
	for(i = 0; i < CSIZE; i++)
	{
		printf("The scores of %s %s:\n",info[i].handle.fname,info[i].handle.sname);
	    for(index = 0; index < SCORES; index++)
	    printf("%-7.2f",info[i].grade[index]);
        printf("\nThe average score is %.2f\n",info[i].average);
	}
}

void show_aver(struct student info[])
{
	int i,j;
	float total;
	
	puts("QUIZ AVERAGES:    ");
	for(j = 0; j < SCORES; j++)
	{
		for(i = 0,total = 0; i < CSIZE; i++)
		    total += info[i].grade[j];
        printf("%-6.2f ",total / CSIZE);
	}	    
}
