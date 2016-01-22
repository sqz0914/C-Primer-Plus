#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define LEN 40
#define SEATS 12
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

int getmenu(void);
int getlet(const char *);
int openings(struct flight [], int );
void show_empties(struct flight [], int );
void list_assign(struct flight * [], int );
void assign_seat(struct flight [], int );
void delete_seat(struct flight [], int );
void show_seat(const struct flight [], int );
void sort(struct flight * [], int );
void makelist(const struct flight [], char *, int );

int main(void)
{
	struct flight plane_1[SEATS], *ps[SEATS];
	int choice;
	int i;
	FILE * fp;
	size_t size = sizeof(struct flight);
	
	for(i = 0; i < SEATS; i++)
	    ps[i] = &plane_1[i];
    if((fp = fopen("air.txt","rb")) == NULL)
    {
    	for(i = 0; i < SEATS; i++)
    	{
	    	plane_1[i].seat_id = i + 1;
	    	plane_1[i].status = EMPTY;
	    }
    }
	else
	{
		fread(plane_1, size, SEATS, fp);
		fclose(fp);
	}
	while((choice = getmenu()) != 'q')
	{
		switch(choice)
		{
			case 'o' : printf("There is %d seats empty.\n",openings(plane_1, SEATS));
			           break;
            case 'e' : show_empties(plane_1, SEATS);
                       break;
            case 'l' : list_assign(ps, SEATS);
                       break;
            case 'a' : assign_seat(plane_1, SEATS);
                       break;
            case 'd' : delete_seat(plane_1, SEATS);
                       break;
            default : puts("Switch Trouble");
                      break;
		}
	}
	if((fp = fopen("air.txt","wb")) == NULL)
		puts("Can't save the data to the file.");
	else
	{
		fwrite(plane_1, size, SEATS, fp);
		fclose(fp);
	}
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
	
	puts("To choose a function, enter its");
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

int openings(struct flight pl[], int n)
{
	int count = 0;
	int seat;
	for(seat = 0; seat < n; seat++)
	{
		if(pl[seat].status == EMPTY)
		   count++;
	}
	
	return count;
}

void show_empties(struct flight pl[], int n)
{
	char seating[3 * SEATS];
	
	if(openings(pl, n) == 0)
	   puts("All seats are assigned.");
    else
    {
    	puts("The following seats are available:");
    	makelist(pl, seating, EMPTY);
    	puts(seating);
    }
}
void makelist(const struct flight pl[], char * str, int kind)
{
	int seat;
	char temp[LEN];
	
	str[0] = '\0';
	for(seat = 0; seat < SEATS; seat++)
	{
		if(pl[seat].status == kind)
		{
			sprintf(temp,"%d ",pl[seat].seat_id);
			strcat(str, temp);
		}
	}
}

void list_assign(struct flight * ps[], int n)
{
	int i;
	if(openings(*ps, n) == SEATS)
		puts("All seats are empty.");
	else
	{
		sort(ps, n);
		for(i = 0; i < n; i++)
		{
			if(ps[i]->status == TAKEN)
			  printf("Seat %d: %s %s\n",ps[i]->seat_id, ps[i]->lname, ps[i]->fname);
		}
	}
}
void assign_seat(struct flight pl[], int n)
{
	int seat,loop;
	char list[3 * SEATS];
	
	if(openings(pl, n) == 0)
	   puts("All seats are assigned.");
    else
    {
    	makelist(pl, list, EMPTY);
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
	    	if(seat < 1 || seat > SEATS || pl[seat - 1].status == TAKEN)
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
        gets(pl[seat - 1].fname);
        puts("Enter last name:");
        gets(pl[seat - 1].lname);
        printf("%s %s assigned to seat %d.\n",pl[seat - 1].fname, pl[seat - 1].lname, seat);
        puts("Enter a to accept assignment, c to cancel it.");
        if(getlet("ac") == 'a')
        {
        	pl[seat - 1].status = TAKEN;
        	puts("Passenger assigned to seat.");
        }
        else
            puts("Passenger not assigned to seat.");

    }
}

void delete_seat(struct flight pl[], int n)
{
	char list[3 * SEATS];
	int seat, loop;
	if(openings(pl, n) == 0)
	   puts("All seats empty.");
    else
    {
    	makelist(pl, list, TAKEN);
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
	    	if(seat < 1 || seat > SEATS || pl[seat].status == EMPTY)
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
        printf("%s %s to be canceled for seat %d.\n",pl[seat - 1].fname, pl[seat - 1].fname, seat);
        puts("Enter d to delete assignment, a to abort.");
        if(getlet("ad") == 'd')
        {
        	pl[seat - 1].status == EMPTY;
        	puts("Passenger dropped.");
        }
           
        else
           puts("Passenger retained.");
    }
}

void show_seat(const struct flight pl[], int n)
{
	int seat;
	
	puts("Seats currently taken:");
	for(seat = 0; seat < n; seat++)
	{
		if(pl[seat].status == TAKEN)
		   printf("Seat %d: %s, %s\n", pl[seat].seat_id,pl[seat].lname, pl[seat].fname);
	}
}

void sort(struct flight * array[], int n)
{
	int top, seek;
	struct flight * temp;
	
	for(top = 0; top < n - 1; top++)
	    for(seek = top + 1; seek < n; seek++)
	    {
    		if(strcmp(array[top]->lname, array[seek]->lname) > 0)
    		{
		    	temp = array[seek];
		    	array[seek] = array[top];
		    	array[top] = temp;
		    }
    	}
}
