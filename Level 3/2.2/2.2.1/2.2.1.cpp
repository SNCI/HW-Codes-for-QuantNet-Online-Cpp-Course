#include <iostream>
#ifndef POINT_H
#define POINT_H
#include "Point.h"
#endif
using namespace std;
void main()
{
	//Get coordinates
	double x;double y;
	cout<<"Please input x-coodinate"<<endl;
	cin>>x;//Get x coordinate
	cout<<"Please input y-coodinate"<<endl;
	cin>>y;//Get y coordinate

	Point pt;// Create an object of Class Point

	pt.SetX(x);//Set x coordinate
	pt.SetY(y);//Set y coordinate

	cout<<pt.ToString()<<endl;//Access the description of pt

	//Print coordinates with Get() function
	cout<<"x coordinate of the point is "<<pt.GetX()<<endl;
	cout<<"y coordinate of the point is "<<pt.GetY()<<endl;
}