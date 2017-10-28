#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void DayName(int day);
void main()
{
	int day;
	printf("This programme will print the day of a given day number.\n");
	printf("Please input a day number: "); scanf_s("%d",&day);
	DayName(day);
	printf("\n");
}
void DayName(int day)
{
	int i=0;
	char Day[7][10]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};//Initialise the 2-dimentinal array
	printf("Day %d is ",day);
	for(i=0;i<10;i++)// Output DayName character by character.
	{
		printf("%c",Day[day-1][i]);
	}
}