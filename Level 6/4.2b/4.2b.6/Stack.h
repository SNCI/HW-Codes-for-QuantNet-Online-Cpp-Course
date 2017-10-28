#ifndef ARRAY_CPP
#define ARRAY_CPP
#include "Array.cpp"
#endif
#ifndef CLASS_STACK
#define CLASS_STACK
namespace Cluster
{
	namespace Containers
	{
		template<typename T, int size>
		class Stack
		{
		private:
			Array<T> arr;//use class array as a data member
			int current;//current index
		public:
			//constructors and destructor
			Stack();//default constructor
			Stack(const Stack<T,size>& source);//copy constructor
			~Stack();//destructor

			//operator
			Stack<T,size>& operator = (const Stack<T,size>& source);//assignment operator

			//getter(create for debugging)
			int GetCurrent() const;
			T GetEle() const;
			
			//functions
			void Push(T CurrentEle);//store current object and push one place forward
			T Pop();//push one place backward and return object at that place
		};
	}
}
#endif