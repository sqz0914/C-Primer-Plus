#include<stdio.h>
#define SIZE 12
int main(void)
{
	int days[SIZE] = {31,28,[4] = 31,30,31,[1] = 29};
	int index;
	
	for(index = 0;index < SIZE;index++)
	   printf("%2d %d\n",index + 1,days[index]);
	   
    return 0;
}
