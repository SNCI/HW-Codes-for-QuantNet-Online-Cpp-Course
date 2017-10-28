#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <functional>
#ifndef LESSTHANV_H
#define LESSTHANV_H
#include "LessThanV.h"
#endif
using namespace std;
//this is a programme for practicing using STL algorithms
double val=4.5;//declare a global value to act as a benchmark in global function LessThan()
bool LessThan(double num){return num<val;}//global function that compare double num with a certain number
void main()
{
	vector<double> dbv;//create a vector with double element
	dbv.reserve(10);//reserve 10 places
	
	//initialize the vector
	for(int i=0;i!=10;++i)
	{
		dbv.push_back(i+i/10);
	}
	
	//use count_if algorithm to count the element less than 4(pass the global function as functor)
	int NumLess=count_if(dbv.begin(),dbv.end(),LessThan);

	//check the result
	cout<<"Then number of elements in vector that is less than "<<val<<" is: "<<NumLess<<"."<<endl;
	cout<<endl;//print a new line

	//try LessThanV object
	LessThanV ltv(6);//create a LessThanV object with bencnmark of 6
	int Less1=count_if(dbv.begin(),dbv.end(),ltv);//call count_if to count the number of elements less than 6
	cout<<"Then number of elements in vector that is less than "<<ltv.GetV()<<" is: "<<Less1<<"."<<endl;//see result
	ltv.Benchmark(5.6);//modify the benchmark to 5.6
	int Less2=count_if(dbv.begin(),dbv.end(),ltv);//call count_if to count the number of elements less than 5.6
	cout<<"Then number of elements in vector that is less than "<<ltv.GetV()<<" is: "<<Less2<<"."<<endl;//see result
}