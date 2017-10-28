//	OptionElements.h
//
//	This file contains the batches, struct and global function declarations required in the prompt
//
//	Namespaces are used to contain batches for programming convenience
//
//	11-07-2016 PM

#ifndef OPTIONELE_H
#define OPTIONELE_H
#ifndef CMATH
#define CMATH
#include <cmath>
#endif
#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
#ifndef VECTOR
#define VECTOR
#include <vector>
#endif
#ifndef BOOSTMATHDIS
#define BOOSTMATHDIS
#include <boost/math/distributions/normal.hpp>
#endif
using namespace std;							//	For readability
using namespace boost::math;					//	For readability

//	namespaces and structs
namespace Batch1
{double T = 0.25; double K = 65; double sig = 0.30; double r = 0.08; double S = 60;};
namespace Batch2
{double T = 1.0; double K = 100; double sig = 0.2; double r = 0.0; double S = 100;};
namespace Batch3
{double T = 1.0; double K = 10; double sig = 0.50; double r = 0.12; double S = 5;};
namespace Batch4
{double T = 30.0; double K = 100.0; double sig = 0.30; double r = 0.08; double S = 100.0;};

struct OptionData
{
	double K;		//	strike price
	double T;		//	time to maturity
	double r;		//	risk-free interest rate
	double sig;		//	stock price volatility
};

//	global functions declarations
//	option-pricing
//double BSCallPrice(const double& S, const double& K, const double& T, const double&r, const double& sig);	//	Call-option price
double BSCallPrice(const OptionData& OptD, const double& S);												//	with struct as input
//double BSPutPrice(const double& S, const double& K, const double& T, const double&r, const double& sig);	//	Put-option price
double BSPutPrice(const OptionData& OptD, const double& S);													//	with struct as input
//void PCParity(const double& S, const double& K, const double& T, const double&r,const double& price, const char& type);	//	Put-Call Parity
double PCParity(const OptionData& OptD, const double& S, const double& price, const char& type);		    //	with struct as input

//	deltas
//double DeltaC(const double& S, const double& K, const double& T, const double&r, const double& sig, const double& b);		//	derivative of price in respect of S
//double Gamma(const double& S, const double& K, const double& T, const double&r, const double& sig, const double& b);		//	second derivative of price in respect of S 
//double DeltaP(const double& S, const double& K, const double& T, const double&r, const double& sig, const double& b);		//	derivative of price in respect of S

//	container modifying
vector<double> CutVec(const double& start, const double& h, const int& size);									//	produces a mesh array of doubles separated by a mesh size h

#endif