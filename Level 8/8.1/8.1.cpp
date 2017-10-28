//This is a test programme for smart pointer in boost lib.
#include <iostream>
#include "Circle.h"
#include "Array.h"
#include <boost/shared_ptr.hpp>

using namespace std;
using namespace Cluster::CAD;
using namespace Cluster::Containers;

// Typedef for a shared pointer to shape and
// a typedef for an array with shapes stored as shared pointers.
typedef boost::shared_ptr<Shape> ShapePtr;
typedef Array<ShapePtr> ShapeArray;

void main()
{


	//declare and initialize shared pointers
	ShapePtr mpoint(new Point(1));
	ShapePtr mline(new Line(Point(1),Point(2)));
	ShapePtr mcircle(new Circle(Point(0),Line(Point(0),Point(1))));

	{//create a new scope

		//create an array of shared pointers for shapes
		ShapeArray arr_shape(6);

		//fill the array
		arr_shape[0]=mpoint;
		cout << "Point Reference Count: " << mpoint.use_count() << endl;
		arr_shape[1]=mline;
		cout << "Line Reference Count: " << mline.use_count() << endl;
		arr_shape[2]=mpoint;
		cout << "Point Reference Count: " << mpoint.use_count() << endl;
		arr_shape[3]=mcircle;
		cout << "Circle Reference Count: " << mcircle.use_count() << endl;
		arr_shape[4]=mline;
		cout << "Line Reference Count: " << mline.use_count() << endl;
		arr_shape[5]=mcircle;
		cout << "Circle Reference Count: " << mcircle.use_count() << endl;
		cout<<endl;//print a new line

		//print the array
		for(int i=0;i!=6;++i)
		{
			(*arr_shape[i]).Print();
		}
	}//end of the scope
	cout<<endl;//print a new line

	//chece if the shapes are deleted automatically
	cout << "Point Reference Count: " << mpoint.use_count() << endl;
	cout << "Line Reference Count: " << mline.use_count() << endl;
	cout << "Circle Reference Count: " << mcircle.use_count() << endl;
	
	//as is shown on screen, the shapes are deleted autometically.
	//this is true even if the "delete [] data;" in Array<T> destructor is put into comment
}