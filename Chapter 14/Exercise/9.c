#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define LEN 40
#define SEATS 12
#define FLIGHT 4
#define CHOICES 6
#define EMPTY 0
#define TAKEN 1
#define CONTINUE 0
#define DONE 1

struct flight {
	int seat_id;
	int status;
	char lname[LEN];
	char fname[LEN];
};

struct airline {
	const int number;
	struct flight plane[SEATS];
};

int showmenu(struct airline pl[]);
int getmenu(void);
int getlet(const char * s);
int openings(struct airline pl[], int n);
void show_empties(struct airline pl[], int n);
void list_assign(struct airline * pl[], int n);
void assign_seat(struct airline pl[], int n);
void delete_seat(struct airline pl[], int n);
void show_seat(const struct airline pl[], int n);
void sort(struct airline * pl[], int n);
void makelist(const struct airline pl[], char * str, int n, int kind);

int main(void)
{
	struct airline handle[FLIGHT] = {
		{102},
		{311},
		{444},
		{519}
	};
	
	struct airline *ps[FLIGHT];
	int c;
	int choice;
	int i,j;
	FILE * fp;
	size_t size = sizeof(struct airline);
	
	for(i = 0; i < SEATS; i++)
	    ps[i] = &handle[i];
    if((fp = fopen("air.txt","rb")) == NULL)
    {
    	for(i = 0; i < FLIGHT; i++)
    	    for(j = 0; j < SEATS; j++)
    	   {
	    	   handle[i].plane[j].seat_id = j + 1;
	    	   handle[i].plane[j].status = EMPTY;
	       }
    }
	else
	{
		fread(handle, size, FLIGHT, fp);
		fclose(fp);
	}
	showmenu(handle);
	while(scanf("%d",&c) == 1)
	{
		while(getchar() != '\n')
		      continue;
		if(c > 0 || c < 5)
		{
			show_seat(handle, c);
			printf("This is %d flight.\n",handle[c - 1].number);
			while((choice = getmenu()) != 'q')
	        {
		           switch(choice)
		           {
			              case 'o' : printf("There is %d seats empty.\n",openings(handle, c - 1));
			                         break;
                          case 'e' : show_empties(handle, c - 1);
                                     break;
                          case 'l' : list_assign(ps, c - 1);
                                     break;
                          case 'a' : assign_seat(handle, c - 1);
                                     break;
                          case 'd' : delete_seat(handle, c - 1);
                                     break;
                          default : puts("Switch Trouble");
                                    break;
		           }
	        }
		}
		showmenu(handle);	
	}
	
	if((fp = fopen("air.txt","wb")) == NULL)
		puts("Can't save the data to the file.");
	else
	{
		fwrite(handle, size, FLIGHT, fp);
		fclose(fp);
	}
}

int showmenu(struct airline pl[])
{
	int i;
	puts("Here is the airline list:");
	for(i = 0; i < FLIGHT; i++)
		printf("%d) %d\t", i + 1, pl[i].number);
	putchar('\n');
	puts("Which airline do you want to choose?");
}

int getmenu(void)
{
	const char * descript[CHOICES] = {
		"Show number of empty seats",
		"Show list of empty seats",
		"Show alphabetical list of seats",
		"Assign a customer to a seat assignment",
		"Delete a seat assignment",
		"Qiut"
	};
	const char labels[CHOICES + 1] = {"oeladq"};
	int index;
	
	puts("To choose a function, enter its letter:");
	for(index = 0; index < CHOICES; index++)
	{
		printf("%c) %s\n", labels[index], descript[index]);
	}
	
	return (getlet(labels));
}

int getlet(const char * s)
{
	int c;
	c = getchar();
	while(strchr(s, c) == NULL)
	{
		printf("Enter a character in the list %s\n",s);
		while(getchar() != '\n')
		      continue;
        c = getchar();
	}
	while(getchar() != '\n')
	      continue;
    
    return c;
}

int openings(struct airline pl[], int n)
{
	int count = 0;
	int seat;
	for(seat = 0; seat < SEATS; seat++)
	{
		if(pl[n].plane[seat].status == EMPTY)
		   count++;
	}
	
	return count;
}

void show_empties(struct airline pl[], int n)
{
	char seating[3 * SEATS];
	
	if(openings(pl, n) == 0)
	   puts("All seats are assigned.");
    else
    {
    	puts("The following seats are available:");
    	makelist(pl, seating, n, EMPTY);
    	puts(seating);
    }
}
void makelist(const struct airline pl[], char * str, int n, int kind)
{
	int seat;
	char temp[LEN];
	
	str[0] = '\0';
	for(seat = 0; seat < SEATS; seat++)
	{
		if(pl[n].plane[seat].status == kind)
		{
			sprintf(temp,"%d ",pl[n].plane[seat].seat_id);
			strcat(str, temp);
		}
	}
}

