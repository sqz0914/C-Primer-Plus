#include<stdio.h>
int main(void)
{
	char name[20];
	float height,height1;
	printf("Please enter\n");
	printf("Your name:");
	scanf("%s",name);
	printf("Your height in inches:");
	scanf("%f",&height);
	printf("Your height in centimeters:");
	scanf("%f",&height1);
    printf("%s,you are %.3f\
 feet tall.\n",name,height);
    printf("And you are %.2f meters tall.\n",height1/100);
    getchar();
    return 0;
}
