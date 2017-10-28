#include <stdio.h>
#include <stdlib.h>
void main()
{
	int c;
	printf("This programme will print whatever content input before key ENTER is pressed.\nExit the programme by pressing CTRL+D.\n");
	c=getchar();//Initialise c
	while (c!= 4)//4 represents ^D. When entering ^A, everything on the screen is highlighted and results in an endless loop.
	{
		putchar(c);
		c=getchar();//Get next c to carry on the loop
	}
	if (c==4)
	{
		printf("CTRL + D is a correct ending.\n");
	}
}