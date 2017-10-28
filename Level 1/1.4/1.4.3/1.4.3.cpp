#include <stdio.h>
#include <stdlib.h>
/* In this programme, a character is defined as anything besides space and LF and a word as consecutive characters.
   Consecutive puncuations (or other symbols) may be counted as words.*/
void main()
{
	char ch;
	int i=0;// counter of characters
	int j=0;// counter of words
	int k=1;// counter of newlines
	printf("Please input some contents as you like.\nCaution: Every word MUST end with a space.\n");
	ch=getchar();// Initiate ch
	while (ch!=4) // When the input character is not the shutdown code, start counting
	{
		switch (ch)
		{
			case 10:
				k++; break;
			case 32:
				j++; break;
			default:
				i++; break;

		}
		ch=getchar();// Get the next input to carry on the loop.
	}
	j>0?j=j:j=1;//at least one word is input by default.
	printf("The number of characters is: %d\nThe number of words is: %d\nThe number of lines is: %d",i,j,k);
}