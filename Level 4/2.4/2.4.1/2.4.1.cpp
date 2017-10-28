#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
#ifndef CIRCLE_H
#define CIRCLE_H
#include "Circle.h"
#endif
using namespace std;
//This is a test file for operators
void Same(Point& p1, Point& p2);//Test for == is incorporated in this function
void main()
{
	//Initiate coordinates
	double x1,x2,y1,y2;
	cout<<"Two points will be initiated."<<endl;
	cout<<"The first point: "<<endl;
	cout<<"Please input x coordinate: ";
	cin>>x1;
	cout<<"Please input y coordinate: ";
	cin>>y1;
	cout<<"The second point: "<<endl;
	cout<<"Please input x coordinate: ";
	cin>>x2;
	cout<<"Please input y coordinate: ";
	cin>>y2;
	cout<<endl;//print a new line

	//Initiate 2 Points
	Point p1(x1,y1);
	Point p2(x2,y2);

	//See descriptions
	cout<<p1.ToString()<<" and "<<p2.ToString()<<endl;
	cout<<endl;//print a new line
	Same(p1,p2);
	cout<<endl;
	
	Point pt; double factor;
	cout<<"A new point is created for test."<<endl;
	pt=p1+p2;//test for +
	cout<<p1.ToString()<<"+"<<p2.ToString ()<<"="<<pt.ToString()<<endl;
	pt=-p1;//test for -
	cout<<"-"<<p1.ToString()<<"="<<pt.ToString()<<endl;
	cout<<endl;

	cout<<"Please input a multiplicative factor: ";
	cin>>factor;
	cout<<endl;
	pt=p1*factor;//test for *
	cout<<p1.ToString()<<"*"<<factor<<"="<<pt.ToString()<<endl;
	pt=p2;//test for =
	Same(pt,p2);
	pt*=factor;//test for *=
	cout<<pt.ToString()<<"="<<p2.ToString()<<"*="<<factor<<endl;
	cout<<endl;

	Line r(p1,p2);
	cout<<p1.ToString()<<" and "<<p2.ToString()<<endl;
	cout<<r.ToString()<<endl;
	Line l;l=r;//Test for = of Line class
	cout<<"A copy of the line is created."<<endl;
	cout<<l.ToString()<<endl;
	Circle O(p1,r);
	cout<<"A circle is created."<<endl;
	cout<<O.ToString()<<endl;
	Circle O1; O1=O;//Test for = of Circle class
	cout<<"A copy of the circle is created."<<endl;
	cout<<O1.ToString()<<endl;
	cout<<endl;

	cout<<"End of Test"<<endl;
}
void Same(Point& p1, Point& p2)
{
	//Test for ==
	if (p1==p2)
	{
		cout<<p1.ToString()<<" and "<<p2.ToString()<<" have identical coordinates."<<endl;
	}
	else
	{
		cout<<p1.ToString()<<" and "<<p2.ToString()<<" have different coordinates."<<endl;
	}
}