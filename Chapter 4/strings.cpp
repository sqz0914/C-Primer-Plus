#include<stdio.h>
#define STRING "Authentic imitation!"
int main(void)
{
	printf("/%s/\n",STRING);
	printf("/%24s/\n",STRING);
	printf("/%24.5s/\n",STRING);
	printf("/%-24.5s/\n",STRING);
	getchar();
	return 0;
}
