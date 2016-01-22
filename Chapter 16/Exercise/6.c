#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 20
#define MAX 5

typedef struct person {
	char first[LEN];
	char last[LEN];
} PERSON;

void showstruct(PERSON * pb, int n);
int comp(const void * p1, const void * p2);

int main(void)
{
	PERSON info[MAX] = {
		{"Shen", "Qizhuo"},
		{"Sun", "Yuefan"},
		{"Xia", "Lei"},
		{"Xu", "Zhiming"},
		{"Tang", "Dongjie"}
	};
	puts("The original struct:");
	showstruct(info, MAX);
	qsort(info, MAX, sizeof(struct person),comp);
	puts("The sorted struct:");
	showstruct(info, MAX);
	
	return 0;
}

void showstruct(PERSON * pb, int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("%s %s\n", pb[i].first, pb[i].last);
	}
	putchar('\n');
}

int comp(const void * p1, const void * p2)
{
	const PERSON * a1 = (const PERSON *) p1;
	const PERSON * a2 = (const PERSON *) p2;
	int res;
	
	res = strcmp(a1->first, a2->first);
	if(res != 0)
	   return res;
    else
       return strcmp(a1->last, a2->last);
}
