//Array.h
#ifndef SSTREAM
#define SSTREAM
#include <sstream>
#endif
#ifndef POINT_H
#define POINT_H
#include "Point.h"
#endif
#ifndef CLASS_ARRAY
#define CLASS_ARRAY
class Array
{
private:
	Point* data;
	int size;
public:
	//constructors and destructor
	Array();//default constructor
	Array(int s);//constructor with size
	Array(const Array& a);//copy constructor
	~Array();//destructor

	//operators
	Array& operator = (const Array& source);
	Point& operator [](int index);
	const Point& operator [](int index) const;

	//Getters
	int Size();
	Point& GetElement(int i);

	//Setter
	void SetElement(int& i, Point& p);
};
#endif