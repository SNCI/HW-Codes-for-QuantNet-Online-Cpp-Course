#include <stdio.h>
#include <stdlib.h>
void main()
{
	double Cel;
	double Fah=0;
	printf("This programme will provide a list of temperatures in Fahrenheit and Celsius respectively.\n");
	printf("    T in F\tT in C\n");
	while (Fah<301)
	{	
		Cel=(Fah-32)*5/9;
		printf("%10.1f,%10.1f\n",Fah,Cel);
		Fah+=20;
	}
}
