#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
#ifndef POINT_H
#define POINT_H
#include "Point.h"
#endif
using namespace std;

//This is a programme for arrays of pointers
void main()
{
	Point** arr_p=new Point*[3];//create an array of pointers
	
	for(int i=0;i<3;i++)//initialize each pointer in the array
	{
		double x1,y1;
		cout<<"Please assign an x-coordinate for point "<<i+1<<": "; cin>>x1;
		cout<<"Please assign an y-coordinate for point "<<i+1<<": "; cin>>y1;
		arr_p[i]=new Point(x1,y1);
	}
	
	cout<<endl;//print a new line
	cout<<"The points in the array are as follows:"<<endl;
	for(int i=0;i<3;i++)//print each point in the array
	{
		cout<<*arr_p[i]<<endl;
	}

	for(int i=0;i<3;i++)//free the memories allocated to each point
	{
		delete arr_p[i];
		arr_p[i]=NULL;
	}

	delete [] arr_p;//free the memory allocated to array of pointers
	arr_p=NULL;
	cout<<endl;
	cout<<"End of Test"<<endl;
}
ostream& operator << (ostream& os, const Point& p)
{
	os<<"Point("<<p.x<<","<<p.y<<")";
	return os;
}