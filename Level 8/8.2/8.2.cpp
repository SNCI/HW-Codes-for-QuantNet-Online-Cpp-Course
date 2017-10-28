//this is a programme for practicing using boost::tuple.
#include <iostream>
#include <string>
#include <boost/tuple/tuple.hpp>	// Tuple class
#include <boost/tuple/tuple_io.hpp> // I/O for tuples
using namespace std;

typedef boost::tuple<string, int, double> Person;//typedef for a Person tuple

void PrintPerson(const Person& source);//declare the function to print a Person tuple

void main()
{
	//create some person tuple instance
	Person A(string("Arthur"),23,179.5);
	Person B=boost::make_tuple(string("Alfred"),19,185.1);
	Person C(string("Gilbert"),23,180.0);
	Person D=boost::make_tuple(string("Francis"),30,186.0);

	//print them
	PrintPerson(A);
	PrintPerson(B);
	PrintPerson(C);
	PrintPerson(D);

	//increment the age of one person
	D.get<1>()+=1;
	cout<<"After change: ";
	PrintPerson(D);//show the result of modification
}

void PrintPerson(const Person& source)// function body
{
	//print the records in tuple on screen
	cout<<"Name: "<<source.get<0>()<<", Age: "<<source.get<1>()<<", Length: "<<source.get<2>()<<"."<<endl;
	cout<<endl;//print a new line
}