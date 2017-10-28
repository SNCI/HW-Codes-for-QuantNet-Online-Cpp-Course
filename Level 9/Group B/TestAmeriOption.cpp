//	This is the source file for testing perpetual American option pricing model
//
//	This file contains main programme and global functions(declaration as well as function body)
//	
//	For pricing model formulae and other class member functions
//
//	See "PerpAmeOption.h"

//	included file
#include "PerpAmeOption.h"
#ifndef VECTOR
#define VECTOR
#include <vector>
#endif
using namespace std;

//	global function declaration
vector<double> CutVec(const double& start, const double& h, const int& size);


//	main programme
void main()
{
	//	required data set
	double K=100;
	double sig=0.1;
	double r=0.1;
	double b=0.02;
	double S=110;
	char type1='C'; char type2='P';

	//	Create objects of class PerpAmeOption with given data and type parameters
	PerpAmeOption AmeCall(b,K,r,sig,type1);
	PerpAmeOption AmePut(b,K,r,sig,type2);

	//	See results
	cout<<"Call Price: "<<AmeCall.Price(S)<<", Put Price: "<<AmePut.Price(S)<<endl;		//	result: call:18.5035, put: 3.03106
	cout<<endl;

	//	container of conditions
	vector<double> StockP=CutVec(10,1,50);	//	call CutVec()
	
	//	get parameters from the user
	cout << "K: "; cin >> K;
	cout << "sig: "; cin >> sig;
	cout << "r: "; cin >> r;
	cout << "b: "; cin >> b;

	//	container of results
	vector<double> Output1;
	Output1.reserve(50);						//	reserve places for outputs
	vector<double> Output2;
	Output2.reserve(50);						//	reserve places for outputs

	//	calculate and print the results
	for (int i=0;i!=50;i++)
	{
		//	calculate and store the results
		Output1.push_back(AmeCall.Price(StockP[i]));
		Output2.push_back(AmePut.Price(StockP[i]));

		//	print the results
		cout<<"Stock Price: "<<StockP[i]<<", Call Price: "<<Output1[i]<<", Put Price: "<<Output2[i]<<endl;
	}
	cout<<endl;
}

//	global function body
vector<double> CutVec(const double& start, const double& h, const int& size)
{
	vector<double> Proto;				//	declare the vector to be returned
	Proto.reserve(size);				//	reserve places for elements
	for (int i=0;i!=size;i++)			//	initialize elements according to requirement
	{
		Proto.push_back(start+h*i);
	}
	return Proto;
}