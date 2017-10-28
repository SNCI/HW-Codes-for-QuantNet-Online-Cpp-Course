//	PerpAmeOption.cpp
//
//	A class of perpetual American options
//
//	11-08-2016 PM

#include "PerpAmeOption.h"

//private functions
double PerpAmeOption::CallPrice(const double& S)
{
	//	declare necessary parameters
	double price, para1, para2,fac;		//	price, intermediate variables

	//	calculate parameters
	para1=0.5-(b/(sig*sig));
	para2=sqrt((-para1)*(-para1)+((2*r)/(sig*sig)));

	double y1=para1+para2;
	if (y1==1)	//	special case: y1=1
	{
		return S;
	}
	else
	{
		fac=((y1-1)/y1)*(S/K);
		price=(K/(y1-1))*pow(fac,y1);
		return price;
	}
}
double PerpAmeOption::PutPrice(const double& S)
{
	//	declare necessary parameters
	double price, para1, para2,fac;		//	price, intermediate variables

	//	calculate parameters
	para1=0.5-(b/(sig*sig));
	para2=sqrt((-para1)*(-para1)+((2*r)/(sig*sig)));

	double y2=para1-para2;
	if (y2==1)	//	special case: y2=1
	{
		return S;
	}
	else
	{
		fac=((y2-1)/y2)*(S/K);
		price=(K/(1-y2))*pow(fac,y2);
		return price;
	}
}

//	constructors and destructor
PerpAmeOption::PerpAmeOption():b(0),K(0),r(0),sig(0),type('C'){}	//	default constructor
PerpAmeOption::PerpAmeOption(double& b1, double& K1, double& r1, double& sig1, char& type1):b(b1),K(K1),r(r1),sig(sig1),type(type1){}		//	constructor with parameters
PerpAmeOption::PerpAmeOption(const PerpAmeOption& source):b(source.b),K(source.K),r(source.r),sig(source.sig),type(source.type){}			//	copy constructor
PerpAmeOption::~PerpAmeOption(){}									//	destructor

//	price function
double PerpAmeOption::Price(const double& S)
{
	if (type==67)	//	perpetual call
	{
		return CallPrice(S);
	}
	else            //	perpetual put
	{
		return PutPrice(S);
	}
}

//	modifiers
void PerpAmeOption::Type(const char& Type)				//	modify type
{
	type=Type;
}

//	getters
char PerpAmeOption::Type()				//	see type
{
	return type;
}

//	operator
PerpAmeOption& PerpAmeOption::operator = (const PerpAmeOption& source)		//	assignment operator
{
	if (&source!=this)	//	handle self-assignment
	{
		//	assign corresponding data members
		b=source.b;
		K=source.K;
		r=source.r;
		sig=source.sig;
		type=source.type;
	}
	return *this;
}