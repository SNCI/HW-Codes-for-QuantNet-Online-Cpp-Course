//Point.cpp
//Simple two-dimentional point with x and y coordinates
//09-15-2016 PM
#ifndef POINT_H
#define POINT_H
#include "Point.h"
#endif
#include <cmath>

//Selectors
double Point::GetX()//Access x value
{
	return m_x;
}
double Point::GetY()//Access y value
{
	return m_y;
}

//Modifiers
void Point::SetX(double newxval)//Initiate m_x
{
	m_x=newxval;
}
void Point::SetY(double newyval)//Initiate m_y
{
	m_y=newyval;
}

//Description
std::string Point::ToString()
{
	std::stringstream m_string;
	m_string<<"Point("<<m_x<<","<<m_y<<")";
	return m_string.str();
}

//Distance functions
double Point::DistanceOrigin()
{
	return sqrt(m_x*m_x+m_y*m_y);//Distance to Origin=SquareRoot(x^2+y^2)
}
double Point::Distance(Point p)
{
	double a,b;
	a=m_x-p.GetX();//Calculate the difference in x coordinates
	b=m_y-p.GetY();//Calculate the difference in y coordinates
	return sqrt(a*a+b*b);
}