#include<stdio.h>
int main(void)
{
	printf("Type int has a size of %u bytes.\n",sizeof(int));
	printf("Type char has a size of %u bytes.\n",sizeof(char));
	printf("Type long has a size of %u bytes.\n",sizeof(long));
	printf("Type double has a size of %u bytes.\n",sizeof(double));
	printf("Type long double has a size of %u bytes.\n",sizeof(long double));
	printf("Type float has a size of %u bytes.\n",sizeof(float));
	getchar();
	return 0;
}
