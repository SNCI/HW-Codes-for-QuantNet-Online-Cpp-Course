#include <stdio.h>
#include <stdlib.h>
#include "Defs.h"
void main()
{
	float a,b,c;
	printf("Please input a: ");
	scanf_s("%f",&a);
	printf("Please input b: ");
	scanf_s("%f",&b);
	printf("Please input c: ");
	scanf_s("%f",&c);
	printf("The maximum of a and b is: %.1f\n",MAX2(a,b));
	printf("The maximum of a,b and c is: %.1f\n",MAX3(a,b,c));
}