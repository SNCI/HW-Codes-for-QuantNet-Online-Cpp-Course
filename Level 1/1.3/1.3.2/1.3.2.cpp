#include <stdio.h>
#include <stdlib.h>
void main()
{
	float h,b;
	printf("This programme will calculate the surface of a right triangle.\nPlease enter the height.");
	scanf("%f",&h);
	printf("Please enter the base.");
	scanf("%f",&b);
	printf("The surface of the right triangle is %f.\n",0.5*h*b);
}