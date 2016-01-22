#include <stdio.h>
#include "hotel.h"
int main(void)
{
	int nights;
	double hotelrate;
	int code;
	
	while((code = menu()) != QIUT)
	{
		switch(code)
		{
			case 1:hotelrate = HOTEL1;
			       break;
            case 2:hotelrate = HOTEL2;
                   break;
            case 3:hotelrate = HOTEL3;
                   break;
            case 4:hotelrate = HOTEL4;
                   break;
            default:hotelrate = 0.0;
                    printf("Oops!\n");
                    break;
		}
		nights = getnights();
		showprice(hotelrate, nights);
	}
	printf("Thank you and goodbye!\n");
	
	return 0;
}
