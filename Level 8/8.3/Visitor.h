//Visitor.h
#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
#ifndef SSTREAM
#define SSTREAM
#include <sstream>
#endif
#ifndef BOOST_VARIANT
#define BOOST_VARIANT
#include <boost/variant.hpp>
#endif
#ifndef CIRCLE_H
#define CIRCLE_H
#include "Circle.h"
#endif



#ifndef CLASS_VISITOR
#define CLASS_VISITOR
namespace Cluster
{
	namespace CAD
	{
		class Visitor: public boost::static_visitor<void>
		{
		private:
			//the benchmark for furthur modification
			double x_offset;
			double y_offset;
		public:
			//constructors and distructor
			Visitor();//default constructor
			Visitor(double x, double y);//constructor with parameters
			Visitor(const Visitor& source);//copy constructor
			virtual ~Visitor();//destructor

			//getters
			double XO();//get x_offset
			double YO();//get y_offset

			//modifiers
			void XO(double x);//modify x_offset
			void YO(double y);//modify y_offset

			//operators
			Visitor& operator = (const Visitor& source);//assignment operator
			void operator () (Point& p) const;//() for Point
			void operator () (Line& l) const;//() for Line
			void operator () (Circle& O) const;//() for Circle
		};
	}
}
#endif