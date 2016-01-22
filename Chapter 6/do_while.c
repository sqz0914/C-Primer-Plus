#include<stdio.h>
int main(void)
{
	const int secret_code = 13;
	int code_enter;
	
	do
	{
		printf("To enter the triskaidekaphobia therapy club,\n");
		printf("please enter the secret code number:");
		scanf("%d",&code_enter);
	}
	while(code_enter != secret_code);
	printf("Congratulations! You are cured!\n");
	
	return 0;
}
