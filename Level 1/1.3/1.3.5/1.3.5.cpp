#include <stdio.h>
#include <stdlib.h>
void main()
{
	int i1=10;
	int i2=10;
	int r1=1;
	int r2=1;
	printf("This is a programme showing the differrence between i-- and --i.\nIn the first place i=%d, r=%d\n",i1,r1);
	r1=--i1;
	printf("Do r=--i, we get r=%d, i=%d\n",r1,i1);
	r2=i2--;
	printf("Do r=i--, we get r=%d, i=%d\n",r2,i2);
}
