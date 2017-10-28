#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
#ifndef CLASS_LESSTHANV
#define CLASS_LESSTHANV
class LessThanV
{
private:
	double value;
public:
	//constructor and destructor
	LessThanV();//default constructor
	LessThanV(double v);//constructor with value parameter
	LessThanV(const LessThanV& f);//copy constructor
	~LessThanV();//destructor

	//operators
	LessThanV& operator = (const LessThanV& f);//assignment operator
	bool operator () (double num);//overloaded operator ()

	//Setter
	void Benchmark(double b);//set private data number value

	//Getter
	double GetV();//get private member value
};
#endif