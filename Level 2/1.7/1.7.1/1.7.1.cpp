#include <stdio.h>
#include <stdlib.h>
float Swap (float* pfa, float* pfb);
float Swap (float* pfa, float* pfb)
{
	float mid=(*pfa);//Initialise a middle variable to store the value of either argument
	(*pfa)=(*pfb);
	(*pfb)=mid;
	return (*pfa),(*pfb);
}
void main()
{
	float a,b;
	printf("Please input a: "); scanf_s("%f",&a);//Get the value of a
	printf("Please input b: "); scanf_s("%f",&b);//Get the value of b
	printf("In the first place a=%.1f, b=%.1f.\n",a,b);
	Swap(&a,&b);
	printf("After a swap, a=%.1f, b=%.1f.\n",a,b);
}