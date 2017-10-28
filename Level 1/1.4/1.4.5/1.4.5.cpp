#include <stdio.h>
#include <stdlib.h>
void main()
{
	double Cel;
	double Fah;
	printf("This programme will provide a list of temperatures in Fahrenheit and Celsius respectively.\n");
	printf("    T in C\tT in F\n");
	for(Cel=0;Cel<=19;Cel++)
	{
		Fah=9*Cel/5+32;
		printf("%10.1f,%10.1f\n",Cel,Fah);
	}
}