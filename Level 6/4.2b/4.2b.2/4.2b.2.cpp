#ifndef ARRAY_CPP
#define ARRAY_CPP
#include "Array.cpp"
#endif
#ifndef NA_CPP
#define NA_CPP
#include "NumericArray.cpp"
#endif
using namespace std;
using namespace Cluster::Containers;
//this is a test programme for generic inheritance
//NumericArray is designed for array of classes in which operator +, *(product(for two objects) sign, not scaling sign) are defined.
//Cannot apply to Point class(* not defined in Point). But with element-wise(or modulus-wise) * defined in class Point, this can apply to Point
//for vector(array of double/int/float,etc.) and matrix, although * can be defined, the meaning of dot product is unclear
//Generally numeric array should be used for double/int/float,etc. type and act like a vector.
void main()
{
	int size;
	cout<<"Please input a size parameter: ";cin>>size;//get size parameter from the user

	NumericArray<int> intarr(size);//create an array of int of size size
	NumericArray<double> dbarr(size);//create an array of double of size size
	NumericArray<double> dfdbarr;//create an array of double with default constructor

	//initialize and display the arrays
	for(int i=0;i!=size;i++)
	{
		intarr[i]=i+1;//initialize the member of intarr
		cout<<"Element "<<i+1<<" of intarr is: "<<intarr[i]<<endl;//and display it on screen
	}
	cout<<endl;//print a new line

	for(int i=0;i!=size;i++)
	{
		dbarr[i]=i+0.5;//initialize the member of dbarr
		cout<<"Element "<<i+1<<" of dbarr is: "<<dbarr[i]<<endl;//and display it on screen
	}
	cout<<endl;//print a new line

	for(int i=0;i!=dfdbarr.DefaultSize();i++)
	{
		dfdbarr[i]=i+0.3;//initialize the member of intarr
		cout<<"Element "<<i+1<<" of dfdbarr is: "<<dfdbarr[i]<<endl;//and display it on screen
	}
	cout<<endl;//print a new line

	cout<<"Test for copy constructor."<<endl;
	NumericArray<double> copydbarr(dbarr);//create a numeric array with copy constructor
	for(int i=0;i!=copydbarr.Size();i++)
	{
		cout<<"Original element: "<<dbarr[i]<<" Copy: "<<copydbarr[i]<<endl;//display and compare with the original array
	}
	cout<<endl;//print a new line

	NumericArray<double> result=dbarr*2;//test operator *
	cout<<"test for operator *"<<endl;
	for(int i=0;i!=dbarr.Size();i++)
	{
		cout<<"Original element: "<<dbarr[i]<<", after *2= "<<result[i]<<endl;//display and compare with the original array
	}
	cout<<endl;//print a new line

	try
	{
		cout<<"test for operator +"<<endl;
		dbarr=copydbarr+copydbarr;//test for operator +
		for(int i=0;i!=dbarr.Size();i++)//display the result
		{
			cout<<copydbarr[i]<<" + "<<copydbarr[i]<<" = "<<dbarr[i]<<endl;
		}
		cout<<endl;//print a new line

		cout<<"test for DotProduct()"<<endl;
		double sum1,sum2;
		sum1=intarr.DotProduct(intarr);//test for DotProduct()
		cout<<"intarr.DotProduct(intarr)="<<sum1<<endl;
		sum2=copydbarr.DotProduct(copydbarr);//test for different type
		cout<<"copydbarr.DotProduct(copydbarr)="<<sum2<<endl;
		cout<<endl;//print a new line

		cout<<"test exception handling"<<endl;
		dbarr=copydbarr+dfdbarr;//add two arrays of different size
		double sum3;
		sum3=copydbarr.DotProduct(dfdbarr);//dot prodoct arrays of different size
	}
	catch(NAException& err)//catch the exception message thrown
	{
		cout<<err.GetMessage()<<endl;
	}
	catch(...)//handle unknown error
	{
		cout<<"Unknown error!"<<endl;
	}
}