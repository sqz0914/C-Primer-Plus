#include<stdio.h>
#define STOP 0
int main(void)
{
	int num;
	int totaleven = 0;
	int totalodd = 0;
	int sumeven = 0;
	int sumodd = 0;
	
	printf("Please enter some integer numbers(0 to qiut):\n");
	scanf("%d",&num);
	while(num != 0)
	{
	    switch(num%2)
	    {
    		case 0:
  	         totaleven++;
			 sumeven += num;
			 break;
            case 1:
             totalodd++;
			 sumodd += num;
	         break;
    	}
		scanf("%d",&num);
	}
	printf("There are %d even integers and their average value is %.1f.\n",totaleven,(float)sumeven/totaleven);
	printf("There are %d odd integers and thier average value is %.1f\n",totalodd,(float)sumodd/totalodd);
	
	return 0;
}
