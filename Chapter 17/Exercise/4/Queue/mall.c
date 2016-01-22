/* mall.c -- use the Queue interface */
/* compile with queue.c */
/* suppose people will join the queue which has less people */
#include <stdio.h>
#include <stdlib.h> /* for rand() and srand() and macro RAND_MAX */
#include <time.h>   /* for time()                                */
#include <windows.h>
#include "queue.h"  /* change Item typedef                       */
#define MIN_PER_HR 60.0

bool newcustomer(double x);
Item customertime(long when);

int main(void)
{
	Queue line1, line2;
	Item temp;
	int hours;
	int perhour;
	long cycle, cyclelimit;
	long turnaways = 0;
	long customers = 0;
	long served = 0;
	long sum_line = 0;
	int wait_time_Q1 = 0;
	int wait_time_Q2 = 0;
	double min_per_cust;
	long line_wait = 0;

	InitializeQueue(&line1);
	InitializeQueue(&line2);
	srand((unsigned int)time(0));
	puts("Case Study: Sigmund Lander's Advice Booth");
	puts("Enter the number of simulation hours:");
	scanf_s("%d", &hours);
	cyclelimit = hours * MIN_PER_HR;
	puts("Enter the average number of customers per hour:");
	scanf_s("%d", &perhour);
	min_per_cust = MIN_PER_HR / perhour;

	for (cycle = 0; cycle < cyclelimit; cycle++)
	{
		if (newcustomer(min_per_cust))
		{
			if (QueueIsFull(&line1) && QueueIsFull(&line2))
				turnaways++;
			else
			{
				temp = customertime(cycle);
				if (QueueItemCount(&line1) < QueueItemCount(&line2))
					EnQueue(temp, &line1);
				else
					EnQueue(temp, &line2);
				customers++;
			}
		}
		if (wait_time_Q1 <= 0 && !QueueIsEmpty(&line1))
		{
			DeQueue(&temp, &line1);
			wait_time_Q1 = temp.processtime;
			line_wait += cycle - temp.arrive;
			served++;
		}
		if (wait_time_Q2 <= 0 && !QueueIsEmpty(&line2))
		{
			DeQueue(&temp, &line2);
			wait_time_Q2 = temp.processtime;
			line_wait += cycle - temp.arrive;
			served++;
		}
		if (wait_time_Q1 > 0)
			wait_time_Q1--;
		if (wait_time_Q2 > 0)
			wait_time_Q2--;
		sum_line += (QueueItemCount(&line1) + QueueItemCount(&line2));
	}

	if (customers > 0)
	{
		printf("customers accepted: %ld\n", customers);
		printf("customers served:   %ld\n", served);
		printf("turnaways:          %ld\n", turnaways);
		printf("average queue size: %.2f\n", (double)sum_line / cyclelimit);
		printf("average wait time:  %.2f\n", (double)line_wait / served);
	}
	else
		puts("No customers!");
	EmptyTheQueue(&line1);
	EmptyTheQueue(&line2);
	puts("Bye!");
	system("PAUSE");

	return 0;
}


bool newcustomer(double x)
{
	if (rand() * x / RAND_MAX < 1)
		return true;
	else
		return false;
}

Item customertime(long when)
{
	Item temp;
	
	temp.arrive = when;
	temp.processtime = rand() % 3 + 1;

	return temp;
}
