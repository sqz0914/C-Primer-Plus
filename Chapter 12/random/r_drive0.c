#include<stdio.h>
extern int rand0(void);

int main(void)
{
	int i;
	for(i = 0;i < 5;i++)
	    printf("%hd\n",rand0());
    
    return 0;
}
