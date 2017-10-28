#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
#ifndef POINT_H
#define POINT_H
#include "Point.h"
#endif
using namespace std;

//Test for const functions and const object
//No text would be printed when constructor and destructor are called
void main()
{
	//Get coordinates
	double x1,y1;
	cout<<"Please input x-coodinate"<<endl;
	cin>>x1;//Get x coordinate
	cout<<"Please input y-coodinate"<<endl;
	cin>>y1;//Get y coordinate
	cout<<endl;//Print a newline

	const Point cp (x1,y1);// Create a constant point
	/*cp.X(x1-1);*///Try to reset x-coordinate. This gives a compiler error anyway.
	cout<<"Use X() to get the x-coordinate: ";
	cout<<cp.X()<<endl;//Try to display x-coordinate. This gives a compiler error if X() is not a const function.
	cout<<endl;//Print a newline

	cout<<cp.ToString()<<endl;//Access the description of pt
	cout<<endl;//Print a newline

	//Distance to Origin
	cout<<"The Distance between the point and the origin is "<<cp.Distance()<<endl;
	cout<<endl;//Print a newline
	
	//Distance to another point
	cout<<"Please assign another point."<<endl;
	double x2,y2;
	cout<<"Please input x-coodinate"<<endl;
	cin>>x2;//Get x coordinate
	cout<<"Please input y-coodinate"<<endl;
	cin>>y2;//Get y coordinate
	cout<<endl;//Print a newline

	//Create another point
	Point p2 (x2,y2);
	
	//Calculate the distance
	cout<<"The Distance between the two points is "<<cp.Distance(p2)<<endl;
}