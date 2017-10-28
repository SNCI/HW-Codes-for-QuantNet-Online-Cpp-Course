//Array.h
#ifndef SSTREAM
#define SSTREAM
#include <sstream>
#endif
#ifndef EXHANDLE
#define EXHANDLE
#include "ExHandle.h"
#endif
#ifndef CLASS_ARRAY
#define CLASS_ARRAY
namespace Cluster
{
	namespace Containers
	{
		template<typename T>
		class Array
		{
		private:
			T* data;
			int size;
		public:
			//constructors and destructor
			Array();//default constructor
			Array(int s);//constructor with size
			Array(const Array<T>& a);//copy constructor
			~Array();//destructor

			//operators
			Array<T>& operator = (const Array<T>& source);
			T& operator [](int index);
			const T& operator [](int index) const;

			//Getters
			int Size() const;
			T& GetElement(int i) const;

			//Setter
			void SetElement(int& i, T& t);
		};
	}
}
#ifndef ARRAY_CPP
#define ARRAY_CPP
#include "Array.cpp"
#endif
#endif
