#ifndef LINE_H
#define LINE_H
#include "Line.h"
#endif
#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
//This is a test programme for calss Line
using namespace std;
void main()
{
	//Initiate a line
	double x1,y1,x2,y2;
	cout<<"Please assign a start point."<<endl;
	cout<<"x-coordinate: ";
	cin>>x1;
	cout<<"y-coordinate: ";
	cin>>y1;
	cout<<"Please assigh an end point."<<endl;
	cout<<"x-coordinate: ";
	cin>>x2;
	cout<<"y-coordinate: ";
	cin>>y2;
	Point stp(x1,y1);//Initiate the start point
	Point endp(x2,y2);//Initiate the end point
	Line l(stp, endp);//Create a line
	Line l2;//Test the default constructor
	cout<<endl;//print a new line

	//Test for selector functions
	cout<<"Default Start Point: "<<l2.Stp().ToString()<<endl;
	cout<<"Default End Point: "<<l2.Endp().ToString()<<endl;
	cout<<endl;//print a new line

	//Access description
	cout<<l.ToString()<<endl;
	cout<<endl;//print a new line

	//Test for copy constructor
	Line l3(l);
	cout<<"A copy of the line is created."<<endl;
	cout<<l3.ToString()<<endl;
	cout<<endl;//print a new line

	//Test for modifier functions
	cout<<"Please re-assign a start point."<<endl;
	cout<<"x-coordinate: ";
	cin>>x1;
	cout<<"y-coordinate: ";
	cin>>y1;
	cout<<"Please re-assigh an end point."<<endl;
	cout<<"x-coordinate: ";
	cin>>x2;
	cout<<"y-coordinate: ";
	cin>>y2;
	stp.X(x1);stp.Y(y1);
	endp.X(x2);endp.Y(y2);
	l.Stp(stp);l.Endp(endp);

	//Access description
	cout<<l.ToString()<<endl;
	cout<<endl;//print a new line

	//Calculate the Length of l
	cout<<"The length of l is: "<<l.Length()<<endl;
}