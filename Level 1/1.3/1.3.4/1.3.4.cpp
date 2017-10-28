#include <stdio.h>
#include <stdlib.h>
void main()
{
	int married;
	printf("If you are single, enter 0; otherwise enter any non-zero integer as you like.\n");
	scanf("%d",&married);
	married==0?printf("You are unmarried."):printf("You are married.");
}