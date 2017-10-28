#ifndef LESSTHANV_H
#define LESSTHANV_H
#include "LessThanV.h"
#endif
//constructor and destructor
LessThanV::LessThanV():value(4.5){}//default constructor
LessThanV::LessThanV(double v):value(v){}//constructor with value parameter
LessThanV::LessThanV(const LessThanV& f):value(f.value){}//copy constructor
LessThanV::~LessThanV(){}//destructor

//operators
LessThanV& LessThanV::operator = (const LessThanV& f)//assignment operator
{
	if(this!=&f)
	{
		value=f.value;
	}
	return *this;
}
bool LessThanV::operator () (double num)//overloaded operator ()
{
	return num<value;
}

//Setter
void LessThanV::Benchmark(double b)//set private data number value
{
	value=b;
}

//Getter
double LessThanV::GetV()//get private member value
{
	return value;
}