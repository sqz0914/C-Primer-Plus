#include<stdio.h>
void copy_arr(int rows, int cols, double ar[rows][cols],double pt[rows][cols]);
void show(int rows ,int cols, double ar[rows][cols],double pt[rows][cols]);
int main(void)
{
	double ar[3][5] = 
	{
		{1.1,2.2,3.3,4.4,5.5},
		{6.6,7.7,8.8,9.9,10.1},
		{11.1,12.1,13.1,14.1,15.1}
	};
	double pt[3][5];
	
	copy_arr(3,5,ar,pt);
	show(3,5,ar,pt);
	
	return 0;
}
void copy_arr(int rows, int cols, double ar[rows][cols],double pt[rows][cols])
{
	int r,c;
	for(r = 0;r < rows;r++)
	    for(c = 0;c < cols;c++)
	        pt[r][c] = ar[r][c];
}
void show(int rows ,int cols, double ar[rows][cols],double pt[rows][cols])
{
	int r,c;
	printf("The original array:\n");
	for(r = 0;r < rows;r++)
    {
    	for(c = 0;c < cols;c++)
        	printf("%5.1f",ar[r][c]);
    	printf("\n");
    }
    printf("The copyed array:\n");
    for(r = 0;r < rows;r++)
    {
    	for(c = 0;c < cols;c++)
        	printf("%5.1f",pt[r][c]);
    	printf("\n");
    }
}
