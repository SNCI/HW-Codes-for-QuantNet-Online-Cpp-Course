#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
#ifndef POINT_H
#define POINT_H
#include "Point.h"
#endif
using namespace std;

//This is a test programme for free store
void main()
{
	//Get coordinates from user
	double x1,y1;
	cout<<"Please input two coordinates: "<<endl;
	cout<<"x: "; cin>>x1;
	cout<<"y: "; cin>>y1;
	cout<<endl;//print a new line

	//Initiate point pointers as asked in the prompt
	Point* pp1=new Point;// create with default constructor
	Point* pp2=new Point(x1,y1);
	Point* pp3=new Point(*pp2);// create with copy constructor

	//See descriptions
	cout<<(*pp1)<<endl;
	cout<<(*pp2)<<endl;
	cout<<(*pp3)<<endl;
	cout<<endl;//print a new line

	//Calculate distance
	cout<<"The distance between "<<(*pp1)<<" and "<<(*pp2)<<" is "<<(*pp1).Distance(*pp2)<<endl;
	cout<<"The distance between "<<(*pp2)<<" and "<<(*pp3)<<" is "<<(*pp2).Distance(*pp3)<<endl;
	cout<<endl;

	// free the memories allocated to Points.
	delete pp1; pp1=NULL;
	delete pp2; pp2=NULL;
	delete pp3; pp3=NULL;

	//Get the size of the array
	int size;
	cout<<"An array of Points will be created."<<endl;
	cout<<"Please assign the size of the array: "; cin>>size;

	//Initiate the array as asked in prompt
	/*Point arr_point[size];*/
	//results in error C2057(expected constant experession),
	//C2466(cannot allocate an array of constant size 0),
	//and C2133('arr_point':unknown size)

	//Create an array on the heap
	Point* arr_point=new Point[size];
	
	/*Point* arr_point1=new Point[size](x1,y1);*/
	//result in error C2075:'Target of operator new()':array initializtion ness curly braces
	
	/*Point* arr_point2=new Point[size](*arr_point);*/
	//result in error C2075 again

	//Display the array
	cout<<"The entries of the array are as follows:"<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<arr_point[i]<<endl;
	}
	cout<<endl;

	delete [] arr_point; arr_point=NULL;//free the memories
	cout<<"End of Test"<<endl;
}
ostream& operator << (ostream& os, const Point& p)
{
	os<<"Point("<<p.x<<","<<p.y<<")";
	return os;
}