#include <stdio.h>
#include <stdbool.h>

int bstoi(char * str);
bool checkval(char * str);

int main(void)
{
	char input[8 * sizeof(int) + 1];
	puts("Enter the string you want to convert:");
	while(gets(input) != NULL && input[0] != '\0')
	{
		if(!checkval(input))
            puts("Binary forms only contains '0' and '1'.");
        else
            printf("The value is %d.\n", bstoi(input));
        puts("Next value.");
	}
	puts("Bye!");
	
	return 0;
}

int bstoi(char * str)
{
	int value = 0;
	while( *str )
	     value = 2 * value + (*str++ - '0');
 
    return value;
}

bool checkval(char * str)
{
	bool valid = true;
	while( *str && valid )
	{
		if( *str != '1' && *str != '0')
		  valid = false;
        str++;
	}
	
	return valid;
}
