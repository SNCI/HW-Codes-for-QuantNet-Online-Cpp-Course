#include <stdio.h>
#include <stdlib.h>
float i;
void print(float);
void main()
{
	printf("Please assign a value to i: ");
	scanf("%f",&i);
	print(i);
}