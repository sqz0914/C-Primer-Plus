#include<stdio.h>
void copy_arr(double (* ar)[12], double (* pt)[12], int rows);
void copy_ptr(double *ar, double *pt,int cols);
int main(void)
{
	int r,c;
	double rain[5][12] = 
	{
		{4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
	    {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
	    {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
	    {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
	    {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
	};
	double copy[5][12];
	copy_arr(rain, copy, 5);
	printf("The copy array is:\n");
	for(r = 0;r < 5;r++)
    {
    	for(c = 0;c < 12;c++)
    	    printf("%6.1f",copy[r][c]);
        printf("\n");
    }
	return 0;
}
void copy_arr(double (* ar)[12], double (* pt)[12], int rows)
{
	int r;
	for(r = 0;r < rows;r++)
        copy_ptr(ar[r],pt[r],12);
}
void copy_ptr(double * ar, double * pt, int cols)
{
	int c;
	for(c = 0;c < cols;c++)
	   pt[c] = ar[c];
}
