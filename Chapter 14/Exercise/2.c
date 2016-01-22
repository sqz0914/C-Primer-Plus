#include<stdio.h>
#include<ctype.h>

struct month {
	char name[20];
	char abb[4];
	int days;
	int monnum;
};

struct month months[12] = {
	{"January", "Jan", 31, 1},
    {"February", "Feb", 28, 2},
    {"March", "Mar", 31, 3},
    {"April", "Apr", 30, 4},
    {"May", "May", 31, 5},
    {"June", "Jun", 30, 6},
    {"July", "Jul", 31, 7},
    {"August", "Aug", 31, 8},
    {"September", "Sep", 30, 9},
    {"October", "Oct", 31, 10},
    {"November", "Nov", 30, 11},
    {"December", "Dec", 31, 12}
};

int get_month(char * ptr);
int day(int days, int remonth, int year);
int leapyear(int year);

int main(void)
{	
    int days,in_month,year;
    int daytotal = 0;
    char input[20];
	puts("Enter the day (enter # to qiut) :");
	while(scanf("%d",&days) == 1)
	{
		while(getchar() != '\n')
		      continue;
		puts("Enter the month:");
		gets(input);
		puts("Enter the year:");
        scanf("%d",&year);
       	while(getchar() != '\n')
		      continue;
		in_month = get_month(input);
		daytotal = day(days, in_month, year);
		if(daytotal > 0)
		   printf("There are %d days through day %d, month %d, year %d.\n",daytotal,days,in_month,year);
        else
           printf("Invalid input. Try again!\n");
	    puts("Enter the day, month and year (enter # to qiut) :");        
	}
	puts("Bye!");
	
	return 0;
}

int get_month(char * ptr)
{
	int i,cmpres1,cmpres2;
	if(isdigit(*ptr))
	   return (*ptr - '0' + 1);
    else
    {
    	for(i = 0; i < 12; i++)
    	{
    	    cmpres1 = strcmp(ptr, months[i].name);
    	    cmpres2 = strcmp(ptr, months[i].abb);
    	    if(cmpres1 == 0 || cmpres2 == 0)
    	       return (i + 1);
	    }
    }
}

int day(int days, int remonth, int year)
{
	int i,daytotal;
	if(leapyear(year))
	   months[1].days = 29;
    else 
       months[1].days = 28;
    if(remonth < 1 || remonth > 12 || days < 1 || days > months[remonth - 1].days)
       return -1;
    else
    {
    	for(i = 0,daytotal = 0; i < remonth - 1; i++)
    	{
	    	daytotal += months[i].days;
	    }
	    daytotal += days;
    }
    
    return daytotal;
}

int leapyear(int year)
{
	if(year % 400 == 0)
	   return 1;
    else if(year % 100 != 0 && year % 4 == 0)
       return 1;
    else 
       return 0;
}
