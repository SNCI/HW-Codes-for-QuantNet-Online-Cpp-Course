//Array.h
#ifndef SSTREAM
#define SSTREAM
#include <sstream>
#endif
#ifndef POINT_H
#define POINT_H
#include "Point.h"
#endif
#ifndef CLUSTER_H
#define CLUSTER_H
#include "Cluster.h"
#endif
#ifndef CLASS_ARRAY
#define CLASS_ARRAY
class Containers::Array
{
private:
	CAD::Point* data;
	int size;
public:
	//constructors and destructor
	Array();//default constructor
	Array(int s);//constructor with size
	Array(const Array& a);//copy constructor
	~Array();//destructor

	//operators
	Array& operator = (const Array& source);
	CAD::Point& operator [](int index);
	const CAD::Point& operator [](int index) const;

	//Getters
	int Size();
	CAD::Point& GetElement(int i);

	//Setter
	void SetElement(int& i, CAD::Point& p);
};
#endif