#include <stdio.h>
#include <stdlib.h>
#ifndef DEFS_H//To avoid multiple inclusion
#define DEFS_H
#include "Defs.h"
#endif
void main()
{
	float a,b;
	printf("Please input a: \n");
	scanf_s("%f",&a);
	printf("Please input b: \n");
	scanf_s("%f",&b);
	PRINT1(a);
	PRINT2(a,b);
}