void list_assign(struct airline * ps[], int n)
{
	int i;
	if(openings(*ps, n) == SEATS)
		puts("All seats are empty.");
	else
	{
		sort(ps, n);
		for(i = 0; i < SEATS; i++)
		{
			if(ps[i]->plane[SEATS].status == TAKEN)
			  printf("Seat %d: %s %s\n",ps[i]->plane[SEATS].seat_id, ps[i]->plane[SEATS].lname, 
			          ps[i]->plane[SEATS].fname);
		}
	}
}
void assign_seat(struct airline pl[], int n)
{
	int seat,loop;
	char list[3 * SEATS];
	
	if(openings(pl, n) == 0)
	   puts("All seats are assigned.");
    else
    {
    	makelist(pl, list, n, EMPTY);
    	puts("Which seat do you want? Choose from this list:");
    	puts(list);
    	do
    	{
	    	while(scanf("%d",&seat) != 1)
	    	{
	    		scanf("%*s");
	    		puts("Enter a number from the list:");
	    		puts(list);
	    	}
	    	if(seat < 1 || seat > SEATS || pl[n].plane[seat - 1].status == TAKEN)
	    	{
	    		puts("Enter a number from the list:");
	    		puts(list);
	    		loop = CONTINUE;
	    	}
	    	else
	    	    loop = DONE;
	    }
	    while(loop = CONTINUE);
	    while(getchar() != '\n')
              continue;
        puts("Enter first name:");
        gets(pl[n].plane[seat - 1].fname);
        puts("Enter last name:");
        gets(pl[n].plane[seat - 1].lname);
        printf("%s %s assigned to seat %d.\n",pl[n].plane[seat - 1].fname, pl[n].plane[seat - 1].lname, seat);
        puts("Enter a to accept assignment, c to cancel it.");
        if(getlet("ac") == 'a')
        {
        	pl[n].plane[seat - 1].status = TAKEN;
        	puts("Passenger assigned to seat.");
        }
        else
            puts("Passenger not assigned to seat.");

    }
}

void delete_seat(struct airline pl[], int n)
{
	char list[3 * SEATS];
	int seat, loop;
	if(openings(pl, n) == SEATS)
	   puts("All seats empty.");
    else
    {
    	makelist(pl, list, n, TAKEN);
    	puts("What seat do you want to delete? Choose from the list:");
    	puts(list);
    	do
    	{
	    	while(scanf("%d",&seat) != 1)
	    	{
	    		scanf("%*s");
	    		puts("Enter a number from the list:");
	    		puts(list);
	    	}
	    	if(seat < 1 || seat > SEATS || pl[n].plane[seat].status == EMPTY)
	    	{
	    		puts("Enter a number from the list:");
	    		puts(list);
	    		loop = CONTINUE;
	    	}
	    	else
	    	    loop = DONE;
	    }
	    while(loop = CONTINUE);
	    while(getchar() != '\n')
	          continue;
        printf("%s %s to be canceled for seat %d.\n",pl[n].plane[seat - 1].fname, pl[n].plane[seat - 1].fname, 
		        seat);
        puts("Enter d to delete assignment, a to abort.");
        if(getlet("ad") == 'd')
        {
        	pl[n].plane[seat - 1].status == EMPTY;
        	puts("Passenger dropped.");
        } 
        else
           puts("Passenger retained.");
    }
}

void show_seat(const struct airline pl[], int n)
{
	int seat;
	
	puts("Seats currently status:");
	for(seat = 0; seat < SEATS; seat++)
	{
		if(pl[n].plane[seat].status == TAKEN)
		   printf("Seat %d: %s, %s, %s\n", pl[n].plane[seat].seat_id,pl[n].plane[seat].lname, 
		           pl[n].plane[seat].fname,"TAKEN");
        else if(pl[n].plane[seat].status == EMPTY)
           printf("Seat %d: %s\n", pl[n].plane[seat].seat_id, "EMPTY");
	}
}

void sort(struct airline * array[], int n)
{
	int top, seek;
	struct flight temp;
	
	for(top = 0; top < SEATS - 1; top++)
	{
		for(seek = top + 1; seek < SEATS; seek++)
	    {
    		if(strcmp(array[n]->plane[top].lname, array[n]->plane[seek].lname) > 0)
    		{
		    	temp = array[n]->plane[seek];
		    	array[n]->plane[seek] = array[n]->plane[top];
		    	array[n]->plane[top] = temp;
		    }
    	}
	}   
}
