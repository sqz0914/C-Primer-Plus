#include<stdio.h>
#include<ctype.h>
char get_choice(void);
float get_number(void);
float add(float a,float b);
float sub(float a,float b);
float mul(float a,float b);
float div(float a,float b);
int main(void)
{
	char ch;
	float num1;
	float num2;
	float result;
	
	while((ch = get_choice()) != 'q')
	{
		if(ch != 'a' && ch != 's' && ch != 'm' && ch != 'd')
		{
			printf("Input error!\n");
			continue;
		}
		printf("Enter first number:");
		num1 = get_number();
		printf("Enter second number:");
		num2 = get_number();
		switch(ch)
		{
			case 'a':result = add(num1,num2);
		             printf("%g + %g = %g\n",num1,num2,result);
		             break;
            case 's':result = sub(num1,num2);
                     printf("%g - %g = %g\n",num1,num2,result);
                     break;
            case 'm':result = mul(num1,num2);
                     printf("%g * %g = %g\n",num1,num2,result);
                     break;
            case 'd':result = div(num1,num2);
                     printf("%g / %g = %g\n",num1,num2,result);
                     break;
		}
	}
	printf("Bye!\n");
	
	return 0;
}

char get_choice(void)
{
	char ch;
	
	printf("Enter the operation of your choice:\n");
	printf("a. add             s. substract\n");
	printf("m. multiply        d. divide\n");
	printf("q. qiut\n");
	while(isspace(ch = getchar()))
	      continue;
    while(getchar() != '\n')
          continue;
    
    return ch;
}

float get_number(void)
{
	float input;
	char ch[225];
	while(scanf("%f",&input) != 1)
    {
    	scanf("%s",ch);
    	printf("%s is not an number.\n",ch);
    	printf("Please enter a number, such as 2.5, -1.78E8, or 3:");
    }
    while(getchar() != '\n')
          continue;
    
    return input;
}

float add(float a,float b)
{
	float result;
	result = a + b;
	
	return result;
}

float sub(float a,float b)
{
	float result;
	if(b == 0)
	{
		printf("Enter a number other than 0:");
		b = get_number();
	}
	result = a - b;
	
	return result;
}

float mul(float a,float b)
{
	float result;
	result = a * b;
	
	return result;
}

float div(float a,float b)
{
	float result;
	if(b == 0)
	{
		printf("Enter a number other than 0:");
		b = get_number();
	}
	result = a / b;
	
	return result;
}
