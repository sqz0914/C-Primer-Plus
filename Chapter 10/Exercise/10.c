#include<stdio.h>
#define ROWS 3
#define COLS 5
void show(int ar[][COLS], int rows);
void multi(int ar[][COLS], int rows);
int main(void)
{
	int ar[ROWS][COLS] = 
	{
		{3,2,4,6,7},
		{6,9,10,13,14},
		{9,3,5,2,1}
	};
	printf("The orginal array:\n");
	show(ar,ROWS);
	multi(ar,ROWS);
	printf("The doubled array:\n");
	show(ar,ROWS);
	
	return 0;
}
void show(int ar[][COLS], int rows)
{
	int r,c;
	for(r = 0;r < rows;r++)
	{
		for(c = 0;c < COLS;c++)
		    printf("%4d",ar[r][c]);
        printf("\n");
	}
}
void multi(int ar[][COLS], int rows)
{
	int r,c;
	for(r = 0;r < rows;r++)
		for(c = 0;c < COLS;c++)
		ar[r][c] *= 2;
}
