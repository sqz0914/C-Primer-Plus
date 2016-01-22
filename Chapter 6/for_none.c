#include<stdio.h>
int main(void)
{
	int n,ans;
	
	ans = 2;
	for(n = 3;ans <= 25;)
	   ans = ans*n;
    printf("n = %d; ans = %d\n",n,ans);
    return 0;
}
