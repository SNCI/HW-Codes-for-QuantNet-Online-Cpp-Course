//NumericArray.cpp
//Array with elements that can become operands of numeric calculations
//10-14-2016 PM
#ifndef NA_H
#define NA_H
#include "NumericArray.h"
#endif
namespace Cluster
{
	namespace Containers
	{
		//constructors and destructor
		template<typename T>
		NumericArray<T>::NumericArray():Array(){}//default construcor

		template<typename T>
		NumericArray<T>::NumericArray(int s):Array(s){}//constructor with size parameter

		template<typename T>
		NumericArray<T>::NumericArray(const NumericArray<T>& n_arr):Array(n_arr){}//copy constructor

		template<typename T>
		NumericArray<T>::~NumericArray(){}//destructor

		//operators
		template<typename T>
		NumericArray<T>& NumericArray<T>::operator = (const NumericArray<T>& source)//assignment operator
		{
			if(&source!=this)//handle self assignment
			{
				Array<T>::operator=(source);//call base class assignment operator
				//no other data member need to be copied
			}
			return *this;
		}

		template<typename T>
		NumericArray<T> NumericArray<T>::operator * (double factor) const//scaling operator *
		{
			NumericArray<T> Scale(this->Size());
			for(int i=0;i!=(*this).Size();i++)//for every element
			{
				Scale[i]=factor*(*this)[i];//scale the element
			}
			return Scale;
		}

		template<typename T>
		NumericArray<T> NumericArray<T>::operator + (const NumericArray<T>& source) const//adding operator +, throw exception when two arrays are of different size
		{
			NumericArray<T> sumarr(this->Size());
			if ((*this).Size()==source.Size())//if the two array are of the same size
			{
				for(int i=0;i!=(*this).Size();i++)//for every index
				{
					sumarr[i]=(*this)[i]+source[i];//add corresponding element
				}
				return sumarr;
			}
			else//if the two array are of different size
			{
				throw NAException();//throw an error message
			}
		}

		template<typename T>
		double NumericArray<T>::DotProduct(const NumericArray<T>& source)//dot product
		{
			if (this->Size()==source.Size())//if the two array are of the same size
			{
				double sum=0;
				for(int i=0;i!=(*this).Size();i++)//for every index
				{
					sum=sum+(*this)[i]*source[i];//multiplay corresponding elements and add the result to the sum
				}
				return sum;
			}
			else//if the two array are of different size
			{
				throw NAException();//throw an error message
			}
		}
	}
}