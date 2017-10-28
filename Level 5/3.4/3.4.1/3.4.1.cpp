#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
#ifndef CIRCLE_H
#define CIRCLE_H
#include "Circle.h"
#endif
using namespace std;
using namespace Cluster::CAD;
//this is a test programme for colon syntax
void main()
{
	Line l;
	//Without colon syntax, Point default constructor and destructor are called twice respectively.
	//The assignment operator is not called in this case.

	//With colon syntax in class Line, Point default constructor and destructor are called twice respectively.
	//Constructor and destructor are called the same times as in the previous case.
	//Assignment operator of class Point is not called in this case.

	//With colon syntax also used in class Point and class Circle, the situation is exactly the same as the previous case.
}