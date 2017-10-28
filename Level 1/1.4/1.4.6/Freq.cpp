#include <stdio.h>
#include <stdlib.h>
void main()
{
	int num;
	int i0=0; int i1=0; int i2=0; int i3=0; int i4=0;// counters for 0-4
	int j=0;// counter for other characters
	printf("Please input integers from 0-4.\n");
	printf("Caution:'^Z' is regarded as EOF only when input immediately after an LF.\n");
	num=getchar();
	while (num!=EOF)
	{
		switch (num)
		{
		case 48:
			i0++; break;
		case 49:
			i1++; break;
		case 50:
			i2++; break;
		case 51:
			i3++; break;
		case 52:
			i4++; break;
		default:
			j++; break;
		}
		num=getchar();
	}
	printf("Number 0 appears %d times.\n",i0);
	printf("Number 1 appears %d times.\n",i1);
	printf("Number 2 appears %d times.\n",i2);
	printf("Number 3 appears %d times.\n",i3);
	printf("Number 4 appears %d times.\n",i4);
	printf("Other characters appear %d times.\n",j);

}