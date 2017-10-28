#ifndef ARRAY_CPP
#define ARRAY_CPP
#include "Array.cpp"
#endif
#ifndef POINT_H
#define POINT_H
#include "Point.h"
#endif
#ifndef CLASS_POINTARRAY
#define CLASS_POINTARRAY
namespace Cluster
{
	namespace Containers
	{
		class PointArray:public Array<CAD::Point>
		{
		public:
			//constructors and destructor
			PointArray();//default constructor
			PointArray(int s);//constructor with size parameter
			PointArray(const PointArray& source);//copy constructor
			virtual ~PointArray();//destructor

			//function
			double Length();//calculate the total length between elements
		};
	}
}
#endif