#include <stdio.h>
void print(float)
{
	extern float i;
	printf("2i = %.1f\n",2*i);
}