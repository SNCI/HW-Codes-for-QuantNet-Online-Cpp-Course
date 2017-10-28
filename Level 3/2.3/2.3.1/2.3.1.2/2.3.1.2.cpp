#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
#ifndef POINT_H
#define POINT_H
#include "Point.h"
#endif
using namespace std;

//In this programme point is created with other constructors than the default one.
//All together, constructor is called 3 times; so is destructor.
//Copy constructor is called once.
void main()
{
	//Get coordinates
	double x1,y1;
	cout<<"Please input x-coodinate"<<endl;
	cin>>x1;//Get x coordinate
	cout<<"Please input y-coodinate"<<endl;
	cin>>y1;//Get y coordinate
	cout<<endl;//Print a newline

	Point pt (x1,y1);// Create an object of Class Point

	cout<<pt.ToString()<<endl;//Access the description of pt
	cout<<endl;//Print a newline

	//Print coordinates with Get() function
	cout<<"x coordinate of the point is "<<pt.GetX()<<endl;
	cout<<"y coordinate of the point is "<<pt.GetY()<<endl;
	cout<<endl;//Print a newline

	//Distance to Origin
	cout<<"The Distance between the point and the origin is "<<pt.DistanceOrigin()<<endl;
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
	cout<<"The Distance between the two points is "<<pt.Distance(p2)<<endl;
}