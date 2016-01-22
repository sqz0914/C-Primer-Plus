#include<stdio.h>
#include<string.h>
int main(void)
{
	char name[20];
	int width;
	printf("Please enter your first name:\n");
	scanf("%s",name);
	printf("\"%s\"\n",name);
	printf("\"%20s\"\n",name);
	printf("\"%-20s\"\n",name);
	width = strlen(name)+3;
	printf("\"%*s\"\n",width,name);
	getchar();
	return 0;
}
