#include <stdio.h>
#include <stdlib.h>
void main()
{
	int a,n,b;
	printf("This programme will calculate a*(2^n).\nPlease assign a: ");
	scanf("%d",&a);
	printf("Please assign n: ");
	scanf("%d",&n);
	b=a<<n;
	printf("a*(2^n)= %d\n",b);
}