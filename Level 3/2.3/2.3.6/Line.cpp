//Line.cpp
//Simple line class with start- and end-point.
//09-18-2016 AM
#ifndef LINE_H
#define LINE_H
#include "Line.h"
#endif
#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
#ifndef CMATH
#define CMATH
#include <cmath>
#endif
//constructors and destructor
Line::Line(Point &p1, Point &p2)//constructor with start- and end-point
{
	stp.X(p1.X());
	stp.Y(p1.Y());
	endp.X(p2.X());
	endp.Y(p2.Y());
}
Line::Line(const Line& l)
{
	stp.X(l.Stp().X());
	stp.Y(l.Stp().Y());
	endp.X(l.Endp().X());
	endp.Y(l.Endp().Y());
}

//Selector
Point Line::Stp() const
{
	return stp;
}
Point Line::Endp() const
{
	return endp;
}

//Modifier
void Line::Stp(Point &nstp)
{
	stp.X(nstp.X());
	stp.Y(nstp.Y());
}
void Line::Endp(Point &nendp)
{
	endp.X(nendp.X());
	endp.Y(nendp.Y());
}

//Description
std::string Line::ToString() const
{
	std::stringstream source;
	source<<"A line between ("<<stp.X()<<","<<stp.Y()<<") and ("<<endp.X()<<","<<endp.Y()<<").";
	return source.str();
}

//Length
double Line::Length() const
{
	Point p1(stp);
	Point p2(endp);
	return p1.Distance(p2);
}