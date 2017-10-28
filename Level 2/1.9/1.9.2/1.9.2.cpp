#include <stdio.h>
#include <stdlib.h>
void main()
{
	int c;
	printf("This programme will print whatever content input before key ENTER is pressed\nto a file assigned by the user.\nExit the programme by pressing CTRL+D.\n");
	FILE* fp;
	fp=fopen("Filename.txt","w");//You can specify a filename here.
	while ((c=getchar())!= 4)//4 represents ^D. When entering ^A, everything on the screen is highlighted and results in an endless loop.
	{
		fputc(c,fp);//Output the contents to the pre-specified file.
	}
	if (c==4)
	{
		printf("CTRL + D is a correct ending.\n");
	}
	printf("Check the file under project folder.\n");
	fclose(fp);
}