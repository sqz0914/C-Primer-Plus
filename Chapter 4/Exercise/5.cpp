#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void)
{
	char name1[20],name2[20];
	int width1,width2;
	printf("Please enter\n");
	printf("Your first name:");
	scanf("%s",name1);
	printf("Your last name:");
	scanf("%s",name2);
	printf("%s %s\n",name1,name2);
	width1 = strlen(name1);
	width2 = strlen(name2);
	printf("%*d %*d\n",width1,width1,width2,width2);
	printf("%-*d %-*d\n",width1,width1,width2,width2);
	system("PAUSE");
	return 0;
}
