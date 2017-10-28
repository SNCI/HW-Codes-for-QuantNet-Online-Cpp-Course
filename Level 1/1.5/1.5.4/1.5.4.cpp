#include <stdio.h>
#include <stdlib.h>
long double printnumber(long double a)
{
	if (a<0)// handle negative numbers
	{
		a=-a;
		putchar(45);
	}
	long double num;//used in recursion
	int d;//used to calculate moduli(digits)
	if (a>10)// then consequtively divide a by 10 until getting the first number from the left
	{
		num=printnumber(a/10);
		d=(int)num;//discard the decimal part
		d=d%10;
		d+=48;//convert into ASCII value
		putchar(d);
		return (10*num);//so that the next modulus would be the same as the next digit from the left
	}
	else// when reaching the first digit from the left
	{
		d=a;//discard the decimal part
		d=d%10;
		d+=48;//convert into ASCII value
		putchar(d);
		return (10*a);//so that the next modulus would be the same as the second digit from the left
	}
}
/*This programme can only handle integers with less than or equal to 8 digits.
  This is possibly because of the limit in precision of certain data types.
  In the main function, if a value is directly assigned to variable a without a "scanf_s" function,
   the programme would be able to handle 9-digit integers.*/
void main()
{
	float a;
	printf("Please input an integer with less than or equal to 8 digits: ");
	scanf_s("%f",&a);
	printnumber(a);
}