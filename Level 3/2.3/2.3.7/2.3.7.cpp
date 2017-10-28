#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
#ifndef POINT_H
#define POINT_H
#include "Point.h"
#endif
using namespace std;

//Test for inline functions
void main()
{
	//Get coordinates
	double x1,y1;
	cout<<"Please input x-coodinate"<<endl;
	cin>>x1;//Get x coordinate
	cout<<"Please input y-coodinate"<<endl;
	cin>>y1;//Get y coordinate
	cout<<endl;//Print a newline

	Point p1 (x1,y1);// Create a constant point
	cout<<"Use X() to get the x-coordinate: ";
	cout<<p1.X()<<endl;
	cout<<"Use Y() to get the y-coordinate: ";
	cout<<p1.Y()<<endl;

	cout<<p1.ToString()<<endl;//Access the description of p1
	cout<<endl;//Print a newline

	//Modify the coordinates
	cout<<"Please re-assign the point."<<endl;
	cout<<"Please input x-coodinate"<<endl;
	cin>>x1;//Get x coordinate
	cout<<"Please input y-coodinate"<<endl;
	cin>>y1;//Get y coordinate
	cout<<endl;//Print a newline

	//Modify the states of the point
	p1.X(x1);p1.Y(y1);

	cout<<p1.ToString()<<endl;//Access the description of p1
	cout<<endl;//Print a newline
	cout<<"End of Test."<<endl;
}