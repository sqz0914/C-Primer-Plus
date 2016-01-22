#include<stdio.h>
int main(void)
{
	int age;
	float assets;
	char name[40];
	printf("Enter your age,assets,\
and favourite pet.\n");
	scanf("%d",&age);
	scanf("%f",&assets);
	scanf("%s",name);
	printf("%d $%8.2f %s",age,assets,name);
	getchar();
	return 0;
}
