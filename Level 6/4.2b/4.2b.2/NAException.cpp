//NAException.cpp
//derived class for class ArrayException, especially developed to handle Numeric Array problem
//10-15-2016 AM
#ifndef EXHANDLE
#define EXHANDLE
#include "ExHandle.h"
#endif
//constructor and destructor
NAException::NAException():ArrayException(){}//default constructor
NAException::~NAException(){}//destructor

//message
std::string NAException::GetMessage()//overriden GetMessage() function
{
	std::stringstream source;
	source<<"Two arrays are of different size!";
	return source.str();//return the string
}