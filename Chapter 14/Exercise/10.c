#include<stdio.h>
#include<math.h>
#define NUM 4

double twice(double x);
double half(double x);
double thrice(double x);
void showmenu(void);

int main(void)
{
	double (*pt[NUM])(double ) = {twice, half, thrice, sqrt};
	double val;
	double ans;
	int sel;
	
	puts("Please enter the number you want to handle (negative value to quit):");
	while(scanf("%lf",&val) == 1 && val > 0)
	{
		showmenu();
		while(scanf("%d",&sel) == 1 && sel >= 0 && sel < 4)
		{
			ans = (*pt[sel])(val);
			printf("Answer is %g\n",ans);
			showmenu();
		}
		puts("Next number (negative value to qiut):");
	}
	puts("Bye!");
	
	return 0;
}

void showmenu(void)
{
    puts("Enter one of the following choices:");
    puts("0) double the value        1) halve the value");
    puts("2) triple the value        3) squareroot the value");
    puts("4) next number");
}

double twice(double x) {return 2.0 * x;}

double half(double x) {return x / 2.0;}

double thrice(double x) {return 3.0 * x;}

