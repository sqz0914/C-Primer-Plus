#include<stdio.h>
#define ROWS 3
#define COLS 4
void sum_rows(int ar[][COLS], int rows);
void sum_cols(int [][COLS],int );
int sum_add2(int (*ar)[COLS],int rows);
int main(void)
{
	int junk[ROWS][COLS] = 
	{
		{2,4,6,8},
		{3,5,7,9},
		{12,10,8,6}
	};
	
	sum_rows(junk,ROWS);
	sum_cols(junk,ROWS);
	printf("Sum of all elements = %d\n",sum_add2(junk,ROWS));
	
	return 0;
}

void sum_rows(int ar[][COLS], int rows)
{
	int r;
	int c;
	int total;
	
	for(r = 0;r < ROWS;r++)
	{
		for(total = 0, c = 0;c < COLS;c++)
			total += ar[r][c];
		printf("row %d: sum = %d\n",r,total);
	}
}

void sum_cols(int ar[][COLS],int rows)
{
	int r;
	int c;
	int total;
	
	for(c = 0;c < COLS;c++)
	{
		for(r = 0,total = 0;r < ROWS;r++)
		    total += ar[r][c];
        printf("col %d: sum = %d\n",c,total);
	}
}

int sum_add2(int (*ar)[COLS],int rows)
{
	int r;
	int c;
	int subtotal;
	int total;
	
	for(r = 0,total = 0;r < ROWS;r++)
	{
		for(c = 0,subtotal = 0;c < COLS;c++)
		    subtotal += ar[r][c];
        total += subtotal;
	}
	
	return total;
}
