//this is a programme for practicing using boost::variant
#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
#ifndef STRING
#define STRING
#include <string>
#endif
using namespace std;

#ifndef BOOST_VARIANT
#define BOOST_VARIANT
#include <boost/variant.hpp>
#endif
#ifndef CIRCLE_H
#define CIRCLE_H
#include "Circle.h"
#endif
#include "Visitor.h"
using namespace Cluster::CAD;
using boost::variant;


//typedef boost::variant for shapes
typedef variant<Point,Line,Circle> ShapeType;

//declare the function that asks input type from the user and returns a ShapeType object
ShapeType WhatToCreate();

//please run the programme for multiple times to carry out test for different shapes
void main()
{
	ShapeType mshape;
	mshape=WhatToCreate();//call the function and ask user to specify a type to return
	cout<<endl;//print a new line

	//print the variant
	cout<<"User-specified Type: "<<mshape<<"\n"<<endl;
	
	//test exception handling of boost::get<T>
	try
	{
		Line l;//create a line
		l=boost::get<Line>(mshape);//try to assign mshape to l
		cout<<l<<endl;//see result
	}
	catch(boost::bad_get& err)
	{
		cout << "Error: " << err.what() << endl;//print error message
	}
	cout<<endl;//print a new line

	//test for class Visitor
	//run the main programme several times to carry out test for each shape class
	Visitor VShape;//create a visitor object
	cout<<"Modification parameters:\nX: "<<VShape.XO()<<" Y: "<<VShape.YO()<<endl;//see parameters

	boost::apply_visitor(VShape, mshape);//modify the variant
	cout<<"After modification: "<<mshape<<endl;//see results
	cout<<endl;//print a new line
}

//function body
ShapeType WhatToCreate()
{
	ShapeType Proto;//create a variant
	int type;
	cout<<"What kind of shape to create?\nPlease input 1 for Point, 2 for Line and 3 for Circle: ";
	cin>>type;//get type from user
	switch (type)
	{
	case 1://if the user specifies a Point
		{
			Proto=Point(0);// assign a Point to variant
			break;
		}
	case 2://if the user specifies a Line
		{
			Proto=Line(Point(0),Point(1));// assign a Line to variant
			break;
		}
	case 3://if the user specifies a Circle
		{
			Proto=Circle(Point(0),Line(Point(0),Point(1)));// assign a Circle to variant
			break;
		}
	default://raw exception handling for bad input
		{
			cout<<"Wrong input! The type is assigned as point by default."<<endl;
			Proto=Point(0);
			break;
		}
	}
	return Proto;
}