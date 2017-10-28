#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
#ifndef CIRCLE_H
#define CIRCLE_H
#include "Circle.h"
#endif
using namespace std;
//This is a test programme for class Circle
void main()
{
	//Initiate two points to construct a circle
	double x1,y1,x2,y2;
	cout<<"Please assign two points to construct a circle."<<endl;
	cout<<"One of the points is the centre of the circle, and the line between them the radius."<<endl;
	cout<<"Please assign the centre point:"<<endl;
	cout<<"x-coordinate: "<<endl;
	cin>>x1;
	cout<<"y-coodinate: "<<endl;
	cin>>y1;
	cout<<"Please assign the other point:"<<endl;
	cout<<"x-coordinate: "<<endl;
	cin>>x2;
	cout<<"y-coodinate: "<<endl;
	cin>>y2;
	cout<<endl;//print a newline
	
	//constructing the circle
	Point cent(x1,y1); Point circ(x2,y2);
	Line r(cent,circ);
	Circle O(cent,r);

	//Test description function
	cout<<O.ToString()<<endl;
	cout<<endl;//print a newline

	//Test Selectors
	cout<<"The centre of the circle is "<<O.CentrePoint().ToString()<<endl;
	cout<<"The radius of the circle is "<<O.Radius().ToString()<<endl;
	cout<<endl;//print a newline

	//Test Modifiers
	cout<<"Please assign another point."<<endl;
	cout<<"This newly-assigned point would become the centre of a new circle."<<endl;
	cout<<"The previous centre would be a point on the circumferences of the new circle."<<endl;
	cout<<"x-coordinate: "<<endl;
	cin>>x2;
	cout<<"y-coodinate: "<<endl;
	cin>>y2;
	cout<<endl;//print a newline
	
	//Modify the parameters
	circ.X(x2);circ.Y(y2);
	r.Stp(circ);r.Endp(cent);
	O.CentrePoint(circ);O.Radius(r);

	//See description
	cout<<O.ToString()<<endl;
	cout<<endl;//print a newline

	//Calculate d, C & A
	cout<<"The diameter of the new circle is: "<<O.Diameter()<<endl;
	cout<<"The circumference of the new circle is: "<<O.Circumference()<<endl;
	cout<<"The area of the new circle is: "<<O.Area()<<endl;
	cout<<endl;//print a newline
	cout<<"End of Test"<<endl;
}