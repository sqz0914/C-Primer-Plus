#include<stdio.h>
#include<console.h>
int main(int argc, char *argv[])
{
	int count;
	
	argc = ccommand(&argv);
	printf("The command line has %d arguments:\n",argc - 1);
	for(count = 1;count < argc;count++)
	    printf("%d:%s\n",count,argv[count]);
    putchar('\n');
    
    return 0;
}
