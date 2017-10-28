#include <stdio.h>
#include <stdlib.h>
void main()
{
	int a,b,c;
	printf("Please input an integer: ");
	scanf("%d",&a);
	b=a>>1; c=b>>1;
	printf("a>>1 evaluates to: %d,\na>>2 evaluates to: %d.\n",b,c);
	if (b<0)
	{
		printf("A 1 is inserted to the left at the second digit from the left.\n");
	}
	else
	{
		printf("A 0 is inserted to the left at the second digit from the left.\n");
	}
	if (c<0)
	{
		printf("\nA 1 is inserted to the left at the first digit from the left.\n");
	}
	else
	{
		printf("A 0 is inserted to the left at the first digit from the left.\n");
	}
}
