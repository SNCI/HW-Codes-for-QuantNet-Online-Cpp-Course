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
			//static member
			static int df_size;
			
			//constructors and destructor
			Array();//default constructor
			Array(int s);//constructor with size
			Array(const Array<T>& a);//copy constructor
			virtual ~Array();//destructor

			//operators
			Array<T>& operator = (const Array<T>& source);
			T& operator [](int index);
			const T& operator [](int index) const;

			//Getters
			int Size() const;
			T& GetElement(int i) const;
			static int DefaultSize();

			//Setter
			void SetElement(int& i, T& t);
			static void DefaultSize(int ds);
		};
	}
}
#ifndef ARRAY_CPP
#define ARRAY_CPP
#include "Array.cpp"
#endif
#endif
