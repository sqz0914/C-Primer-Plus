#include<stdio.h>
#define ROWS 3
#define COLS 5
void store(double ar[][COLS], int rows);
double aver_row(double ar[], int n);
double aver(double ar[][COLS], int rows);
double max(double ar[][COLS], int rows);
int main(void)
{
	int i;
	int rowaverage;
	int average;
	double ar[ROWS][COLS];
	printf("Please enter three sets of five double numbers:\n");
	store(ar,ROWS);
	for(i = 0;i < ROWS;i++)
    {
    	printf("The average value of row %d: %g\n",i + 1,aver_row(*(ar + i),COLS));
    }
    printf("The average value of the array: %g\n",aver(ar,ROWS));
    printf("The max value among the array: %g\n",max(ar,ROWS));
    
    return 0;
}
void store(double ar[][COLS], int rows)
{
	int r,c;
	for(r = 0;r < rows;r++)
    {
    	 for(c = 0;c < COLS;c++)
	       scanf("%lf",&ar[r][c]);
    }
}
double aver_row(double ar[], int n)
{
	int i;
	double total;
	for(i = 0,total = 0;i < n;i++)
	    total += ar[i];
    
    return (total/n);
}
double aver(double ar[][COLS], int rows)
{
	int r,c;
	double total;

    for(r = 0,total = 0;r < rows;r++)
    	for(c = 0;c < COLS;c++)
    	    total += ar[r][c];
    
    return (total/(r*c));
}
double max(double ar[][COLS], int rows)
{
	int r,c;
	double max;
	for(r = 0;r < rows;r++)
    {
    	for(c = 0,max = ar[0][0];c < COLS;c++)
    	{
	    	if(ar[r][c] > max)
	    	   max = ar[r][c];
	    }
    }
    
    return max;
}
