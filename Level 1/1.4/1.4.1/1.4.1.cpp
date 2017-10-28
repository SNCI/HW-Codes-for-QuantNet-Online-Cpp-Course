#include <stdio.h>
#include <stdlib.h>
/* In this programme and the following 1.4.2, a character is defined as anything besides space and LF 
   and a word as consecutive characters.
   However consecutive puncuations (or other symbols) would not be counted as words.*/
void main()
{
	char ch;
	int i=0;// counter of characters
	int j=0;// counter of words
	int k=1;// counter of newlines
	printf("Please input some contents as you like.\nCaution: Every word should end with a space, '.', ';', '!' or '?'\n");
	ch=getchar();// Initiate ch
	while (ch!=4) // When the input character is not the shutdown code, start counting
	{
		if (ch!=32 && ch!=10) // The input is counted as a character when it is not a space or a new line
			i++;
		if (ch==10)// Number of new lines is increased whenever an LF is typed in
			k++;
		
		/*The following block prevent consecutive symbols from being counted as words*/
		if (ch==32 || ch==33 || ch==44 || ch==46 || ch==59 ||ch==63) // When an end-of-sentence punctuation or a space is typed in, check for following cases.
		{
			j++; // Since it's the first time in the string an end-of-sentence punctuation/space is typed in,  this marks a new word by default
			ch=getchar();// Get the next input.
			while (ch<64 || (ch>91 && ch<96) || ch>123) // The next input is not something from "A-Z" or "a-z"
			{
				if (ch==4)// Case 1: end of text.
				break;
				if (ch!=32 && ch!=10)// Case 2: a common symbol which should be counted as a character
					i++;
				if (ch==10)// Case 3: a new line
					k++;
				ch=getchar();//Get the next input to carry on the loop to check for consecutive punctuations
				
			}
			continue; // start a new loop without re-assign a value to ch
		}
		
		if (ch==4)// the value of ch might have been changed
				break;
		ch=getchar();// Get the next input to carry on the loop.
	}
	j>0?j=j:j=1;// at least one word is input by default.
	printf("The number of characters is: %d\nThe number of words is: %d\nThe number of lines is: %d",i,j,k);
}