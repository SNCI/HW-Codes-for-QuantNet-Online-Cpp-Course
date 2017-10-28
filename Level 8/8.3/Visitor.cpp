//Visitor.cpp
//a variant visitor class that moves the shapes
//11-03-2016 AM
#ifndef VISITOR_H
#define VISITOR_H
#include "Visitor.h"
#endif
namespace Cluster
{
	namespace CAD
	{
		//constructors and distructor
		Visitor::Visitor():boost::static_visitor<void>(),x_offset(0.5),y_offset(0.5){}//default constructor
		Visitor::Visitor(double x, double y):boost::static_visitor<void>(),x_offset(x),y_offset(y){}//constructor with parameters
		Visitor::Visitor(const Visitor& source):boost::static_visitor<void>(source),x_offset(source.x_offset),y_offset(source.y_offset){}//copy constructor
		Visitor::~Visitor(){}//destructor

		//getters
		double Visitor::XO()//get x_offset
		{
			return x_offset;
		}
		double Visitor::YO()//get y_offset
		{
			return y_offset;
		}

		//modifiers
		void Visitor::XO(double x)//modify x_offset
		{
			x_offset=x;
		}
		void Visitor::YO(double y)//modify y_offset
		{
			y_offset=y;
		}

		//operators
		Visitor& Visitor::operator = (const Visitor& source)//assignment operator
		{
			if (this!=&source)//handle self-assignment
			{
				//call base class assignment operator
				boost::static_visitor<void>::operator = (source);

				//assign corresponding data members
				x_offset=source.x_offset;
				y_offset=source.y_offset;
			}
			return *this;
		}
		void Visitor::operator () (Point& p) const//() for Point
		{
			p.X(p.X()+x_offset);//call class Point modifier and selector for x coordinate
			p.Y(p.Y()+y_offset);//call class Point modifier and selector for y coordinate
		}
		void Visitor::operator () (Line& l) const//() for Line
		{
			l.Stp(l.Stp()+Point(x_offset,y_offset));//call start-point modifier of class Line and operator + of class Point
			l.Endp(l.Endp()+Point(x_offset,y_offset));//call end-point modifier of class Line and operator + of class Point
		}
		void Visitor::operator () (Circle& O) const//() for Circle
		{
			//call centre point modifier of class Circle and operator + of class Point
			O.CentrePoint(O.CentrePoint()+Point(x_offset,y_offset));
		}
	}
}