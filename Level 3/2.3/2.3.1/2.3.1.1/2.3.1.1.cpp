#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
#ifndef POINT_H
#define POINT_H
#include "Point.h"
#endif
using namespace std;

//This is the programme for the experiment(Constructors and Destructors with text printed on screen)
//In this experiment the constructor is called 2 times while the destructor is called 3 times,
//which are not the same.
void main()
{
	//Get coordinates
	double x1,y1;
	cout<<"Please input x-coodinate"<<endl;
	cin>>x1;//Get x coordinate
	cout<<"Please input y-coodinate"<<endl;
	cin>>y1;//Get y coordinate
	cout<<endl;//Print a newline

	Point pt;// Create an object of Class Point

	pt.SetX(x1);//Set x coordinate
	pt.SetY(y1);//Set y coordinate

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
	Point p2;
	p2.SetX(x2);p2.SetY(y2);
	
	//Calculate the distance
	cout<<"The Distance between the two points is "<<pt.Distance(p2)<<endl;
	cout<<endl;//Print a newline
}