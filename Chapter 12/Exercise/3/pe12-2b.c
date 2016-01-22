#include <stdio.h>
#include "pe12-2a.h"
int main(void)
{
	int mode;
	double distance,fuel;
	distance = fuel = 0;
	
	printf("Enter 0 to metric mode, 1 for US mode:");
	scanf("%d",&mode);
	while(mode >= 0)
	{
		set_mode(&mode);
		get_info(mode, &distance, &fuel);
		show_info(mode,distance,fuel);
		printf("Enter 0 to metric mode, 1 for US mode:");
		printf(" (-1 to qiut): ");
		scanf("%d",&mode);
	}
	puts("Done!");
	
	return 0;
}
