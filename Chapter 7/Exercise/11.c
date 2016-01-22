#include<stdio.h>
#define A_PER 1.25
#define B_PER 0.65
#define C_PER 0.89
#define DISCOUNT 0.05
#define D_LIMIT 100.0
#define LIMIT1 5.0
#define LIMIT2 20.0
#define FEE1 3.50
#define FEE2 10.00
#define FEE3 8.00
#define RATE 0.10
int main(void)
{
	double pound,a_pound,b_pound,c_pound,all_pound;
	double buycost;
	double shipcost;
	double allpay;
	char ch = 0;
	printf("Please order:\n");
	printf("a) artichokes\n");
	printf("b) beets\n");
	printf("c) carrots\n");
	printf("q to qiut.\n");
    while((ch = getchar()) != 'q')
    {
    	switch(ch)
    	{
	    	case 'a': printf("How many pounds of artichokes do you want?");
                      scanf("%lf",&a_pound);
                      printf("Please select your vegetable: a,b,c,q:");
                      break;
            case 'b': printf("How many pounds of beets do you want?");
                      scanf("%lf",&b_pound);
                      printf("Please select your vegetable: a,b,c,q:");
                      break;
            case 'c': printf("How many pounds of carrots do you want?");
                      scanf("%lf",&c_pound);
                      printf("Please select your vegetable: a,b,c,q:");
                      break;
            default:  break;
	    }
    }
    all_pound = a_pound + b_pound + c_pound;
    buycost = a_pound*A_PER + b_pound*B_PER + c_pound*C_PER;
    if(buycost >= D_LIMIT)
    {
    	printf("discount = %f\n",buycost*DISCOUNT);
    	buycost *=(1-DISCOUNT);
    }
    if(all_pound <= LIMIT1)
       shipcost = FEE1;
    else if(all_pound > LIMIT1 && all_pound < LIMIT2)
       shipcost = FEE2;
    else
       shipcost = FEE3 + RATE*all_pound;
    allpay = shipcost + buycost;
    printf("the cost per pound:%.3g\n",allpay/all_pound);
    printf("the pounds ordered:%.3g\n",all_pound);
    printf("the cost for artichokes:%.3g\n",a_pound*A_PER);
    printf("the cost for beets:%.3g\n",b_pound*B_PER);
    printf("the cost for carrots:%.3g\n",c_pound*C_PER);
    printf("the total cost for the order:%.3g\n",buycost);
    printf("the shipping charge:%.3g\n",shipcost);
    printf("the grand total of all the charges:%.3g\n",allpay);
    return 0;	
}
