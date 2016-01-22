#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct month {
	char name[20];
	char abb[4];
	int days;
	int monnum;
};

const struct month months[12] = {
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

int tell_days(char name[]);

int main(void)
{
	int total_day;
	char input[20];
	puts("Enter the name of the month (empty line to qiut):");
	while(gets(input) != NULL && input[0] != '\0')
	{
		total_day = tell_days(input);
		if(total_day > 0)
		   printf("The total days in the year up to and including the month is %d.\n",total_day);
        else
           puts("Your input is invalid. Try again!");
        puts("Enter the next name of the month (empty line to qiut):");
	}
	puts("Bye!");
	
	return 0;
}

int tell_days(char name[])
{
	int daytotal = 0;
	int monthnum = 0;
	int index;
	
	if(name[0] == '\0')
	   daytotal = -1;
    else
    {
    	name[0] = toupper(name[0]);
    	for(index = 1; name[index] != '\0'; index++)
    	    name[index] = tolower(name[index]);
	    for(index = 0; index < 12; index++)
	    {
    		if(strcmp(name, months[index].name) == 0)
  		    {
    		  	monthnum = months[index].monnum;
    		  	break;
  		    }
    	}
    	if(monthnum == 0)
    	   daytotal = -1;
 	    else
 	    {
    	 	for(index = 0; index < monthnum; index++)
    	 	   daytotal += months[index].days; 
   	    }
    }
    
    return daytotal;
}
