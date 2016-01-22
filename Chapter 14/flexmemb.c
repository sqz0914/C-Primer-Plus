#include<stdio.h>
#include<stdlib.h>

struct flex {
	int count;
	double average;
	double scores[];
};

void showflex(const struct flex * p);

int main(void)
{
	int i;
	int n = 5;
	double total = 0;
	struct flex * pf1, *pf2;
	
	pf1 = malloc(sizeof(struct flex) + n * sizeof(double));
	pf1->count = n;
	for(i = 0;i < n;i++)
	{
		pf1->scores[i] = 20.0 - i;
		total += pf1->scores[i];
	}
	pf1->average = total / n;
	showflex(pf1);
	
	n = 9;
	total = 0;
	pf2 = malloc(sizeof(struct flex) + n * sizeof(double));
	pf2->count = n;
	for(i = 0;i < n;i++)
	{
		pf2->scores[i] = 20.0 - i / 2.0;
		total += pf2->scores[i];
	}
	pf2->average = total / n;
	showflex(pf2);
    free(pf1);
    free(pf2);
    
    return 0;
}

void showflex(const struct flex * p)
{
	int i;
	puts("Scores:");
	for(i = 0;i < p->count;i++)
	   printf("%g ",p->scores[i]);
    printf("\nAverage: %g\n",p->average);
}
