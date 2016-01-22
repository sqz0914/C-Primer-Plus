#include<stdio.h>
#define MAXTITL 41
#define MAXAUTL 31

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

int main(void)
{
	int score;
	struct book readlist;
	
	puts("Enter test score:");
	scanf("%d",&score);
	if(score >= 84)
	   readlist = (struct book){"Crime and Punishment",
	                            "Fyodor Dostoyevsky",
   		                        9.99
                               };
    else
       readlist = (struct book){"Mr.Bouncy's Nice Hat",
       	                        "Fred Winsome",
       	                        5.99
                               };
    printf("Your assigned reading:\n");
    printf("%s by %s: $%.2f\n",readlist.title,readlist.author,readlist.value);
    
    return 0;
}
