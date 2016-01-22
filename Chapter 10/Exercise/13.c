#include<stdio.h>
#define ROWS 3
#define COLS 5
void store(int rows, int cols, double ar[rows][cols]);
double aver_row(int n, double ar[n]);
double aver(int rows, int cols, double ar[rows][cols]);
double max(int rows, int cols, double ar[rows][cols]);
int main(void)
{
	int i;
	int rowaverage;
	int average;
	double ar[ROWS][COLS];
	printf("Please enter three sets of five double numbers:\n");
	store(ROWS,COLS,ar);
	for(i = 0;i < ROWS;i++)
    {
    	printf("The average value of row %d: %g\n",i + 1,aver_row(COLS,*(ar + i)));
    }
    printf("The average value of the array: %g\n",aver(ROWS,COLS,ar));
    printf("The max value among the array: %g\n",max(ROWS,COLS,ar));
    
    return 0;
}
void store(int rows, int cols, double ar[rows][cols])
{
	int r,c;
	for(r = 0;r < rows;r++)
    {
    	 for(c = 0;c < cols;c++)
	       scanf("%lf",&ar[r][c]);
    }
}
double aver_row(int n, double ar[n])
{
	int i;
	double total;
	for(i = 0,total = 0;i < n;i++)
	    total += ar[i];
    
    return (total/n);
}
double aver(int rows, int cols, double ar[rows][cols])
{
	int r,c;
	double total;

    for(r = 0,total = 0;r < rows;r++)
    	for(c = 0;c < cols;c++)
    	    total += ar[r][c];
    
    return (total/(r*c));
}
double max(int rows, int cols, double ar[rows][cols])
{
	int r,c;
	double max;
	for(r = 0;r < rows;r++)
    {
    	for(c = 0,max = ar[0][0];c < cols;c++)
    	{
	    	if(ar[r][c] > max)
	    	   max = ar[r][c];
	    }
    }
    
    return max;
}
