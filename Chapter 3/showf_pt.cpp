#include<stdio.h>
int main(void)
{
	float aboat = 32000.;
	double abet = 2.14e9;
	long double dip = 0x5.32p-5;
	
	printf("%f can be written %e\n",aboat,aboat);
	printf("%f can be written %e\n",abet,abet);
	printf("%Lf can be written %Le\n",dip,dip);
	getchar();
	return 0;
}
