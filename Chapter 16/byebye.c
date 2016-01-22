#include <stdio.h>
#include <stdlib.h>
void sign_off(void);
void too_bad(void);

int main(void)
{
	int n;
	
	atexit(sign_off);
	puts("Enter an integer:");
	if(scanf("%d", &n) != 1)
	{
		puts("That is no integer!");
		atexit(too_bad);
		exit(EXIT_FAILURE);
	}
	
	return 0;
}

void sign_off(void)
{
	puts("Thus terminates another magnificent program from");
	puts("Seesaw Software!");
}

void too_bad(void)
{
	puts("Seasaw Software extends its heartfelt condolences");
	puts("to you upon the failure of your program.");
}
