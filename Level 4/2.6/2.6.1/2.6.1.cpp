#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
#ifndef CLUSTER_H
#define CLUSTER_H
#include "Cluster.h"
#endif
#ifndef CIRCLE_H
#define CIRCLE_H
#include "Circle.h"
#endif
#ifndef ARRAY_H
#define ARRAY_H
#include "Array.h"
#endif

using namespace std;
using Cluster::CAD::Line;
using namespace Cluster::Containers;
namespace Circ=Cluster::CAD;

//This is a test programme for namspace
void main()
{
	//Experiment with Array and Point first
	//Get the size of the array
	int s;
	cout<<"Please assign the size of the array: "; cin>>s;
	
	Array arr1(s);//Create an array
	
	for(int i=0;i<s;i++)//Modify arr1
	{arr1[i]=Cluster::CAD::Point(i+1,0);}//modify each element with Point(full namespace)

	//See descriptions
	cout<<"Array 1:"<<endl;
	for (int i=0;i<s;i++)
	{cout<<arr1[i]<<endl;}
	cout<<endl;
	
	//Initiate coordinates to create points, then line, then circle
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

	//Create the objects
	Cluster::CAD::Point p1(x1,y1);
	Cluster::CAD::Point p2(x2,y2);
	Line r(p1,p2);
	Circ::Circle O(p1,r);

	//See descriptions
	cout<<p1<<" and "<<p2<<endl;
	cout<<r<<" with a lengh of "<<r.Length()<<endl;
	cout<<O<<", whose circumference is "<<O.Circumference()<<" and whose area is "<<O.Area()<<endl;
	cout<<endl;

	cout<<"End of Test."<<endl;
}


ostream& Cluster::operator << (ostream& os, const Cluster::CAD::Point& p)
{
		os<<"Point("<<p.x<<","<<p.y<<")";
		return os;
}
ostream& Cluster::operator << (ostream& os, const Cluster::CAD::Line& l)
{
	os<<"A line between Point("<<l.stp.x<<","<<l.stp.y<<") and Point("<<l.endp.x<<","<<l.endp.y<<").";
	return os;
}
ostream& Cluster::operator << (ostream& os, Circ::Circle& O)
{
	os<<O.ToString();
	return os;
}
