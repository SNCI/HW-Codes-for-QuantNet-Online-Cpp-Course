//PointArray.cpp
//class of array of point, concretely inherited from class Array
//10-15-2016 PM
#ifndef POINTARRAY_H
#define POINTARRAY_H
#include "PointArray.h"
#endif
namespace Cluster
{
	namespace Containers
	{
		//constructors and destructor
		PointArray::PointArray():Array(){}//default constructor
		PointArray::PointArray(int s):Array(s){}//constructor with size parameter
		PointArray::PointArray(const PointArray& source):Array(source){}//copy constructor
		PointArray::~PointArray(){}//destructor

			//function
		double PointArray::Length()//calculate the total length between elements
		{
			double sum=0;
			for(int i=0;i!=(this->Size()-1);i++)
			{
				sum=sum+(*this)[i].Distance((*this)[i+1]);
			}
			return sum;
		}
	}
}