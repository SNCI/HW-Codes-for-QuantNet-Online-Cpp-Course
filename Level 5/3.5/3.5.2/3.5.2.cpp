#ifndef CIRCLE_H
#define CIRCLE_H
#include "Circle.h"
#endif
using namespace std;
using namespace Cluster::CAD;
//this is a test programme for using base class functionality in derived classes
void main()
{
	//declare and initialize the objects
	Point pt;
	Line r(pt,Point(1,1));
	Circle O(pt,r);

	//see descriptions
	cout<<pt.ToString()<<endl;//description for point pt
	//no ID print if Shape::ToString() is not called in Point::ToString()
	cout<<r.ToString()<<endl;//description for line r
	cout<<O.ToString()<<endl;//description for circle O
}