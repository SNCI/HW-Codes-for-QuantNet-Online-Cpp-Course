//OutOfBoundException.cpp
//derived class for class ArrayException, especially developed to handle index out of bound problem
//10-08-2016 PM
#ifndef EXHANDLE
#define EXHANDLE
#include "ExHandle.h"
#endif
//counstructor and destructor
OutOfBoundsException::OutOfBoundsException(int index):ArrayException(), index(index){}//default constructor with one parameter(using colon syntax)
OutOfBoundsException::~OutOfBoundsException(){}//destructor

//message
std::string OutOfBoundsException::GetMessage()
{
	std::stringstream source;
	source<<"Index "<<index<<" is out of bound!";
	return source.str();
}