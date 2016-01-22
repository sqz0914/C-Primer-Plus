#include<stdio.h>
#define ROWS 3
#define COLS 4
int sum_add2(int rows, int cols, int ar[rows][cols]);
int main(void)
{
	int i,j;
	int rs = 3;
	int cs = 10;
	
	int junk[ROWS][COLS] = 
	{
		{2,4,6,8},
		{3,5,7,9},
		{12,10,8,6}
	};
	
	int morejunk[ROWS-1][COLS+2] = 
	{
		{20,30,40,50,60,70},
		{5,6,7,8,9,10}
	};
	
	int varr[rs][cs];
	
	for(i = 0;i < rs;i++)
    {
    	for(j = 0;j < cs;j++)
    	   varr[i][j] = i*j + j;
 	   varr[i][j] = i*j + j;
    }
    
    printf("3x4 array\n");
    printf("Sum of all elements = %d\n",sum_add2(ROWS,COLS,junk));
    
    printf("2x6 array\n");
    printf("Sum of all elements = %d\n",sum_add2(ROWS-1,COLS+2,morejunk));
    
    printf("3x10 array\n");
    printf("Sum of all elements = %d\n",sum_add2(rs,cs,varr));
    
    return 0;
}

int sum_add2(int rows, int cols, int ar[rows][cols])
{
	int r;
	int j;
	int total = 0;
	
	for(r = 0;r < rows;r++)
	    for(j = 0;j < cols;j++)
	    total += ar[r][j];
    
    return total;
}
