#include<stdio.h>
#include<stdlib.h>
#define S_PER_M 60
#define S_PER_H 3600
#define M_PER_K 0.62137
int main(void)
{
	double distk,distm;
	double rate;
	int min,sec;
	int time;
	double mtime;
	int mmin,msec;
	
	printf("This program converts your time for a metric race\n");
	printf("to a time for running a mile and to your average\n");
	printf("speed in miles per hour.\n");
	printf("Please enter,in kilometers,the distance run\n");
	scanf("%lf",&distk);
	printf("Next enter the time in minutes and seconds.\n");
	printf("Begin by entering the minutes.\n");
	scanf("%d",&min);
	printf("Now enter the seconds.\n");
	scanf("%d",&sec);
	time = min*S_PER_M + sec;
	distm = distk*M_PER_K;
	rate = distm/time*S_PER_H;
	mtime = (double)time/distm;
	mmin = (int)mtime/S_PER_M;
	msec = (int)mtime%S_PER_M;
	
	printf("You can run %.2f km(%.2f miles) in %d min, %d sec.\n",distk,distm,min,sec);
	printf("That pace corresponds to running a mile in %d min, %d sec.\n",mmin,msec);
	printf("Your average speed was %.2f mph.\n",rate);
	system("PAUSE");
	return 0;
}
