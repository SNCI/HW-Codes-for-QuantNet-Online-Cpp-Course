//Circle.h
#ifndef SSTREAM
#define SSTREAM
#include <sstream>
#endif
#ifndef LINE_H
#define LINE_H
#include "Line.h"
#endif
#ifndef CLUSTER_H
#define CLUSTER_H
#include "Cluster.h"
#endif
using namespace std;
using namespace Cluster;
#ifndef CLASS_CIRCLE
#define CLASS_CIRCLE
class CAD::Circle
{
private:
	Point centre;
	Line radius;
public:
	//constructors and destructor
	Circle();//default constructor
	Circle(Point& p1, Line& l1);//constructor with parameters
	Circle(const Circle& O);//copy constructor
	~Circle();//destructor

	//Selectors
	Point CentrePoint() const;
	Line Radius() const;

	//Modifiers
	void CentrePoint(Point& p);
	void Radius(Line& l);
	
	//Geometric Property Functions
	double Diameter();
	double Circumference();
	double Area();

	//Description
	std::string ToString();

	//Operator
	Circle& operator = (const Circle& O);
};
ostream& Cluster::operator << (ostream& os, CAD::Circle& O);
#endif